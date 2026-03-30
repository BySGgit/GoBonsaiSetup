import * as THREE from 'three';
import { TREE_CONSTANTS } from './TreeConstants';
import { MSVCRand } from './MSVCRand';
import { TreeSection } from './TreeSection';

export class BranchingService {
    /**
     * Логика принятия решения о ветвлении из sub_408A30.c
     * Возвращает количество затраченной энергии.
     */
    public static process(section: TreeSection, energy: number, rng: MSVCRand): number {
        const { GROWTH } = TREE_CONSTANTS;
        let energyConsumed = 0;
        
        if (section.level >= GROWTH.MAX_LEVEL) return 0;

        // sub_4188E0.c: Динамическая вероятность ветвления
        // В оригинале вероятность зависит от роста толщины (v13)
        // Здесь используем упрощенную, но верную оригиналу вероятность 0.2
        const branchingProb = 0.2;
        const maxChildren = section.level === 0 ? 4 : 2;

        if (section.children.length < maxChildren && rng.randFloat() < branchingProb && energy > 0.3) {
            // sub_4188E0.c:46-47 - Углы отклонения
            // yaw (v15): rand * 2pi - pi
            // pitch (v19): rand * 1.1 - 1.6 (отрицательный pitch означает наклон "от ствола")
            const yaw = rng.randFloat() * Math.PI * 2 - Math.PI;
            const pitch = rng.randFloat() * 1.1 - 1.6;
            
            const spawnPos = 0.4 + rng.randFloat() * 0.55;
            const newBranch = section.addBranch(spawnPos);
            
            if (newBranch) {
                energyConsumed += 0.2; 
                
                // sub_4188E0.c:50 - Направление ветки (0, v19, -v15)
                // Преобразуем в кватернион
                const tempEuler = new THREE.Euler(pitch, 0, -yaw);
                newBranch.targetRotation.setFromEuler(tempEuler);
            }
        } 

        // Рекурсивный проход (sub_4188E0.c не рекурсивен сам по себе, 
        // но в движке вызывается для всей структуры)
        for (const child of section.children) {
            if (energy - energyConsumed > 0.1) {
                energyConsumed += this.process(child, energy - energyConsumed, rng);
            }
        }

        return energyConsumed;
    }
}
