import * as THREE from 'three';
import { TreeSection } from './TreeSection';
import { TreeRoot } from './TreeRoot';
import { MSVCRand } from './MSVCRand';
import { GrowthController, GrowthStats } from './GrowthController';

export class BonsaiController {
    private scene: THREE.Scene;
    public rng: MSVCRand;
    private growthController: GrowthController;
    
    private stats: GrowthStats;
    public gameTime: number = 0;
    public root: TreeSection;
    public treeRoots: TreeRoot[] = [];
    
    public lightIntensity: number = 1.0;
    public wind: THREE.Vector3 = new THREE.Vector3(0.02, 0, 0.01); 
    public timeSpeed: number = 1.0;
    
    private onLog?: (message: string, type: 'info' | 'warning' | 'error' | 'success') => void;

    constructor(scene: THREE.Scene, seed: number = Date.now()) {
        this.scene = scene;
        this.rng = new MSVCRand(seed);
        this.growthController = new GrowthController(this.rng);
        
        this.stats = this.growthController.initStats();
        this.root = new TreeSection(null, 0, this.rng);
        this.scene.add(this.root.group);
        
        this.initRoots();
        this.loadState();
    }

    private initRoots(): void {
        const rootCount = 5 + Math.floor(this.rng.randFloat() * 3); // Оригинальное количество (5-8)
        for (let i = 0; i < rootCount; i++) {
            const treeRoot = new TreeRoot(this.scene, 0, this.rng);
            this.treeRoots.push(treeRoot);
        }
    }

    public update(deltaTime: number): void {
        this.updateClock(deltaTime);
        
        this.growthController.animateGrowth(this.stats, deltaTime, this.timeSpeed);
        const metabolismLogs = this.growthController.updateMetabolism(this.stats, this.lightIntensity, deltaTime);
        metabolismLogs.forEach(msg => this.addLog(msg, 'warning'));
        
        this.updateEnvironment();
        
        const ageFactor = this.stats.age / 10.0; 
        const dayOfYear = this.gameTime % 365;
        
        this.root.update(ageFactor, this.lightIntensity, {
            thickness: this.stats.trunkThickness,
            bend: this.stats.trunkBend,
            color: new THREE.Color(this.stats.colorR, this.stats.colorG, this.stats.colorB)
        }, this.stats.health, this.wind, dayOfYear, deltaTime);

        this.treeRoots.forEach(root => root.update(ageFactor, deltaTime));
    }

    private updateClock(deltaTime: number): void {
        const prevTime = this.gameTime;
        this.gameTime += deltaTime * this.timeSpeed * 5; 
        
        if (Math.floor(this.gameTime / 365.0) > Math.floor(prevTime / 365.0)) {
            this.growthController.updateYearlyTargets(this.stats, this.root);
            this.saveState();
            this.addLog("Прошел игровой год. Рост продолжается.", 'info');
        }

        if (this.stats.health > 0.7 && this.stats.energy > 0.5) {
            this.stats.targetAge += 0.05 * deltaTime * this.timeSpeed;
        }
    }

    private updateEnvironment(): void {
        const timeScale = (Date.now() * 0.001) % (Math.PI * 2);
        this.wind.x = 0.02 + Math.sin(timeScale) * 0.01;
        this.wind.z = 0.01 + Math.cos(timeScale * 0.5) * 0.01;
    }

    public prune(target: THREE.Object3D): boolean {
        if (this.root.prune(target)) {
            this.stats.energy = Math.min(1.0, this.stats.energy + 0.1); 
            this.addLog("Ветка обрезана. Энергия перераспределена.", 'info');
            this.saveState();
            return true;
        }
        return false;
    }

    public applyWire(target: THREE.Object3D): boolean {
        if (this.root.applyWire(target)) {
            this.addLog("Наложена проволока для коррекции роста.", 'info');
            this.saveState();
            return true;
        }
        return false;
    }

    public interact(): void {
        this.stats.energy = Math.min(1.0, this.stats.energy + 0.2);
        this.stats.health = Math.min(1.0, this.stats.health + 0.05);
        this.addLog("Дерево полито.", 'info');
        this.saveState();
    }

    public setLightIntensity(value: number): void {
        this.lightIntensity = value;
    }

    public setTimeSpeed(value: number): void {
        this.timeSpeed = value;
    }

    public setLogCallback(callback: (msg: string, type: 'info' | 'warning' | 'error' | 'success') => void): void {
        this.onLog = callback;
    }

    private addLog(message: string, type: 'info' | 'warning' | 'error' | 'success' = 'info'): void {
        if (this.onLog) this.onLog(message, type);
    }

    public saveState(): void {
        const state = {
            stats: this.stats,
            gameTime: this.gameTime,
            tree: this.root.serialize(),
            roots: this.treeRoots.map(r => r.serialize())
        };
        localStorage.setItem('gobonsai_state', JSON.stringify(state));
    }

    private loadState(): boolean {
        const saved = localStorage.getItem('gobonsai_state');
        if (saved) {
            try {
                const data = JSON.parse(saved);
                this.stats = data.stats;
                this.gameTime = data.gameTime;
                
                if (this.root && this.root.group.parent) {
                    this.scene.remove(this.root.group);
                }
                this.treeRoots.forEach(r => {
                    if (r.group.parent) this.scene.remove(r.group);
                });
                
                this.root = TreeSection.deserialize(data.tree, null, this.rng);
                this.scene.add(this.root.group);

                if (data.roots) {
                    this.treeRoots = data.roots.map((rd: any) => TreeRoot.deserialize(this.scene, rd, this.rng));
                }
                
                return true;
            } catch (e) {
                console.error("Failed to load state", e);
            }
        }
        return false;
    }

    public get health() { return this.stats.health; }
    public get energy() { return this.stats.energy; }
    public get age() { return this.stats.age; }
    public get targetAge() { return this.stats.targetAge; }
}
