import * as THREE from 'three';
import { MSVCRand } from './MSVCRand';
import { TREE_CONSTANTS } from './TreeConstants';

export class TreeLeaf {
    public mesh: THREE.Mesh;
    public energy: number = 1.0; 
    public health: number = 1.0;
    public size: number = 0.0;
    public targetSize: number = 0.25; // Оригинальный размер
    private isDead: boolean = false;
    private isFalling: boolean = false;
    private fallTime: number = 0;
    private velocity: THREE.Vector3 = new THREE.Vector3();
    private rotationVelocity: THREE.Vector3 = new THREE.Vector3();
    private rng: MSVCRand;
    private swayOffset: number;

    constructor(parentGroup: THREE.Group, rng: MSVCRand) {
        this.rng = rng;
        this.swayOffset = this.rng.randFloat() * Math.PI * 2;
        
        const shape = new THREE.Shape();
        shape.moveTo(0, 0);
        shape.bezierCurveTo(0.04, 0.04, 0.04, 0.08, 0, 0.12);
        shape.bezierCurveTo(-0.04, 0.08, -0.04, 0.04, 0, 0);
        
        const geometry = new THREE.ShapeGeometry(shape);
        geometry.rotateX(-Math.PI / 4);
        
        const material = new THREE.MeshStandardMaterial({ 
            color: 0x2e7d32, 
            side: THREE.DoubleSide,
            transparent: true,
            opacity: 0,
            roughness: 0.3,
            emissive: 0x143306,
            emissiveIntensity: 0.5
        });
        
        material.onBeforeCompile = (shader) => {
            shader.fragmentShader = shader.fragmentShader.replace('#include <common>', '#include <common>\nvarying vec3 vLeafPos;');
            shader.vertexShader = shader.vertexShader.replace('#include <common>', '#include <common>\nvarying vec3 vLeafPos;').replace('#include <begin_vertex>', '#include <begin_vertex>\nvLeafPos = position;');
            shader.fragmentShader = shader.fragmentShader.replace('#include <dithering_fragment>', '#include <dithering_fragment>\nfloat vein = step(0.98, sin(vLeafPos.x * 100.0) * cos(vLeafPos.y * 10.0));\ngl_FragColor.rgb += vec3(vein * 0.1);');
        };

        this.mesh = new THREE.Mesh(geometry, material);
        this.mesh.castShadow = true;
        this.mesh.position.set((this.rng.randFloat() - 0.5) * 0.2, 0.5, (this.rng.randFloat() - 0.5) * 0.2);
        this.mesh.rotation.set(this.rng.randFloat() * Math.PI, this.rng.randFloat() * Math.PI, 0);
        this.mesh.scale.set(0, 0, 0);
        
        parentGroup.add(this.mesh);
    }

    update(
        lightIntensity: number,
        globalGrowthFactor: number,
        globalHealth: number,
        wind: THREE.Vector3,
        dayOfYear: number,
        deltaTime: number,
        strictExeSimVisuals: boolean = false,
    ): void {
        const { METABOLISM } = TREE_CONSTANTS;
        const leafMat = this.mesh.material as THREE.MeshStandardMaterial;

        if (this.isDead || this.isFalling) {
            this.velocity.y -= 0.1 * deltaTime;
            this.velocity.x += ((this.rng.randFloat() - 0.5) * 0.05 + wind.x * 0.05) * deltaTime; 
            this.velocity.z += ((this.rng.randFloat() - 0.5) * 0.05 + wind.z * 0.05) * deltaTime;
            
            this.mesh.position.add(this.velocity);
            this.mesh.rotation.x += this.rotationVelocity.x * deltaTime * 60;
            this.mesh.rotation.y += this.rotationVelocity.y * deltaTime * 60;

            const worldPos = new THREE.Vector3();
            this.mesh.getWorldPosition(worldPos);
            
            if (worldPos.y < 0) {
                this.velocity.set(0, 0, 0);
                this.rotationVelocity.set(0, 0, 0);
                leafMat.opacity -= 0.3 * deltaTime;
                if (leafMat.opacity <= 0) {
                    this.mesh.visible = false;
                    this.isDead = true;
                }
            } else {
                leafMat.opacity -= 0.05 * deltaTime;
            }
            return;
        }

        if (!strictExeSimVisuals) {
            const time = Date.now() * 0.002;
            this.mesh.rotation.z = Math.sin(time + this.swayOffset) * (wind.length() * 0.2 + 0.1);
            this.mesh.rotation.x = Math.cos(time * 0.8 + this.swayOffset) * (wind.length() * 0.1 + 0.05);
        }

        if (lightIntensity <= METABOLISM.LIGHT_THRESHOLD) {
            this.energy -= 0.0005 * deltaTime * 60; 
        } else {
            this.energy += 0.001 * lightIntensity * deltaTime * 60;
        }

        if (globalHealth < 0.3) this.energy -= 0.002 * deltaTime * 60;
        this.energy = Math.max(0, Math.min(1.0, this.energy));

        if ((this.energy <= 0 && this.rng.randFloat() < 0.01) || (globalHealth < 0.2 && this.rng.randFloat() < 0.005)) {
            this.startFalling();
        }

        if (this.energy > 0.4 && this.size < this.targetSize) {
            this.size += 0.1 * globalGrowthFactor * deltaTime;
        } 

        const s = Math.max(0, this.size);
        this.mesh.scale.set(s, s, s);
        
        const targetOpacity = this.energy * 0.8;
        const lerpFactor = 1.0 - Math.pow(0.1, deltaTime);
        leafMat.opacity += (targetOpacity - leafMat.opacity) * lerpFactor;
        
        let hue = 0.25 + this.energy * 0.1;
        let saturation = 0.6;
        let lightness = 0.2 + this.energy * 0.3;

        if (dayOfYear > 250 && dayOfYear < 320) {
            const autumnFactor = (dayOfYear - 250) / 70;
            hue = 0.25 - autumnFactor * 0.2;
            saturation += autumnFactor * 0.2;
        } else if (dayOfYear >= 320 || dayOfYear < 60) {
            saturation *= 0.5;
            lightness *= 0.8;
        }

        leafMat.color.setHSL(hue, saturation, lightness);
        leafMat.emissiveIntensity = this.energy * 0.5;
    }

    private startFalling(): void {
        if (this.isFalling) return;
        this.isFalling = true;
        this.velocity.set((this.rng.randFloat() - 0.5) * 0.02, 0, (this.rng.randFloat() - 0.5) * 0.02);
        this.rotationVelocity.set(this.rng.randFloat() * 0.1, this.rng.randFloat() * 0.1, this.rng.randFloat() * 0.05);
    }
}
