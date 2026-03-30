import * as THREE from 'three';
import { MSVCRand } from './MSVCRand';
import { TREE_CONSTANTS } from './TreeConstants';

export class TreeRoot {
    public level: number;
    public children: TreeRoot[] = [];
    public group: THREE.Group = new THREE.Group();
    public mesh: THREE.Group; 
    private rng: MSVCRand;
    private currentScale: number = 0.0;
    private targetRotation: THREE.Euler;

    constructor(parent: THREE.Object3D, level: number = 0, rng: MSVCRand) {
        this.level = level;
        this.rng = rng;
        
        const { ROOTS } = TREE_CONSTANTS;
        
        const pitch = level === 0 
            ? (Math.PI / 2) + (this.rng.randFloat() - 0.5) * 0.1 // Еще более горизонтально
            : (this.rng.randFloat() * 0.4 + 0.9); // Прижаты к земле

        this.targetRotation = new THREE.Euler(
            pitch, 
            (this.rng.randFloat() * Math.PI * 2), 
            0
        );

        const group = new THREE.Group();
        const segments = ROOTS.SEGMENTS; 
        const heightPerSegment = ROOTS.SEGMENT_HEIGHT;
        const baseRadius = ROOTS.BASE_RADIUS * Math.pow(ROOTS.RADIUS_DECAY, level); 

        for (let i = 0; i < segments; i++) {
            const factor = i / segments;
            const rBottom = baseRadius * Math.pow(1.0 - factor, 0.5);
            const rTop = baseRadius * Math.pow(1.0 - (i + 1) / segments, 0.5);
            
            // Оригинальное перекрытие сегментов для плотности (0.75)
            const geometry = new THREE.CylinderGeometry(rTop, rBottom, heightPerSegment, 8);
            geometry.translate(0, heightPerSegment / 2, 0);
            
            const material = new THREE.MeshStandardMaterial({ 
                color: 0x15100c, 
                roughness: 0.9,
                metalness: 0.0
            });

            const segmentMesh = new THREE.Mesh(geometry, material);
            segmentMesh.position.y = i * (heightPerSegment * 0.75); 
            
            const gnarl = level === 0 ? ROOTS.GNARL_LEVEL_0 : ROOTS.GNARL_LEVEL_N;
            segmentMesh.rotation.z = (this.rng.randFloat() - 0.5) * gnarl;
            segmentMesh.rotation.x = (this.rng.randFloat() - 0.5) * gnarl;
            
            segmentMesh.position.x = (this.rng.randFloat() - 0.5) * 0.15;
            segmentMesh.position.z = (this.rng.randFloat() - 0.5) * 0.15;

            segmentMesh.castShadow = true;
            segmentMesh.receiveShadow = true;
            group.add(segmentMesh);
        }

        this.mesh = group;
        this.group.add(this.mesh);
        parent.add(this.group);

        if (level < ROOTS.MAX_LEVEL && this.rng.randFloat() > 0.25) { 
            const childCount = Math.floor(this.rng.randFloat() * 2) + 1;
            for (let i = 0; i < childCount; i++) {
                const child = new TreeRoot(this.group, level + 1, this.rng);
                child.group.position.y = this.rng.randFloat() * heightPerSegment * segments * 0.8;
                this.children.push(child);
            }
        }
    }

    public update(ageFactor: number, deltaTime: number): void {
        const targetScale = Math.min(1.0, ageFactor * 8.0 - (this.level * 0.15));
        const lerpFactor = 1.0 - Math.pow(0.1, deltaTime);
        
        this.currentScale += (targetScale - this.currentScale) * lerpFactor;
        
        if (this.currentScale > 0.01) {
            this.group.scale.set(this.currentScale, this.currentScale, this.currentScale);
            this.group.rotation.copy(this.targetRotation);
            this.group.visible = true;
            
            this.children.forEach(child => {
                child.update(ageFactor, deltaTime);
            });
        } else {
            this.group.visible = false;
        }
    }

    public serialize(): any {
        return {
            level: this.level,
            currentScale: this.currentScale,
            targetRotation: { x: this.targetRotation.x, y: this.targetRotation.y, z: this.targetRotation.z },
            children: this.children.map(c => c.serialize())
        };
    }

    public static deserialize(parent: THREE.Object3D, data: any, rng: MSVCRand): TreeRoot {
        const root = new TreeRoot(parent, data.level, rng);
        root.currentScale = data.currentScale ?? 0;
        if (data.targetRotation) {
            root.targetRotation.set(data.targetRotation.x, data.targetRotation.y, data.targetRotation.z);
        }
        root.children = data.children.map((c: any) => TreeRoot.deserialize(root.group, c, rng));
        return root;
    }
}
