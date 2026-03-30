import * as THREE from 'three';

export class PotService {
    /**
     * Создает процедурную геометрию горшка.
     * В оригинале было несколько типов горшков, здесь реализуем классический вариант.
     */
    public static createPot(): THREE.Group {
        const group = new THREE.Group();
        
        // Материал горшка (керамика, более темный и матовый)
        const potMaterial = new THREE.MeshStandardMaterial({ 
            color: 0x2a1a1a,
            roughness: 0.8,
            metalness: 0.1
        });

        // Плоский поддон (Tray) вместо глубокого горшка
        const potGeometry = new THREE.CylinderGeometry(1.5, 1.3, 0.2, 32);
        const pot = new THREE.Mesh(potGeometry, potMaterial);
        pot.position.y = -0.1;
        pot.castShadow = true;
        pot.receiveShadow = true;
        group.add(pot);

        // Тонкий ободок
        const rimGeometry = new THREE.TorusGeometry(1.5, 0.04, 16, 32);
        rimGeometry.rotateX(Math.PI / 2);
        const rim = new THREE.Mesh(rimGeometry, potMaterial);
        rim.position.y = 0;
        rim.castShadow = true;
        rim.receiveShadow = true;
        group.add(rim);

        return group;
    }
}
