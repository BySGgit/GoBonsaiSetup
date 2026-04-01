import * as THREE from 'three';
import { TreeSection } from './TreeSection';
import { TreeRoot } from './TreeRoot';
import { MSVCRand } from './MSVCRand';
import { GrowthController, GrowthStats } from './GrowthController';
import { TransformService } from './math/TransformService';
import { Sub416510Rotation } from './math/Sub416510Rotation';
import { WorldGrowthState } from './world/WorldGrowthState';
import { GrowthFramePipeline } from './growth/GrowthFramePipeline';
import { SectionRuntimeType } from './SectionRuntimeType';

export class BonsaiController {
    private scene: THREE.Scene;
    public rng: MSVCRand;
    private growthController: GrowthController;
    /** Глобальные величины мира (день симуляции, пул энергии) — см. world/WorldGrowthState */
    public readonly worldGrowth: WorldGrowthState;
    private readonly growthFrame: GrowthFramePipeline;
    
    private stats: GrowthStats;
    public gameTime: number = 0;
    public root: TreeSection;
    public treeRoots: TreeRoot[] = [];
    
    public lightIntensity: number = 1.0;
    public wind: THREE.Vector3 = new THREE.Vector3(0.02, 0, 0.01); 
    public timeSpeed: number = 1.0;
    
    private onLog?: (message: string, type: 'info' | 'warning' | 'error' | 'success') => void;
    private _dbgFrame: number = 0;

    constructor(scene: THREE.Scene, seed: number = Date.now()) {
        this.scene = scene;
        this.rng = new MSVCRand(seed);
        this.growthController = new GrowthController(this.rng);
        this.worldGrowth = new WorldGrowthState();
        this.growthFrame = new GrowthFramePipeline(this.growthController);
        
        this.stats = this.growthController.initStats();
        this.root = new TreeSection(null, 0, this.rng);
        // sub_417220 TreeSectionSeed: *(this+4)=8, *(float*)(this+428)=1.0
        this.root.sectionRuntimeType4 = SectionRuntimeType.TreeSectionSeed;
        this.root.sub414CE0SeedBudget428 = 1.0;
        
        // Root initial lean — subtle tilt only (±5°)
        TransformService.rotationYawPitchRoll(
            this.root.targetRotation,
            this.stats.trunkRotationY * 0.05,
            this.stats.trunkRotationX * 0.05,
            this.stats.trunkRotationZ * 0.05
        );
        this.root.rotationQuaternion.copy(this.root.targetRotation);
        this.root.rotation.copy(this.root.targetRotation);
        Sub416510Rotation.syncBlob80FromQuaternion(this.root);

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

        this.worldGrowth.syncEnergyFromStats(this.stats.energy);

        const metabolismLogs = this.growthFrame.run({
            deltaTime,
            timeSpeed: this.timeSpeed,
            stats: this.stats,
            root: this.root,
            worldGrowth: this.worldGrowth,
            onSimulationYearCrossed: () => {
                this.saveState();
                this.addLog("Прошел игровой год. Рост продолжается.", "info");
            },
            lightIntensity: this.lightIntensity,
            wind: this.wind,
            treeRoots: this.treeRoots,
            tickEnvironment: () => this.updateEnvironment(),
            rng: this.rng,
        });
        metabolismLogs.forEach(msg => this.addLog(msg, 'warning'));

        // DEBUG: log tree state every 120 frames
        if (!this._dbgFrame) this._dbgFrame = 0;
        if (++this._dbgFrame % 120 === 0) {
            const count = (s: TreeSection): number => {
                let n = 1;
                for (const c of s.children) n += count(c);
                return n;
            };
            const dumpTree = (s: TreeSection, depth: number): string => {
                const pad = '  '.repeat(depth);
                const t = s.sectionRuntimeType4;
                const b432 = (s.energyBudget432 as number).toFixed(4);
                const p420 = (s.energyProduction420 as number).toFixed(4);
                const tR = (s.twigRadius444 as number).toFixed(5);
                const tL = (s.twigLength448 as number).toFixed(5);
                const mg = (s.maxGrowth as number).toFixed(4);
                const gf = s.growthFlag512 ? 'T' : 'F';
                const bg = (s.baseGrowth as number).toFixed(4);
                const det = s.markedForDetach236 ? 'D!' : '';
                const w428 = (s.energyWeight428 as number).toFixed(4);
                const gR = (s.growthRate as number).toFixed(4);
                const lf = (s.lastLightFactor as number).toFixed(3);
                let line = `${pad}[t${t}] bud432=${b432} prod420=${p420} tR=${tR} tL=${tL} max=${mg} gf=${gf} bg=${bg} w=${w428} gR=${gR} lf=${lf} ${det}`;
                for (const c of s.children) line += '\n' + dumpTree(c, depth + 1);
                return line;
            };
            const sf = this.worldGrowth.seasonFactor().toFixed(3);
            console.log(
                `[Bonsai] sections=${count(this.root)}`
                + ` day=${this.worldGrowth.simulationDay}`
                + ` season=${sf}`
                + ` E=${this.stats.energy.toFixed(3)}`
                + ` age=${this.stats.age.toFixed(2)}`
                + `\n` + dumpTree(this.root, 0)
            );
        }

        this.worldGrowth.syncEnergyFromStats(this.stats.energy);
    }

    private updateClock(deltaTime: number): void {
        this.gameTime += deltaTime * this.timeSpeed * 5;

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
            this.root.energy = this.stats.energy;
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
        this.root.energy = this.stats.energy;
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
            simulationDay: this.worldGrowth.simulationDay,
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

                // Validate stats integrity — reject corrupted saves
                const s = data.stats;
                if (!s || typeof s.energy !== 'number') {
                    console.warn("Corrupted save state detected, starting fresh");
                    localStorage.removeItem('gobonsai_state');
                    return false;
                }

                // Repair targets that fell behind current values (old save compat)
                if (typeof s.targetThickness !== 'number' || s.targetThickness < 0.1) {
                    s.targetThickness = (s.trunkThickness || 0) + 5.0;
                }
                if (typeof s.targetAge !== 'number' || s.targetAge < (s.age || 0)) {
                    s.targetAge = (s.age || 0) + 1.0;
                }
                if (typeof s.targetBend !== 'number') {
                    s.targetBend = s.trunkBend || 3.0;
                }

                this.stats = s;
                this.gameTime = data.gameTime;
                if (typeof data.simulationDay === "number") {
                    this.worldGrowth.simulationDay = data.simulationDay;
                }
                
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
                localStorage.removeItem('gobonsai_state');
            }
        }
        return false;
    }

    public get health() { return this.stats.health; }
    public get energy() { return this.stats.energy; }
    public get age() { return this.stats.age; }
    public get targetAge() { return this.stats.targetAge; }
}
