import * as THREE from 'three';
import { MSVCRand } from './MSVCRand';
import { TreeSection } from './TreeSection';
import { MetabolismService, MetabolismUpdateResult } from './MetabolismService';
import { GrowthService, GrowthState } from './GrowthService';
import { GrowthConstants } from './config/GrowthConstants';
import { Float32 } from './math/MathTypes';
import { TREE_CONSTANTS } from './TreeConstants';
import { WorldGrowthState } from './world/WorldGrowthState';
import { SectionRuntimeType } from './SectionRuntimeType';
export type GrowthStats = GrowthState & {
    energy: number;
    health: number;
};

export class GrowthController {
    private rng: MSVCRand;

    constructor(rng: MSVCRand) {
        this.rng = rng;
    }

    public initStats(): GrowthStats {
        // sub_408880.c
        const targetAge = this.rng.randFloat(); // a1[68]
        const currentAge = (this.rng.randFloat() * 0.800000011920929 + 0.2000000029802322); // a1[67]
        
        const targetThickness = (this.rng.randFloat() * 0.699999988079071 + 0.800000011920929) * 9.0; // a1[51]
        const targetBend = (this.rng.randFloat() * 0.4000000357627869 + 0.800000011920929) * 5.0; // a1[52]

        const rotX = (this.rng.randFloat() * 4.0 - 2.0); // v4 (a1[56])
        const rotZ = (this.rng.randFloat() * 4.0 - 2.0); // v7 (a1[58])

        // Use a natural wood color base instead of random RGB
        const r = 0.35 + this.rng.randFloat() * 0.1;
        const g = 0.25 + this.rng.randFloat() * 0.05;
        const b = 0.15 + this.rng.randFloat() * 0.05;

        return {
            age: currentAge,
            targetAge: targetAge,
            trunkThickness: 0.0, // a1[49] (начинается с 0 для анимации прорастания)
            targetThickness: targetThickness,
            trunkBend: 0.0,      // a1[50] (начинается с 0)
            targetBend: targetBend,
            trunkRotationX: rotX,
            trunkRotationY: 0.0,
            trunkRotationZ: rotZ,
            energy: 1.0,         // a1[66], a1[62]
            health: 1.0,
            colorR: r,
            colorG: g,
            colorB: b,
            targetColorR: r,
            targetColorG: g,
            targetColorB: b
        };
    }

    /**
     * sub_40DC90 §2.3 при смене года: sub_408A30 (цели), затем E *= 0.9 * (1 - flt_4D7EF4),
     * затем ветвление как часть кадра; virtual (*root+40) sub_414CE0 — отдельно от этого шага.
     */
    public updateYearlyTargets(stats: GrowthStats, root: TreeSection, worldGrowth?: WorldGrowthState): void {
        GrowthService.updateYearlyTargets(stats, this.rng);
        this.applySubtleYearlyBendDrift(stats);

        const d = GrowthConstants.FLT_4D7EF4 as number;
        if (worldGrowth) {
            worldGrowth.energyPool = worldGrowth.energyPool * 0.9 * (1.0 - d);
            if (worldGrowth.energyPool < 0) worldGrowth.energyPool = 0;
            root.energy = worldGrowth.normalizedEnergy as Float32;
            stats.energy = worldGrowth.normalizedEnergy;
        } else {
            let e = stats.energy * 0.9 * (1.0 - d);
            if (e < 0) e = 0;
            if (e > 1) e = 1;
            stats.energy = e;
            root.energy = e as Float32;
        }

        // Branching now happens inside twigUpdateSub417C90 → branchingDispatcherSub417F40
    }

    /**
     * Stripped-down sub_416510 tail: growthScratchA/B для aggregate (+420); цвет листьев — в processLeafMetabolism.
     */
    public updateEnergyScratches(root: TreeSection, deltaTime: number): void {
        const simTicks = Math.min(2, deltaTime * 60);
        const leafProd = GrowthConstants.LEAF_ENERGY_PRODUCTION as number;

        const walk = (section: TreeSection): void => {
            // sub_416510 writes local production for leaf path; keep non-leaf scratch at 0.
            section.growthScratchA = 0 as Float32;

            if (section.skipGrowthTick) {
                for (const c of section.children) walk(c);
                return;
            }

            if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
                const v34 = Math.min(1, section.lastLightFactor as number);
                const v16 = (section.growthRate as number) * v34;
                const v19 = v16 * v34 * (section.energy as number) * leafProd * simTicks;
                section.growthScratchA = v19 as Float32;
                section.growthScratchB = ((section.growthScratchB as number) + v19) as Float32;
            }

            // Цвет листьев — в processLeafMetabolism (treeAge); дублировать здесь нельзя.

            for (const c of section.children) walk(c);
        };
        walk(root);
    }

    /**
     * sub_408A30-style yearly drift on *global* bend only — avoids slamming every branch targetRotation (was causing whole-tree jumps).
     */
    private applySubtleYearlyBendDrift(stats: GrowthStats): void {
        const delta = (this.rng.randFloat() - 0.5) * 0.08;
        stats.targetBend = Math.min(
            TREE_CONSTANTS.GROWTH.BEND_LIMIT,
            Math.max(0, stats.targetBend + delta)
        );
    }

    public animateGrowth(stats: GrowthStats, deltaTime: number, timeSpeed: number): void {
        GrowthService.animate(stats, deltaTime, timeSpeed);
    }

    public updateMetabolism(
        stats: GrowthStats,
        root: TreeSection,
        lightDirection: THREE.Vector3,
        lightIntensity: number,
        deltaTime: number,
    ): MetabolismUpdateResult {
        return MetabolismService.update(
            stats,
            root,
            lightDirection,
            lightIntensity,
            deltaTime,
            this.rng,
            stats.age,
        );
    }
}
