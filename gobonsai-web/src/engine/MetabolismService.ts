import * as THREE from 'three';
import { TREE_CONSTANTS } from './TreeConstants';
import { TreeSection } from './TreeSection';

export interface MetabolismState {
    energy: number;
    health: number;
}

export class MetabolismService {
    /**
     * Логика метаболизма из sub_416510.c
     * Обновлено для 100% соответствия оригиналу, включая расчет освещенности через dot product.
     */
    public static update(
        state: MetabolismState,
        section: TreeSection, // Передаем секцию для доступа к ее ориентации
        age: number,
        lightDirection: THREE.Vector3, // Глобальный вектор направления света
        deltaTime: number
    ): string[] {
        const logs: string[] = [];
        const { METABOLISM } = TREE_CONSTANTS;

        // 1. Расчет фактора освещенности (эквивалент sub_416510.c: 58-63)
        const branchUpVector = new THREE.Vector3(0, 1, 0);
        // Применяем кватернион вращения секции, чтобы получить ее направление 'up' в мировых координатах
        branchUpVector.applyQuaternion(section.group.quaternion);

        // Скалярное произведение (dot product) между вектором ветки и направлением света
        const lightDot = branchUpVector.dot(lightDirection);
        
        // В оригинале используется fabs - абсолютное значение. Это значит, что и нижняя сторона веток поглощает свет.
        const lightFactor = Math.abs(lightDot);

        const metabolicRate = METABOLISM.ENERGY_GAIN_RATE * deltaTime;
        const prevEnergy = state.energy;
        const prevHealth = state.health;

        // 2. Фотосинтез (эквивалент sub_416510.c: 283-287)
        // Прирост энергии зависит от фактора освещенности и текущего здоровья
        const energyGain = lightFactor * state.health * metabolicRate;
        state.energy += energyGain;

        // 3. Затраты на поддержание структуры (эквивалент sub_416510.c:295)
        const maintenanceCost = METABOLISM.MAINTENANCE_COST_BASE * (age / 10.0 + 1.0) * deltaTime;
        state.energy -= maintenanceCost;

        // 4. Увядание при недостатке энергии (эквивалент sub_416510.c: 299-301)
        if (state.energy < METABOLISM.CRITICAL_ENERGY) {
            const decayFactor = 1.0 - (state.energy / METABOLISM.CRITICAL_ENERGY);
            state.health -= METABOLISM.HEALTH_DECAY_RATE * decayFactor * deltaTime;
            
            if (prevHealth >= 0.3 && state.health < 0.3) {
                logs.push("Дерево увядает! Нужен свет и уход.");
            }
        } else if (state.energy > 0.6 && state.health < 1.0) {
            // 5. Восстановление здоровья (эквивалент sub_416510.c: 306-308)
            state.health += METABOLISM.HEALTH_DECAY_RATE * deltaTime;
        }

        if (prevEnergy > METABOLISM.CRITICAL_ENERGY && state.energy <= METABOLISM.CRITICAL_ENERGY) {
            logs.push("Критически низкая энергия");
        }

        state.energy = Math.max(0, Math.min(1.0, state.energy));
        state.health = Math.max(0, Math.min(1.0, state.health));

        return logs;
    }
}
