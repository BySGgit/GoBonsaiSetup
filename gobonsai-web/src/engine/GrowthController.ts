import * as THREE from 'three';
import { MSVCRand } from './MSVCRand';
import { TreeSection } from './TreeSection';
import { MetabolismService, MetabolismUpdateResult } from './MetabolismService';
import { GrowthService, GrowthState } from './GrowthService';
import { BranchingService } from './BranchingService';
import { GrowthConstants } from './config/GrowthConstants';
import { Float32 } from './math/MathTypes';
import { TransformService } from './math/TransformService';
import { TREE_CONSTANTS } from './TreeConstants';
import { SectionColorService } from './SectionColorService';

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
    public updateYearlyTargets(stats: GrowthStats, root: TreeSection): void {
        GrowthService.updateYearlyTargets(stats, this.rng);
        this.applySubtleYearlyBendDrift(stats);

        const d = GrowthConstants.FLT_4D7EF4 as number;
        let e = stats.energy * 0.9 * (1.0 - d);
        if (e < 0) e = 0;
        if (e > 1) e = 1;
        stats.energy = e;
        root.energy = e as Float32;

        if (stats.health > 0.4) {
            const energySpent = BranchingService.process(root, stats.energy, this.rng);
            stats.energy = Math.max(0, stats.energy - energySpent);
            root.energy = stats.energy as Float32;
        }
    }

    /**
     * sub_416510.c:225–306 — currentGrowth, накопления +105/+106, прирост growthRate при headroom;
     * продолжение сегмента (TS) когда growthRate достиг maxGrowth.
     */
    public updateSectionGrowth(section: TreeSection, deltaTime: number, treeAge: number): void {
        if (section.skipGrowthTick) {
            for (const child of section.children) {
                this.updateSectionGrowth(child, deltaTime, treeAge);
            }
            return;
        }

        if (section.baseGrowth <= 0.0) {
            section.isPruned = true;
            return;
        }

        const simTicks = Math.min(2, deltaTime * 60);
        const v34 = Math.min(1, section.lastLightFactor);

        section.currentGrowth = Math.min(1.0, section.baseGrowth * section.energy);

        const v16 = section.growthRate * v34;
        const v19 =
            v16 *
            v34 *
            section.energy *
            GrowthConstants.LEAF_ENERGY_PRODUCTION *
            simTicks;
        section.growthScratchA = v19;
        section.growthScratchB += v19;

        if (section.growthRate < section.maxGrowth) {
            const v27 = v34 * GrowthConstants.FLT_4D63C4;
            const rnd = this.rng.randFloat() * 0.5 + 0.5;
            let v33 = rnd * (section.energy * v27) + section.growthRate;
            if (v33 > section.maxGrowth) v33 = section.maxGrowth;
            section.growthRate = v33;
            section.growthTarget = section.growthRate + section.growthRate;
        } else {
            const hasContinuation = section.children.some(c => c.isContinuation);
            if (!hasContinuation && section.baseGrowth > 0.1) {
                const nextSection = section.addBranch(1.0, true);
                if (nextSection) {
                    nextSection.baseGrowth = section.baseGrowth * 0.85;
                    nextSection.maxGrowth = section.maxGrowth * 0.9;
                    section.growthRate = section.maxGrowth;
                }
            }
        }

        SectionColorService.applyFrom416510(section, treeAge);

        for (const child of section.children) {
            this.updateSectionGrowth(child, deltaTime, treeAge);
        }
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
        deltaTime: number
    ): MetabolismUpdateResult {
        return MetabolismService.update(stats, root, lightDirection, lightIntensity, deltaTime, this.rng);
    }
}
