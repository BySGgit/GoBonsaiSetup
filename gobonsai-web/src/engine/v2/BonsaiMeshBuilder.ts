import * as THREE from 'three';
import { BonsaiNode } from './BonsaiNode';
import { BonsaiConfig, NodeType } from './BonsaiConfig';

/**
 * BonsaiMeshBuilder — генерация меша дерева.
 * В оригинале (sub_4093B0) меш строится как единый буфер вершин
 * для всего дерева, проходя по сплайну из 3 контрольных точек.
 * 
 * Здесь мы генерируем цилиндры для каждого узла и собираем
 * их в иерархию Three.js объектов.
 */
export class BonsaiMeshBuilder {
    private static barkMaterial: THREE.MeshStandardMaterial | null = null;
    private static leafMaterial: THREE.MeshStandardMaterial | null = null;

    /**
     * Создание материала коры.
     */
    private static getBarkMaterial(): THREE.MeshStandardMaterial {
        if (!this.barkMaterial) {
            this.barkMaterial = new THREE.MeshStandardMaterial({
                color: 0x5d4037,
                roughness: 0.85,
                metalness: 0.05,
            });

            this.barkMaterial.onBeforeCompile = (shader) => {
                shader.uniforms.uTreeAgeFactor = { value: 0.0 };
                shader.vertexShader = shader.vertexShader.replace(
                    '#include <common>',
                    `#include <common>
                    varying vec3 vWorldPos;
                    uniform float uTreeAgeFactor;`
                );
                shader.vertexShader = shader.vertexShader.replace(
                    '#include <begin_vertex>',
                    `#include <begin_vertex>
                    vWorldPos = (modelMatrix * vec4(position, 1.0)).xyz;`
                );
                shader.fragmentShader = shader.fragmentShader.replace(
                    '#include <common>',
                    `#include <common>
                    varying vec3 vWorldPos;`
                );
                shader.fragmentShader = shader.fragmentShader.replace(
                    '#include <dithering_fragment>',
                    `#include <dithering_fragment>
                    float bark = sin(vWorldPos.y * 40.0) * 0.03 + sin(vWorldPos.x * 30.0 + vWorldPos.z * 30.0) * 0.02;
                    gl_FragColor.rgb += vec3(bark * 0.5, bark * 0.3, bark * 0.1);`
                );
                (this.barkMaterial as any).userData.shader = shader;
            };
        }
        return this.barkMaterial;
    }

    /**
     * Создание материала листа.
     */
    private static getLeafMaterial(): THREE.MeshStandardMaterial {
        if (!this.leafMaterial) {
            this.leafMaterial = new THREE.MeshStandardMaterial({
                color: 0x2e7d32,
                roughness: 0.4,
                side: THREE.DoubleSide,
                transparent: true,
                opacity: 0.9,
            });
        }
        return this.leafMaterial;
    }

    /**
     * Построение меша для одного узла.
     */
    public static buildNodeMesh(node: BonsaiNode): void {
        // Удаляем только Mesh-объекты, оставляя дочерние Object3D (BonsaiNode)
        const toRemove: THREE.Object3D[] = [];
        for (const child of node.object3D.children) {
            if (child instanceof THREE.Mesh) {
                toRemove.push(child);
            }
        }
        for (const obj of toRemove) {
            if (obj instanceof THREE.Mesh) obj.geometry.dispose();
            node.object3D.remove(obj);
        }

        if (node.type === NodeType.ROOT) return;

        if (node.type === NodeType.LEAF) {
            if (node.trunkRadius > 0.001) {
                const leafSize = 0.1 + node.trunkRadius * 2.0;
                const leafGeo = new THREE.PlaneGeometry(leafSize, leafSize * 1.5);
                const mat = this.getLeafMaterial().clone();
                mat.color.setHSL(0.3, 0.7, 0.3 + node.health * 0.2);
                const leafMesh = new THREE.Mesh(leafGeo, mat);
                leafMesh.castShadow = true;
                leafMesh.rotation.x = -Math.PI / 4;
                node.object3D.add(leafMesh);
            }
            return;
        }

        // STEM — цилиндрическая геометрия
        if (node.trunkRadius <= 0.001) return;

        // Радиус и длина пропорциональны trunkRadius
        const baseRadius = Math.max(0.005, node.trunkRadius * 0.15);
        const tipRadius = baseRadius * 0.7;
        const length = Math.max(0.05, node.trunkRadius * 1.5);

        const geometry = new THREE.CylinderGeometry(
            tipRadius,
            baseRadius,
            length,
            12,     // 12 сегментов для производительности (32 при финальном рендере)
            1,
            false
        );
        geometry.translate(0, length / 2, 0);

        const mesh = new THREE.Mesh(geometry, this.getBarkMaterial().clone());
        mesh.castShadow = true;
        mesh.receiveShadow = true;
        node.object3D.add(mesh);
    }

    /**
     * Рекурсивное построение мешей для всего дерева.
     */
    public static buildTree(node: BonsaiNode): void {
        this.buildNodeMesh(node);

        for (const child of node.children) {
            // Позиционируем дочерний узел на верхушке родительского
            if (node.type === NodeType.STEM) {
                const parentLength = Math.max(0.01, node.trunkRadius * 0.5);
                child.object3D.position.y = parentLength;
            }

            this.buildTree(child);
        }
    }

    /**
     * Обновление мешей при изменении параметров (каждый кадр).
     * Вместо полной перестройки — обновляем масштабы.
     */
    public static updateMeshes(node: BonsaiNode): void {
        // Применяем вращение
        node.object3D.quaternion.copy(node.currentRotation);

        // Позиционируем дочерних на верхушке
        if (node.type === NodeType.STEM && node.trunkRadius > 0.001) {
            const length = Math.max(0.05, node.trunkRadius * 1.5);
            for (const child of node.children) {
                child.object3D.position.y = length;
            }
        }

        // Видимость
        node.object3D.visible = node.health > 0;

        // Рекурсия
        for (const child of node.children) {
            this.updateMeshes(child);
        }
    }

    /**
     * Освобождение ресурсов.
     */
    public static dispose(): void {
        if (this.barkMaterial) {
            this.barkMaterial.dispose();
            this.barkMaterial = null;
        }
        if (this.leafMaterial) {
            this.leafMaterial.dispose();
            this.leafMaterial = null;
        }
    }
}
