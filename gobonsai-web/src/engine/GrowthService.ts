import { TREE_CONSTANTS } from './TreeConstants';
import { MSVCRand } from './MSVCRand';
import { TreeSection } from './TreeSection';

export interface GrowthState {
    age: number;
    targetAge: number;
    trunkThickness: number;
    targetThickness: number;
    trunkBend: number;
    targetBend: number;
    trunkRotationX: number;
    trunkRotationY: number;
    trunkRotationZ: number;
    colorR: number;
    colorG: number;
    colorB: number;
    targetColorR: number;
    targetColorG: number;
    targetColorB: number;
}

export class GrowthService {
    /**
     * Анимация параметров из sub_408D60.c
     */
    public static animate(state: GrowthState, deltaTime: number, timeSpeed: number): void {
        const { ANIMATION } = TREE_CONSTANTS;
        const stepMultiplier = deltaTime * 60.0 * timeSpeed;

        // Возраст
        this.interpolate(state, 'age', 'targetAge', ANIMATION.AGE_STEP * stepMultiplier);
        // Толщина
        this.interpolate(state, 'trunkThickness', 'targetThickness', ANIMATION.TRUNK_STEP * stepMultiplier);
        // Изгиб
        this.interpolate(state, 'trunkBend', 'targetBend', ANIMATION.BEND_STEP * stepMultiplier);
        
        // Цвета
        const colorStep = ANIMATION.COLOR_STEP * stepMultiplier;
        this.interpolate(state, 'colorR', 'targetColorR', colorStep);
        this.interpolate(state, 'colorG', 'targetColorG', colorStep);
        this.interpolate(state, 'colorB', 'targetColorB', colorStep);
    }

    private static interpolate(state: any, currentKey: string, targetKey: string, step: number): void {
        const diff = state[targetKey] - state[currentKey];
        if (Math.abs(diff) > 0.0001) {
            state[currentKey] += Math.sign(diff) * Math.min(Math.abs(diff), step);
        }
    }

    /**
     * Ежегодное обновление целей из sub_408A30.c
     */
    public static updateYearlyTargets(state: GrowthState, rng: MSVCRand): void {
        const { GROWTH } = TREE_CONSTANTS;

        // Новые цели для цвета (sub_408A30.c:36-43)
        state.targetColorR = rng.randFloat();
        state.targetColorG = rng.randFloat();
        state.targetColorB = rng.randFloat();

        // Приращение возраста (sub_408A30.c:48)
        state.targetAge += rng.randFloat() * (GROWTH.YEARLY_AGE_MAX - GROWTH.YEARLY_AGE_MIN) + GROWTH.YEARLY_AGE_MIN;

        // Новая цель толщины (sub_408A30.c:52-54)
        // v18 = sub_4153D0(...) -> в оригинале это связано с метаболизмом, но в sub_408A30:52 используется множитель 0.333
        const thicknessFactor = rng.randFloat() * 0.2000000476837158 + 0.8999999761581421;
        // В оригинале расчет сложнее, но базовый фактор приращения именно этот
        state.targetThickness *= thicknessFactor;
        
        if (state.targetThickness < GROWTH.THICKNESS_MIN) {
            state.targetThickness = GROWTH.THICKNESS_MIN;
        }

        // Новая цель изгиба (sub_408A30.c:56-57)
        const bendFactor = rng.randFloat() * 0.2000000476837158 + 0.8999999761581421;
        state.targetBend = bendFactor * (state.trunkBend + state.trunkBend);
        
        if (state.targetBend > GROWTH.BEND_LIMIT) {
            state.targetBend = GROWTH.BEND_LIMIT;
        }
    }
}
