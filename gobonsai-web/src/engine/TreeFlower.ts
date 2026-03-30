import * as THREE from 'three';
import { MSVCRand } from './MSVCRand';
import { TREE_CONSTANTS } from './TreeConstants';

export class TreeFlower {
    public group: THREE.Group = new THREE.Group();
    public petals: THREE.Mesh[] = [];
    public size: number = 0.0;
    public targetSize: number = 0.15; // Оригинальный размер
    public isBloomed: boolean = false;
    private bloomProgress: number = 0;
    private isFalling: boolean = false;
    private fallVelocities: THREE.Vector3[] = [];
    private fallRotations: THREE.Vector3[] = [];
    private rng: MSVCRand;

    constructor(parentGroup: THREE.Group, rng: MSVCRand) {
        this.rng = rng;
        
        const coreGeo = new THREE.SphereGeometry(0.02, 8, 8); // Оригинальное ядро
        const coreMat = new THREE.MeshStandardMaterial({ color: 0xffeb3b, roughness: 0.8 });
        const core = new THREE.Mesh(coreGeo, coreMat);
        this.group.add(core);

        const petalGeo = new THREE.CapsuleGeometry(0.02, 0.08, 4, 8); // Оригинальные лепестки
        const petalMat = new THREE.MeshStandardMaterial({ 
            color: 0xffc0cb, 
            roughness: 0.5,
            transparent: true,
            opacity: 0
        });

        for (let i = 0; i < 5; i++) {
            const petal = new THREE.Mesh(petalGeo, petalMat.clone());
            const angle = (i / 5) * Math.PI * 2;
            petal.rotation.z = angle;
            petal.position.set(Math.cos(angle) * 0.05, Math.sin(angle) * 0.05, 0);
            petal.rotation.x = Math.PI / 4;
            this.petals.push(petal);
            this.group.add(petal);
        }

        this.group.position.set(
            (this.rng.randFloat() - 0.5) * 0.3,
            this.rng.randFloat() * 0.8 + 0.1,
            (this.rng.randFloat() - 0.5) * 0.3
        );
        this.group.rotation.set(this.rng.randFloat() * Math.PI, this.rng.randFloat() * Math.PI, 0);
        this.group.scale.set(0, 0, 0);
        
        parentGroup.add(this.group);
    }

    public update(dayOfYear: number, globalHealth: number, deltaTime: number): void {
        const { METABOLISM } = TREE_CONSTANTS;
        
        // Цветение происходит весной (день 60-150)
        const isSpring = dayOfYear >= 60 && dayOfYear < 150;
        const isEndSeason = dayOfYear >= 150 && dayOfYear < 180; 
        
        if (isSpring && globalHealth > METABOLISM.LIGHT_THRESHOLD) {
            this.bloomProgress = Math.min(1.0, this.bloomProgress + deltaTime * 0.1);
        } else if (!isEndSeason) {
            this.bloomProgress = Math.max(0.0, this.bloomProgress - deltaTime * 0.2);
        }

        if (isEndSeason && this.bloomProgress > 0.5 && !this.isFalling) {
            this.startFalling();
        }

        if (this.isFalling) {
            this.updateFalling(deltaTime);
            return;
        }

        this.size = this.targetSize * this.bloomProgress;
        this.group.scale.set(this.size, this.size, this.size);
        this.group.visible = this.size > 0.01;

        this.petals.forEach((petal) => {
            const mat = petal.material as THREE.MeshStandardMaterial;
            mat.opacity = this.bloomProgress;
            petal.rotation.x = (Math.PI / 2) * (1 - this.bloomProgress) + (Math.PI / 4);
        });
    }

    private startFalling(): void {
        if (this.isFalling) return;
        this.isFalling = true;
        this.petals.forEach(() => {
            this.fallVelocities.push(new THREE.Vector3(
                (this.rng.randFloat() - 0.5) * 0.02,
                -0.01 - this.rng.randFloat() * 0.02,
                (this.rng.randFloat() - 0.5) * 0.02
            ));
            this.fallRotations.push(new THREE.Vector3(
                this.rng.randFloat() * 0.1,
                this.rng.randFloat() * 0.1,
                this.rng.randFloat() * 0.1
            ));
        });
    }

    private updateFalling(deltaTime: number): void {
        let allHidden = true;
        const step = deltaTime * 60;
        
        this.petals.forEach((petal, i) => {
            const vel = this.fallVelocities[i];
            const rot = this.fallRotations[i];
            
            petal.position.add(vel.clone().multiplyScalar(step));
            petal.rotation.x += rot.x * step;
            petal.rotation.y += rot.y * step;
            
            vel.y -= 0.001 * step; 

            const mat = petal.material as THREE.MeshStandardMaterial;
            mat.opacity -= 0.01 * step;
            if (mat.opacity > 0) allHidden = false;
        });

        if (allHidden) {
            this.group.visible = false;
            this.bloomProgress = 0;
        }
    }
}
