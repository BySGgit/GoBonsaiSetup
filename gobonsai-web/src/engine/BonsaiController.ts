import * as THREE from 'three';
import { TreeSection } from './TreeSection';
import { TreeRoot } from './TreeRoot';
import { MSVCRand } from './MSVCRand';
import { GrowthController, GrowthStats } from './GrowthController';
import { Sub416510Rotation } from './math/Sub416510Rotation';
import { WorldGrowthState } from './world/WorldGrowthState';
import { GrowthFramePipeline } from './growth/GrowthFramePipeline';
import { SectionRuntimeType } from './SectionRuntimeType';
import { GrowthConstants } from './config/GrowthConstants';
import { TREE_CONSTANTS } from './TreeConstants';
import { writeUnifiedBudget428 } from './growth/sub414CE0';

export class BonsaiController {
    private scene: THREE.Scene;
    public rng: MSVCRand;
    private growthController: GrowthController;
    /** Р“Р»РѕР±Р°Р»СЊРЅС‹Рµ РІРµР»РёС‡РёРЅС‹ РјРёСЂР° (РґРµРЅСЊ СЃРёРјСѓР»СЏС†РёРё, РїСѓР» СЌРЅРµСЂРіРёРё) вЂ” СЃРј. world/WorldGrowthState */
    public readonly worldGrowth: WorldGrowthState;
    private readonly growthFrame: GrowthFramePipeline;
    
    private stats: GrowthStats;
    public gameTime: number = 0;
    public root: TreeSection;
    public treeRoots: TreeRoot[] = [];
    
    public lightIntensity: number = 1.0;
    /**
     * Р‘Р°Р·РѕРІС‹Р№ РІРµС‚РµСЂ (РґР»СЏ Р»СѓС‡РµР№ sub_40E460 Рё РЅРµstrict sway). Р’ strict-exe СЂРµР¶РёРјРµ (`VITE_STRICT_EXE_SIM_PATH=true`)
     * `tickEnvironment` РЅРµ РєСЂСѓС‚РёС‚ РІРµРєС‚РѕСЂ РєР°Р¶РґС‹Р№ РєР°РґСЂ вЂ” РѕСЃС‚Р°С‘С‚СЃСЏ СЌС‚Рѕ Р·РЅР°С‡РµРЅРёРµ.
     */
    public wind: THREE.Vector3 = new THREE.Vector3(0.004, 0, 0.002); 
    public timeSpeed: number = 1.0;
    
    private onLog?: (message: string, type: 'info' | 'warning' | 'error' | 'success') => void;
    private _dbgFrame: number = 0;
    private readonly debugTreeLogs: boolean =
        typeof window !== "undefined" &&
        window.localStorage.getItem("gobonsai_debug_tree") === "1";
    private readonly debugTreeDumpMaxNodes: number =
        typeof window !== "undefined"
            ? Math.max(
                40,
                Math.min(
                    400,
                    Number.parseInt(
                        window.localStorage.getItem("gobonsai_debug_tree_max_nodes") ?? "120",
                        10,
                    ) || 120,
                ),
            )
            : 120;
    private readonly debugTreeDumpMaxDepth: number =
        typeof window !== "undefined"
            ? Math.max(
                2,
                Math.min(
                    12,
                    Number.parseInt(
                        window.localStorage.getItem("gobonsai_debug_tree_max_depth") ?? "8",
                        10,
                    ) || 8,
                ),
            )
            : 8;
    /** sub_412700.c: `flt_4D8D04` вЂ” РЅР°РєРѕРїРёС‚РµР»СЊ РґРѕ С€Р°РіР° `flt_4DBEE4` (~1/30 СЃ) Рё РІС‹Р·РѕРІР° `sub_4130D0` */
    private simTimeBank412700 = 0;

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
        this.root.isContinuation = true;
        writeUnifiedBudget428(this.root, 1.0);
        
        // РЎРµРјСЏ/РєРѕСЂРµРЅСЊ: Р±РµР· РЅР°С‡Р°Р»СЊРЅРѕРіРѕ РЅР°РєР»РѕРЅР° вЂ” РЅР°РєР»РѕРЅ Р·Р°РґР°С‘С‚СЃСЏ СЂРѕСЃС‚РѕРј РІРµС‚РѕРє Рё С„РёР·РёРєРѕР№.
        // (СЂР°РЅСЊС€Рµ: trunkRotation * 0.05 РґР°РІР°Р»Рѕ Р·Р°РјРµС‚РЅС‹Р№ СѓРіРѕР» В«СЃ РїРµСЂРІРѕРіРѕ РєР°РґСЂР°В».)
        this.root.targetRotation.identity();
        this.root.rotationQuaternion.identity();
        this.root.rotation.identity();
        Sub416510Rotation.syncBlob80FromQuaternion(this.root);

        this.scene.add(this.root.group);
        
        this.initRoots();
        this.loadState();
    }

    private initRoots(): void {
        const rootCount = 1;
        for (let i = 0; i < rootCount; i++) {
            const treeRoot = new TreeRoot(this.scene, 0, this.rng);
            this.treeRoots.push(treeRoot);
        }
    }

    public update(deltaTime: number): void {
        this.updateClock(deltaTime);

        // sub_408D60: РёРЅС‚РµСЂРїРѕР»СЏС†РёСЏ UI-СЃС‚Р°С‚РѕРІ РЅР° С‡Р°СЃС‚РѕС‚Рµ СЂРµРЅРґРµСЂР° (РЅРµ РїСЂРёРІСЏР·Р°РЅР° Рє sub_4130D0)
        this.growthController.animateGrowth(this.stats, deltaTime, this.timeSpeed);

        const SIM_DT = GrowthConstants.SIM_FRAME_DT_SUB_412700 as number;
        const cappedRealDelta = Math.min(
            deltaTime,
            GrowthConstants.MAX_DELTA_SUB_412700 as number,
        );
        // Keep speed multiplier effective at high xN; cap only real frame delta.
        this.simTimeBank412700 += cappedRealDelta * this.timeSpeed;

        const metabolismLogs: string[] = [];
        while (this.simTimeBank412700 >= SIM_DT) {
            this.simTimeBank412700 -= SIM_DT;
            metabolismLogs.push(
                ...this.growthFrame.run({
                    deltaTime,
                    timeSpeed: this.timeSpeed,
                    stats: this.stats,
                    root: this.root,
                    worldGrowth: this.worldGrowth,
                    onSimulationYearCrossed: () => {
                        this.saveState();
                        this.addLog("Simulation year passed. Growth continues.", "info");
                    },
                    lightIntensity: this.lightIntensity,
                    wind: this.wind,
                    treeRoots: this.treeRoots,
                    tickEnvironment: () => this.updateEnvironment(),
                    rng: this.rng,
                    scene: this.scene,
                    simFrameDt: SIM_DT,
                    renderDeltaTime: deltaTime,
                }),
            );
        }
        metabolismLogs.forEach(msg => this.addLog(msg, 'warning'));

        // Optional heavy debug dump (disabled by default).
        if (this.debugTreeLogs) {
            if (!this._dbgFrame) this._dbgFrame = 0;
            if (++this._dbgFrame % 120 === 0) {
                let sections = 0;
                const byType = new Map<number, number>();
                const stack: TreeSection[] = [this.root];
                while (stack.length) {
                    const s = stack.pop()!;
                    sections++;
                    const t = s.sectionRuntimeType4;
                    byType.set(t, (byType.get(t) ?? 0) + 1);
                    for (const c of s.children) stack.push(c);
                }
                const typeSummary = [...byType.entries()]
                    .sort((a, b) => a[0] - b[0])
                    .map(([t, n]) => `t${t}:${n}`)
                    .join(",");

                let remaining = this.debugTreeDumpMaxNodes;
                let truncated = false;
                const maxDepth = this.debugTreeDumpMaxDepth;
                const dumpTree = (s: TreeSection, depth: number): string => {
                    const pad = '  '.repeat(depth);
                    if (remaining <= 0) {
                        truncated = true;
                        return `${pad}... [truncated]`;
                    }
                    remaining--;
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
                    if (depth >= maxDepth) {
                        if (s.children.length > 0) {
                            truncated = true;
                            line += ` [depth-cut children=${s.children.length}]`;
                        }
                        return line;
                    }
                    for (const c of s.children) {
                        if (remaining <= 0) {
                            truncated = true;
                            break;
                        }
                        line += '\n' + dumpTree(c, depth + 1);
                    }
                    return line;
                };
                const sf = this.worldGrowth.seasonFactor().toFixed(3);
                const treeDump = dumpTree(this.root, 0);
                const tail = truncated
                    ? `\n... [dump limited: maxNodes=${this.debugTreeDumpMaxNodes}, maxDepth=${this.debugTreeDumpMaxDepth}]`
                    : "";
                console.log(
                    `[Bonsai] sections=${sections}`
                    + ` day=${this.worldGrowth.simulationDay}`
                    + ` season=${sf}`
                    + ` E=${this.stats.energy.toFixed(3)}`
                    + ` age=${this.stats.age.toFixed(2)}`
                    + ` types=${typeSummary}`
                    + `\n` + treeDump
                    + tail
                );
            }
        }

        this.stats.energy = this.worldGrowth.normalizedEnergy;
    }

    private updateClock(deltaTime: number): void {
        this.gameTime += deltaTime * this.timeSpeed * 5;
    }

    private updateEnvironment(): void {
        const timeScale = this.gameTime % (Math.PI * 2);
        // РЎР»Р°Р±Р°СЏ РјРѕРґСѓР»СЏС†РёСЏ вЂ” РёРЅР°С‡Рµ sub_414A70 РЅР°РєР°РїР»РёРІР°РµС‚ РєСЂРµРЅ В«РІ СЃС‚РѕСЂРѕРЅСѓВ» Р·Р° С‚С‹СЃСЏС‡Рё РєР°РґСЂРѕРІ
        this.wind.x = 0.004 + Math.sin(timeScale) * 0.002;
        this.wind.z = 0.002 + Math.cos(timeScale * 0.5) * 0.002;
    }

    public prune(
        target: THREE.Object3D,
        options?: { removeSection?: boolean; removeTerminalSection?: boolean },
    ): boolean {
        if (this.root.prune(target, options)) {
            this.worldGrowth.energyPool += (GrowthConstants.INITIAL_ENERGY_POOL_196 as number) * 0.1;
            this.stats.energy = this.worldGrowth.normalizedEnergy;
            this.root.energy = this.stats.energy;
            this.addLog("Branch pruned. Energy redistributed.", 'info');
            this.saveState();
            return true;
        }
        return false;
    }

    public applyWire(target: THREE.Object3D): boolean {
        if (this.root.applyWire(target)) {
            this.addLog("Wire applied for growth correction.", 'info');
            this.saveState();
            return true;
        }
        return false;
    }

    public interact(): void {
        this.worldGrowth.energyPool += (GrowthConstants.INITIAL_ENERGY_POOL_196 as number) * 0.2;
        this.stats.energy = this.worldGrowth.normalizedEnergy;
        this.root.energy = this.stats.energy;
        this.stats.health = Math.min(1.0, this.stats.health + 0.05);
        this.addLog("Tree watered.", 'info');
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
            growthAccumulator4D7EF8: this.worldGrowth.growthAccumulator4D7EF8,
            energyPool196: this.worldGrowth.energyPool,
            simTimeBank412700: this.simTimeBank412700,
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

                // Validate stats integrity вЂ” reject corrupted saves
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
                if (typeof data.growthAccumulator4D7EF8 === "number") {
                    this.worldGrowth.growthAccumulator4D7EF8 = data.growthAccumulator4D7EF8;
                }
                if (typeof data.energyPool196 === "number") {
                    this.worldGrowth.energyPool = data.energyPool196;
                }
                if (typeof data.simTimeBank412700 === "number") {
                    this.simTimeBank412700 = data.simTimeBank412700;
                }
                
                if (this.root && this.root.group.parent) {
                    this.scene.remove(this.root.group);
                }
                this.treeRoots.forEach(r => {
                    if (r.group.parent) this.scene.remove(r.group);
                });
                
                this.root = TreeSection.deserialize(data.tree, null, this.rng);
                this.normalizeUnifiedBudget428(this.root);
                this.normalizeContinuationChain(this.root);
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

    /**
     * Backward-compat repair for old saves where continuation flags were not populated.
     * Marks the main apical Seed/Twig/Bud chain so detach/visual branches don't treat it as lateral.
     */
    private normalizeContinuationChain(root: TreeSection): void {
        const all: TreeSection[] = [];
        const stack: TreeSection[] = [root];
        while (stack.length) {
            const s = stack.pop()!;
            all.push(s);
            for (const c of s.children) stack.push(c);
        }
        for (const s of all) {
            s.isContinuation = false;
        }

        let current: TreeSection | null = root;
        while (current) {
            current.isContinuation = true;
            const candidates: TreeSection[] = current.children.filter(
                (c: TreeSection) =>
                    !c.worldDetached188 &&
                    (c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig ||
                        c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionBud),
            );
            if (candidates.length === 0) break;
            let next: TreeSection = candidates[0] as TreeSection;
            for (let i = 1; i < candidates.length; i++) {
                if ((candidates[i].branchPosition as number) > (next.branchPosition as number)) {
                    next = candidates[i];
                }
            }
            current = next;
        }
    }

    /**
     * Backward-compat repair for old saves where +428 aliases could diverge.
     * Keeps `energyWeight428` as source of truth and mirrors it into yearly alias.
     */
    private normalizeUnifiedBudget428(root: TreeSection): void {
        const stack: TreeSection[] = [root];
        while (stack.length) {
            const s = stack.pop()!;
            const runtime = s.energyWeight428 as number;
            const yearly = s.sub414CE0SeedBudget428 as number;
            const unified = runtime !== 0 ? runtime : yearly;
            const v = unified as typeof s.energyWeight428;
            s.energyWeight428 = v;
            s.sub414CE0SeedBudget428 = v;
            for (const c of s.children) stack.push(c);
        }
    }

    public get health() { return this.stats.health; }
    public get energy() { return this.stats.energy; }
    public get age() { return this.worldGrowth.simulationDay / 365.0; }
    public get targetAge() { return this.worldGrowth.simulationDay / 365.0; }
    public get simulationDay() { return this.worldGrowth.simulationDay; }
}
