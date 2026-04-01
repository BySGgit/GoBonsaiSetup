import * as THREE from 'three';
import { TreeSection } from './TreeSection';
import { GrowthConstants } from './config/GrowthConstants';
import { MSVCRand } from './MSVCRand';

const _inv = new THREE.Matrix4();
const _normalMat = new THREE.Matrix3();
const _lightWorld = new THREE.Vector3();
const _lightLocal = new THREE.Vector3();
const _localUp = new THREE.Vector3(0, 1, 0);

export interface MetabolismState {
    energy: number;
    health: number;
    trunkThickness: number;
    age: number;
}

/**
 * sub_416510.c — свет: D3DXMatrixInverse(this+104) + sub_401540 (D3DXVec3TransformNormal) + dot с flt_4D5390/8C/94.
 * Здесь: inverse(world) + normal matrix, локальный «вверх» · свет (эквивалентно мировому up·L при ортогональной части).
 * v34 = *(+52)*v22 + *(+53)*0.5; энергия; пропуск роста.
 */
export interface MetabolismUpdateResult {
    logs: string[];
    /** Суммарный «расход» локальной energy по секциям за кадр — прокси для части root+436 (до полного sub_414E10). */
    totalEnergySpent: number;
}

export class MetabolismService {
    public static update(
        stats: MetabolismState,
        root: TreeSection,
        lightDirection: THREE.Vector3,
        lightIntensity: number,
        deltaTime: number,
        rng: MSVCRand
    ): MetabolismUpdateResult {
        const logs: string[] = [];
        MetabolismService.syncMetabolismLightScales(root);
        MetabolismService.clearGrowthSkipFlags(root);
        const totalEnergySpent = MetabolismService.updateBranchEnergyTree(
            root,
            lightDirection,
            lightIntensity,
            deltaTime,
            rng,
            stats.trunkThickness
        );
        stats.energy = root.energy;

        const dtScale = Math.min(2, deltaTime * 60);
        const energy = stats.energy;

        if (energy < GrowthConstants.CRITICAL_ENERGY_THRESHOLD) {
            stats.health -= GrowthConstants.HEALTH_DECAY_CRITICAL * dtScale;
            if (stats.health < 0) stats.health = 0;
            logs.push('Critical energy! Health decaying.');
        } else if (energy < GrowthConstants.LOW_ENERGY_THRESHOLD) {
            stats.health -= GrowthConstants.HEALTH_DECAY_LOW * dtScale;
            if (stats.health < 0) stats.health = 0;
            logs.push('Low energy. Health slowly decaying.');
        } else if (energy > GrowthConstants.HIGH_ENERGY_THRESHOLD && stats.health < 1.0) {
            stats.health += GrowthConstants.HEALTH_RECOVERY_RATE * dtScale;
            if (stats.health > 1.0) stats.health = 1.0;
        }

        if (stats.age > GrowthConstants.AGE_HEALTH_DECAY_START) {
            const ageFactor =
                (stats.age - GrowthConstants.AGE_HEALTH_DECAY_START) * GrowthConstants.AGE_HEALTH_DECAY_RATE;
            stats.health -= ageFactor * dtScale;
            if (stats.health < 0) stats.health = 0;
        }

        if (stats.health <= 0) {
            logs.push('Tree has died from neglect!');
        }

        return { logs, totalEnergySpent };
    }

    private static syncMetabolismLightScales(root: TreeSection): void {
        const stack: TreeSection[] = [root];
        while (stack.length) {
            const s = stack.pop()!;
            s.metabolismLightScale = s.baseGrowth;
            for (const c of s.children) stack.push(c);
        }
    }

    private static clearGrowthSkipFlags(root: TreeSection): void {
        const stack: TreeSection[] = [root];
        while (stack.length) {
            const s = stack.pop()!;
            s.skipGrowthTick = false;
            for (const c of s.children) stack.push(c);
        }
    }

    private static updateBranchEnergyTree(
        root: TreeSection,
        lightDirection: THREE.Vector3,
        lightIntensityUser: number,
        deltaTime: number,
        rng: MSVCRand,
        trunkThicknessHint: number
    ): number {
        const lv = GrowthConstants.LIGHT_VECTOR;
        const simTicks = Math.min(2, deltaTime * 60);
        const b4 = GrowthConstants.FLT_4D63B4;
        const b8 = GrowthConstants.FLT_4D63B8;
        const bC = GrowthConstants.FLT_4D63BC;

        let totalSpent = 0;

        const visit = (section: TreeSection, isRoot: boolean): void => {
            const energyBeforeVisit = section.energy;

            if (lightDirection.lengthSq() > 1e-12) {
                _lightWorld.copy(lightDirection).normalize().multiplyScalar(lightIntensityUser);
            } else {
                _lightWorld.set(
                    lv.x * lightIntensityUser,
                    lv.y * lightIntensityUser,
                    lv.z * lightIntensityUser
                );
            }

            _inv.copy(section.group.matrixWorld).invert();
            _normalMat.getNormalMatrix(_inv);
            _lightLocal.copy(_lightWorld).applyNormalMatrix(_normalMat);

            const v21 =
                _localUp.x * _lightLocal.x + _localUp.y * _lightLocal.y + _localUp.z * _lightLocal.z;
            const v22 = Math.abs(v21);

            let v34 = section.metabolismLightScale * v22 + section.metabolismLightOffset * 0.5;
            if (v34 >= 0) {
                if (v34 > 1.0) v34 = 1.0;
            } else {
                v34 = 0;
            }

            section.lastLightFactor = v34;

            let v29 = (v34 - b4) / (0.0 - b4);
            if (v29 < 0) v29 = 0;
            if (v29 > 1) v29 = 1;
            const v24 = v29;

            let energy = section.energy - v24 * b8 * simTicks;
            if (energy < 0) energy = 0;
            if (energy > 1) energy = 1;
            section.energy = energy;

            const v4 = 0.0;
            if (v4 >= section.energy || (1.0 - section.energy) * bC > rng.randFloat()) {
                section.skipGrowthTick = true;
            }

            if (isRoot && trunkThicknessHint <= GrowthConstants.METABOLISM_ROOT_THICKNESS_GATE) {
                const v23 = trunkThicknessHint;
                section.energy -= rng.randFloat() * 0.025 * (1.0 - v23 / 0.01) * simTicks;
                if (section.energy < 0) section.energy = 0;
            }

            const localSpent = Math.max(0, energyBeforeVisit - section.energy);
            const scale = GrowthConstants.SUB40DC90_METABOLISM_SPENT_SCALE as number;
            // sub_414E10 суммирует +436 только от листьевых ветвей (sub_416510); внутренние узлы — через детей.
            if (section.children.length === 0) {
                totalSpent += localSpent;
                section.energySpent436 = Math.min(1, localSpent * scale);
            } else {
                section.energySpent436 = 0;
            }

            for (const child of section.children) {
                visit(child, false);
            }
        };

        visit(root, true);
        return totalSpent;
    }
}
