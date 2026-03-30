import * as THREE from 'three';
import { TreeLeaf } from './TreeLeaf';
import { TreeFlower } from './TreeFlower';
import { MSVCRand } from './MSVCRand';
import { TREE_CONSTANTS } from './TreeConstants';
import { GeometryService } from './GeometryService';
import { TreeTrunkParams } from './TreeState';

export class TreeSection {
    public parent: TreeSection | null;
    public level: number;
    public children: TreeSection[] = [];
    public leaves: TreeLeaf[] = [];
    public flowers: TreeFlower[] = [];
    
    public currentBranchScale: number = 0.0;
    public branchPosition: number = 1.0; 
    public branchBaseRadius: number; 
    public branchTipRadius: number;
    
    public rotation: THREE.Quaternion = new THREE.Quaternion();
    public targetRotation: THREE.Quaternion = new THREE.Quaternion();
    private currentEuler: THREE.Euler = new THREE.Euler();
    private targetEuler: THREE.Euler = new THREE.Euler();
    public sway: THREE.Vector3 = new THREE.Vector3(0, 0, 0);
    
    public hasWire: boolean = false;
    public isPruned: boolean = false;
    
    public group: THREE.Group = new THREE.Group();
    public mesh: THREE.Group; 
    
    private wireMesh: THREE.Group | null = null;
    private cutCap: THREE.Mesh | null = null;
    private rng: MSVCRand;

    constructor(parent: TreeSection | null = null, level: number = 0, rng: MSVCRand, overrideBaseRadius?: number) {
        this.parent = parent;
        this.level = level;
        this.rng = rng;
        
        const { GEOMETRY } = TREE_CONSTANTS;
        
        this.group.userData = { isTreeSection: true, level, controller: this };
        
        // sub_4093B0.c / sub_408880.c: Начальные углы
        const rotX = (this.rng.randFloat() - 0.5) * 1.5;
        const rotY = (this.rng.randFloat() - 0.5) * 0.6;
        const rotZ = (this.rng.randFloat() - 0.5) * 1.5;
        
        this.targetEuler.set(rotX, rotY, rotZ);
        this.targetRotation.setFromEuler(this.targetEuler);
        this.rotation.copy(this.targetRotation);
        
        this.mesh = new THREE.Group();
        this.group.add(this.mesh);
        
        // Радиус и сужение (sub_4093B0.c)
        this.branchBaseRadius = overrideBaseRadius ?? (GEOMETRY.BASE_RADIUS_FACTOR * Math.pow(GEOMETRY.RADIUS_DECAY, level)); 
        this.branchTipRadius = this.branchBaseRadius * (level === 0 ? GEOMETRY.TAPER_ROOT : GEOMETRY.TAPER_BRANCH); 

        // HEIGHT_FACTOR
        const sectionHeight = GEOMETRY.HEIGHT_FACTOR; 
        const heightPerSegment = sectionHeight / GEOMETRY.SEGMENTS_PER_SECTION;
        
        for (let i = 0; i < GEOMETRY.SEGMENTS_PER_SECTION; i++) {
            const tBottom = i / GEOMETRY.SEGMENTS_PER_SECTION;
            const tTop = (i + 1) / GEOMETRY.SEGMENTS_PER_SECTION;
            
            const rBottom = this.getRadiusAt(tBottom);
            const rTop = this.getRadiusAt(tTop);
            
            const segmentMesh = GeometryService.createBranchSegment(rTop, rBottom, heightPerSegment, level, this.rng);
            segmentMesh.position.y = i * heightPerSegment;
            segmentMesh.userData = { isSegment: true, segmentIndex: i, parentSection: this };
            
            this.mesh.add(segmentMesh);
        }
        
        if (parent) parent.group.add(this.group);
        if (level > 0) this.initFoliage();
    }

    private initFoliage(): void {
        const leafCount = Math.floor(this.rng.randFloat() * 50) + 100; // Оригинальное количество
        for (let i = 0; i < leafCount; i++) {
            const leaf = new TreeLeaf(this.group, this.rng);
            leaf.targetSize = 0.25 + this.rng.randFloat() * 0.25; // Оригинальный размер
            leaf.mesh.position.y = this.rng.randFloat();
            leaf.mesh.position.x += (this.rng.randFloat() - 0.5) * 0.6;
            leaf.mesh.position.z += (this.rng.randFloat() - 0.5) * 0.6;
            this.leaves.push(leaf);
        }

        if (this.rng.randFloat() > 0.15) {
            const flowerCount = Math.floor(this.rng.randFloat() * 15) + 10;
            for (let i = 0; i < flowerCount; i++) {
                const flower = new TreeFlower(this.group, this.rng);
                flower.group.position.y = this.rng.randFloat();
                flower.group.position.x += (this.rng.randFloat() - 0.5) * 0.3;
                flower.group.position.z += (this.rng.randFloat() - 0.5) * 0.3;
                this.flowers.push(flower);
            }
        }
    }

    public getRadiusAt(t: number): number {
        // sub_4093B0.c:127 - Линейное затухание радиуса от основания к вершине
        // В оригинале затухание идет по всей длине структуры, здесь аппроксимируем для секции
        const baseRadius = this.branchBaseRadius;
        const tipRadius = this.branchTipRadius;
        return baseRadius * (1.0 - t) + tipRadius * t;
    }

    public update(ageFactor: number, lightIntensity: number, trunkParams: TreeTrunkParams, globalHealth: number, wind: THREE.Vector3, dayOfYear: number, deltaTime: number): void {
        const { ANIMATION } = TREE_CONSTANTS;
        
        this.mesh.children.forEach(child => {
            if (child instanceof THREE.Mesh && child.material instanceof THREE.MeshStandardMaterial) {
                if (child.material.userData.shader) {
                    child.material.userData.shader.uniforms.uTreeAgeFactor.value = ageFactor;
                }
            }
        });

        // sub_416510.c:273 - Quaternion Slerp
        // flt_4D63C0 - коэффициент интерполяции вращения (примерно 0.05)
        const slerpFactor = 1.0 - Math.pow(0.05, deltaTime * 60); 
        
        const levelBend = trunkParams.bend * (1.0 / (this.level * 0.5 + 1));
        const curvature = new THREE.Euler(
            Math.sin(this.level * 0.5) * levelBend * 0.02,
            0,
            Math.cos(this.level * 0.5) * levelBend * 0.02
        );

        // Комбинируем целевое вращение и изгиб
        const finalTargetRotation = this.targetRotation.clone();
        const tempEuler = new THREE.Euler().setFromQuaternion(finalTargetRotation);
        tempEuler.x += curvature.x;
        tempEuler.z += curvature.z;
        finalTargetRotation.setFromEuler(tempEuler);

        this.rotation.slerp(finalTargetRotation, slerpFactor);
        
        const stabilityFactor = Math.pow(4.0, 6 - this.level); 
        const swayFactor = (0.002 + (1.0 - globalHealth) * 0.005) * (wind.length() / stabilityFactor);
        const swayX = Math.sin(Date.now() * 0.0005 + this.level) * wind.x * swayFactor;
        const swayZ = Math.cos(Date.now() * 0.0006 + this.level) * wind.z * swayFactor;

        this.group.quaternion.copy(this.rotation);
        this.group.rotateX(swayX);
        this.group.rotateZ(swayZ);
        
        if (trunkParams.thickness > 0.01) {
            const thicknessFactor = trunkParams.thickness; 
            // Оригинальный множитель 0.03 уже заложен в BASE_RADIUS_FACTOR
            this.mesh.scale.set(thicknessFactor, 1.0, thicknessFactor);
            this.group.visible = true;
            
            if (this.wireMesh) this.wireMesh.scale.set(thicknessFactor, 1.0, thicknessFactor);
            
            // HEIGHT_FACTOR (sub_4093B0.c:92 и др.)
            const sectionHeight = TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR;
            this.children.forEach(child => {
                child.group.position.y = child.branchPosition * sectionHeight; 
            });
        } else {
            this.group.visible = false;
        }

        const mat = this.mesh.children[0] instanceof THREE.Mesh ? (this.mesh.children[0].material as THREE.MeshStandardMaterial) : null;
        if (mat) {
            mat.color.copy(trunkParams.color);
            mat.roughness = 0.7 + (1.0 - globalHealth) * 0.3;
        }

        this.children.forEach(child => child.update(ageFactor, lightIntensity, trunkParams, globalHealth, wind, dayOfYear, deltaTime));
        
        // Листва появляется при достаточной толщине (ориентировочно)
        const foliageVisible = trunkParams.thickness > 1.0;
        this.leaves.forEach(leaf => {
            leaf.mesh.visible = foliageVisible;
            if (foliageVisible) {
                // Листья на фиксированной высоте, так как ветка не растягивается
                leaf.update(lightIntensity, ageFactor, globalHealth, wind, dayOfYear, deltaTime);
            }
        });

        this.flowers.forEach(flower => {
            flower.group.visible = foliageVisible;
            if (foliageVisible) {
                flower.update(dayOfYear, globalHealth, deltaTime);
            }
        });
    }

    public serialize(): any {
        const targetEuler = new THREE.Euler().setFromQuaternion(this.targetRotation);
        const rotationEuler = new THREE.Euler().setFromQuaternion(this.rotation);
        return {
            level: this.level,
            branchPosition: this.branchPosition,
            branchBaseRadius: this.branchBaseRadius,
            branchTipRadius: this.branchTipRadius,
            targetRotation: { x: targetEuler.x, y: targetEuler.y, z: targetEuler.z },
            rotation: { x: rotationEuler.x, y: rotationEuler.y, z: rotationEuler.z },
            children: this.children.map(c => c.serialize()),
            leaves: this.leaves.map(l => ({ size: l.size, energy: l.energy })),
            flowers: this.flowers.map(f => ({ bloomProgress: f['bloomProgress'], isFalling: f['isFalling'] })),
            hasWire: this.hasWire,
            isPruned: this.isPruned
        };
    }

    public static deserialize(data: any, parent: TreeSection | null, rng: MSVCRand): TreeSection {
        const section = new TreeSection(parent, data.level, rng, data.branchBaseRadius);
        section.branchPosition = data.branchPosition ?? 1.0;
        if (data.branchTipRadius !== undefined) section.branchTipRadius = data.branchTipRadius;
        
        if (data.targetRotation) {
            const euler = new THREE.Euler(data.targetRotation.x, data.targetRotation.y, data.targetRotation.z);
            section.targetRotation.setFromEuler(euler);
        }
        
        if (data.rotation) {
            const euler = new THREE.Euler(data.rotation.x, data.rotation.y, data.rotation.z);
            section.rotation.setFromEuler(euler);
        }
        
        section.isPruned = data.isPruned ?? false;
        
        if (data.children) {
            section.children = data.children.map((c: any) => TreeSection.deserialize(c, section, rng));
        }
        
        if (data.leaves) {
            section.leaves = data.leaves.map((ld: any) => {
                const leaf = new TreeLeaf(section.group, rng);
                leaf.size = ld.size;
                leaf.energy = ld.energy;
                return leaf;
            });
        }

        if (data.flowers) {
            section.flowers = data.flowers.map((fd: any) => {
                const flower = new TreeFlower(section.group, rng);
                flower['bloomProgress'] = fd.bloomProgress ?? 0;
                flower['isFalling'] = fd.isFalling ?? false;
                return flower;
            });
        }

        if (data.hasWire) {
            section.hasWire = true;
            section.createWireVisuals();
        }
        
        return section;
    }

    public prune(target: THREE.Object3D): boolean {
        const index = this.children.findIndex(child => child.group === target);
        if (index !== -1) {
            this.group.remove(this.children[index].group);
            this.children.splice(index, 1);
            return true;
        }

        const segmentIndex = this.mesh.children.findIndex(child => child === target || (child instanceof THREE.Group && child.children.includes(target as any)));
        if (segmentIndex !== -1 && segmentIndex < this.mesh.children.length - 1) {
            const segmentsToRemove = this.mesh.children.splice(segmentIndex + 1);
            segmentsToRemove.forEach(s => this.mesh.remove(s));
            
            this.children.forEach(child => this.group.remove(child.group));
            this.children = [];
            
            const cutY = (segmentIndex + 1) / TREE_CONSTANTS.GEOMETRY.SEGMENTS_PER_SECTION; 
            this.leaves = this.leaves.filter(l => { if (l.mesh.position.y > cutY) this.group.remove(l.mesh); return l.mesh.position.y <= cutY; });
            this.flowers = this.flowers.filter(f => { if (f.group.position.y > cutY) this.group.remove(f.group); return f.group.position.y <= cutY; });

            this.isPruned = true;
            this.addCutVisual(segmentIndex);
            return true;
        }

        for (const child of this.children) if (child.prune(target)) return true;
        return false;
    }

    public applyWire(target: THREE.Object3D): boolean {
        if (this.group === target) {
            const euler = new THREE.Euler().setFromQuaternion(this.targetRotation);
            euler.x += (this.rng.randFloat() - 0.5) * 0.5;
            euler.z += (this.rng.randFloat() - 0.5) * 0.5;
            this.targetRotation.setFromEuler(euler);
            this.hasWire = true;
            this.createWireVisuals();
            return true;
        }
        for (const child of this.children) if (child.applyWire(target)) return true;
        return false;
    }

    private addCutVisual(segmentIndex: number): void {
        if (this.cutCap) this.mesh.remove(this.cutCap);
        const lastSegment = this.mesh.children[segmentIndex] as THREE.Mesh;
        if (!lastSegment || !lastSegment.geometry) return;

        const radius = (lastSegment.geometry as THREE.CylinderGeometry).parameters.radiusTop;
        this.cutCap = GeometryService.createCutCap(radius);
        this.cutCap.position.y = (segmentIndex + 1) / TREE_CONSTANTS.GEOMETRY.SEGMENTS_PER_SECTION;
        this.mesh.add(this.cutCap);
    }

    private createWireVisuals(): void {
        if (this.wireMesh) return;
        this.wireMesh = new THREE.Group();
        const wireMaterial = new THREE.MeshStandardMaterial({ color: 0x888888, metalness: 0.8, roughness: 0.2 });
        const segments = 10;
        const radius = this.branchBaseRadius + 0.01;
        for (let i = 0; i < segments; i++) {
            const wireGeo = new THREE.TorusGeometry(radius, 0.005, 8, 12, Math.PI);
            const wire = new THREE.Mesh(wireGeo, wireMaterial);
            wire.position.y = (i / segments) * TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR;
            wire.rotation.x = Math.PI / 2;
            wire.rotation.z = (i / segments) * Math.PI * 4;
            this.wireMesh.add(wire);
        }
        this.group.add(this.wireMesh);
    }

    public addBranch(atPosition: number = 1.0): TreeSection | null {
        if (this.level < TREE_CONSTANTS.GROWTH.MAX_LEVEL) {
            const child = new TreeSection(this, this.level + 1, this.rng, this.getRadiusAt(atPosition));
            child.branchPosition = atPosition;
            this.children.push(child);
            return child;
        }
        return null;
    }
}
