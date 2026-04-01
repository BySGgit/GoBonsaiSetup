import { TREE_CONSTANTS } from './TreeConstants';

function u32(x: number): number {
    return x >>> 0;
}
import { MSVCRand } from './MSVCRand';
import { TreeSection } from './TreeSection';
import { GrowthConstants } from './config/GrowthConstants';
import { TransformService } from './math/TransformService';

export class BranchingService {
    /**
     * sub_4188E0.c — lateral branch spawn.
     * v13 = growth headroom; v14 = clamped probability; v15/yaw, v19/pitch for direction.
     */
    public static process(section: TreeSection, energy: number, rng: MSVCRand): number {
        const { GROWTH } = TREE_CONSTANTS;
        let energyConsumed = 0;
        
        if (section.level >= GROWTH.MAX_LEVEL) return 0;

        const v13 = Math.max(0, section.baseGrowth - section.currentGrowth);
        const growthNorm = section.maxGrowth > 0 ? section.growthRate / section.maxGrowth : 0;
        if (growthNorm < 0.38 || energy <= 0.22) {
            for (const child of section.children) {
                if (energy > 0.08) energyConsumed += this.process(child, energy - energyConsumed, rng);
            }
            return energyConsumed;
        }

        if (v13 >= GrowthConstants.BRANCH_THRESHOLD_MIN * 0.2 || growthNorm > 0.72) {
            let v14 = (v13 / GrowthConstants.BRANCH_THRESHOLD_MAX) * 0.0003;
            v14 = Math.max(0, Math.min(0.003, v14));
            const yearlyP = Math.min(0.38, v14 * 420 + growthNorm * 0.06);

            const sideBranches = section.children.filter(c => !c.isContinuation);
            const maxSideBranches = section.level === 0 ? 4 : 2;

            if (sideBranches.length < maxSideBranches && yearlyP > rng.randFloat()) {
                const spawnPos = 0.28 + rng.randFloat() * 0.62;
                const newBranch = section.addBranch(spawnPos, false);
                if (newBranch) {
                    section.spawnDelta480 = u32(section.spawnDelta480 + 1);
                    const yaw = rng.randFloat() * (Math.PI * 2) - Math.PI;
                    const pitch = rng.randFloat() * 1.1 - 1.6;
                    TransformService.rotationYawPitchRoll(newBranch.targetRotation, -yaw, pitch, 0);

                    newBranch.baseGrowth = section.baseGrowth * 0.72;
                    newBranch.maxGrowth = Math.max(2.0, section.maxGrowth * 0.65);
                    energyConsumed += 0.22;
                    section.currentGrowth += Math.min(v13 * 0.35, 0.4);
                }
            }
        }

        for (const child of section.children) {
            if (energy - energyConsumed > 0.08) {
                energyConsumed += this.process(child, energy - energyConsumed, rng);
            }
        }

        return energyConsumed;
    }
}
