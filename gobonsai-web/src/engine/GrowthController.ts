import { MSVCRand } from './MSVCRand';
import { TreeSection } from './TreeSection';
import { MetabolismService } from './MetabolismService';
import { GrowthService, GrowthState } from './GrowthService';
import { BranchingService } from './BranchingService';

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

        const r = this.rng.randFloat(); // v5 (a1[63], a1[59])
        const g = this.rng.randFloat(); // v6 (a1[64], a1[60])
        const b = this.rng.randFloat(); // v8 (a1[65], a1[61])

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

    public updateYearlyTargets(stats: GrowthStats, root: TreeSection): void {
        GrowthService.updateYearlyTargets(stats, this.rng);
        this.updateGrowthVectors(root);

        if (stats.health > 0.4) {
            const energySpent = BranchingService.process(root, stats.energy, this.rng);
            stats.energy = Math.max(0, stats.energy - energySpent);
        }
    }

    private updateGrowthVectors(section: TreeSection): void {
        const noise = 0.2 * (section.level + 1);
        section.targetRotation.x += (this.rng.randFloat() - 0.5) * noise;
        section.targetRotation.y += (this.rng.randFloat() - 0.5) * noise;
        section.targetRotation.z += (this.rng.randFloat() - 0.5) * noise;

        for (const child of section.children) {
            this.updateGrowthVectors(child);
        }
    }

    public animateGrowth(stats: GrowthStats, deltaTime: number, timeSpeed: number): void {
        GrowthService.animate(stats, deltaTime, timeSpeed);
    }

    public updateMetabolism(stats: GrowthStats, lightIntensity: number, deltaTime: number): string[] {
        return MetabolismService.update(stats, stats.age, lightIntensity, deltaTime);
    }
}
