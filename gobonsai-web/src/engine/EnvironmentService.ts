import * as THREE from 'three';

export class EnvironmentService {
    /**
     * Создает холмик земли (Soil Mound) с процедурным рельефом.
     */
    public static createSoilMound(): THREE.Mesh {
        const moundGeometry = new THREE.SphereGeometry(2.1, 36, 24, 0, Math.PI * 2, 0, Math.PI / 2);
        moundGeometry.scale(1, 0.22, 1);
        
        const posAttr = moundGeometry.attributes.position;
        for (let i = 0; i < posAttr.count; i++) {
            const y = posAttr.getY(i);
            if (y > 0) {
                const x = posAttr.getX(i);
                const z = posAttr.getZ(i);
                // Оригинальный рельеф почвы (sub_4093B0)
                const noise = (Math.sin(x * 6.0) * Math.cos(z * 6.0) + Math.sin(z * 10.0)) * 0.05;
                posAttr.setY(i, y + noise);
            }
        }
        moundGeometry.computeVertexNormals();

        const soilMaterial = new THREE.MeshStandardMaterial({ 
            color: 0x241411,
            roughness: 1.0,
            metalness: 0.0
        });
        
        const mound = new THREE.Mesh(moundGeometry, soilMaterial);
        mound.position.y = -0.08;
        mound.receiveShadow = true;
        return mound;
    }

    /**
     * Создает группу случайных камней вокруг дерева.
     */
    public static createStones(count: number = 5): THREE.Group {
        const group = new THREE.Group();
        const stoneMat = new THREE.MeshStandardMaterial({ 
            color: 0x666666,
            roughness: 0.9
        });

        for (let i = 0; i < count; i++) {
            const stoneSize = 0.08 + Math.random() * 0.14;
            const stoneGeo = new THREE.DodecahedronGeometry(stoneSize, 0);
            const stone = new THREE.Mesh(stoneGeo, stoneMat);
            
            const angle = Math.random() * Math.PI * 2;
            const dist = 0.8 + Math.random() * 1.1;
            stone.position.set(
                Math.cos(angle) * dist,
                -0.02,
                Math.sin(angle) * dist
            );
            stone.rotation.set(Math.random(), Math.random(), Math.random());
            stone.castShadow = true;
            stone.receiveShadow = true;
            group.add(stone);
        }
        return group;
    }

    /**
     * Создает основание (пол/стол).
     */
    public static createFloor(): THREE.Mesh {
        const floorGeometry = new THREE.PlaneGeometry(20, 20);
        const floorMaterial = new THREE.MeshStandardMaterial({ 
            color: 0x080808,
            roughness: 0.8,
            metalness: 0.1
        });
        const floor = new THREE.Mesh(floorGeometry, floorMaterial);
        floor.rotation.x = -Math.PI / 2;
        floor.position.y = -0.8;
        floor.receiveShadow = true;
        return floor;
    }
}
