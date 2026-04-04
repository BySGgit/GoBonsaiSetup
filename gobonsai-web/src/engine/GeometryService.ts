import * as THREE from 'three';
import { TREE_CONSTANTS } from './TreeConstants';
import { MSVCRand } from './MSVCRand';

export class GeometryService {
    /**
     * Создает меш сегмента ветки на основе параметров из sub_4093B0.c
     */
    public static createBranchSegment(
        radiusTop: number,
        radiusBottom: number,
        height: number,
        level: number,
        rng: MSVCRand,
        tBottom: number = 0,
        tTop: number = 1,
        openEnded: boolean = true
    ): THREE.Mesh {
        const { GEOMETRY } = TREE_CONSTANTS;
        const geometry = new THREE.CylinderGeometry(
            radiusTop,
            radiusBottom,
            height,
            GEOMETRY.RADIAL_SEGMENTS,
            1,
            openEnded
        );
        geometry.translate(0, height / 2, 0);

        // sub_4093B0.c: Custom UV mapping (Concentric projection)
        // The original game maps UVs as a circle: U = sin(angle)*scale + 0.5, V = cos(angle)*scale + 0.5
        // where scale decreases along the length of the branch.
        const positionAttribute = geometry.attributes.position;
        const uvAttribute = geometry.attributes.uv;
        
        for (let i = 0; i < positionAttribute.count; i++) {
            const x = positionAttribute.getX(i);
            const y = positionAttribute.getY(i);
            const z = positionAttribute.getZ(i);
            
            // Local t within this cylinder segment (0 at bottom, 1 at top)
            const localT = y / height;
            // Global t along the entire branch section
            const globalT = tBottom + localT * (tTop - tBottom);
            
            // Calculate angle around the Y axis
            const angle = Math.atan2(x, z);
            
            // Scale factor (v50 in C code) decreases as we go up the branch
            const scale = (1.0 - globalT) * 0.5; 
            
            const u = Math.sin(angle) * scale + 0.5;
            const v = Math.cos(angle) * scale + 0.5;
            
            uvAttribute.setXY(i, u, v);
        }

        const material = new THREE.MeshStandardMaterial({
            color: 0x5d4037,
            roughness: 0.9,
            metalness: 0.05
        });

        this.applyTreeShader(material);

        const mesh = new THREE.Mesh(geometry, material);
        
        // В оригинальном sub_4093B0.c нет случайных поворотов или смещений сегментов.
        // Геометрия строится строго по точкам сплайна.
        mesh.rotation.z = 0;
        mesh.rotation.x = 0;
        mesh.position.x = 0;
        mesh.position.z = 0;

        mesh.castShadow = true;
        mesh.receiveShadow = true;

        return mesh;
    }

    /**
     * Создает срез ветки с годовыми кольцами
     */
    public static createCutCap(radius: number): THREE.Mesh {
        const geometry = new THREE.CircleGeometry(radius, 32);
        const material = new THREE.MeshStandardMaterial({
            color: 0xdbcbb0,
            roughness: 0.8
        });

        this.applyCapShader(material, radius);

        const mesh = new THREE.Mesh(geometry, material);
        mesh.rotation.x = -Math.PI / 2;
        return mesh;
    }

    private static applyTreeShader(material: THREE.MeshStandardMaterial): void {
        material.onBeforeCompile = (shader) => {
            shader.uniforms.uTreeAgeFactor = { value: 0 };
            shader.vertexShader = shader.vertexShader.replace('#include <common>', '#include <common>\nvarying vec3 vTreePos;');
            shader.vertexShader = shader.vertexShader.replace('#include <begin_vertex>', '#include <begin_vertex>\nvTreePos = position;');
            shader.fragmentShader = shader.fragmentShader.replace('#include <common>', '#include <common>\nuniform float uTreeAgeFactor;\nvarying vec3 vTreePos;');
            shader.fragmentShader = shader.fragmentShader.replace('#include <normal_fragment_begin>', '#include <normal_fragment_begin>\nfloat n = sin(vTreePos.y * 100.0) * sin(vTreePos.x * 20.0 + vTreePos.z * 20.0);\nfloat cracks = pow(abs(sin(vTreePos.y * 10.0 + vTreePos.x * 5.0)), 10.0) * 0.5 * uTreeAgeFactor;\nnormal = normalize(normal + vec3(n * 0.1 * uTreeAgeFactor + cracks, 0.0, n * 0.1 * uTreeAgeFactor));');
            shader.fragmentShader = shader.fragmentShader.replace('#include <color_fragment>', '#include <color_fragment>\nfloat mossNoise = sin(vTreePos.y * 20.0) * cos(vTreePos.x * 15.0) * sin(vTreePos.z * 15.0);\nfloat mossMask = smoothstep(0.2, 0.5, mossNoise) * smoothstep(0.8, 0.2, vTreePos.y * 0.5);\nvec3 mossColor = vec3(0.22, 0.28, 0.14);\ndiffuseColor.rgb = mix(diffuseColor.rgb, mossColor, mossMask * 0.38 * smoothstep(0.2, 1.0, uTreeAgeFactor));');
            material.userData.shader = shader;
        };
    }

    private static applyCapShader(material: THREE.MeshStandardMaterial, radius: number): void {
        material.onBeforeCompile = (shader) => {
            shader.uniforms.uRadius = { value: radius };
            shader.vertexShader = shader.vertexShader.replace('#include <common>', '#include <common>\nvarying vec3 vCapPos;');
            shader.vertexShader = shader.vertexShader.replace('#include <begin_vertex>', '#include <begin_vertex>\nvCapPos = position;');
            shader.fragmentShader = shader.fragmentShader.replace('#include <common>', '#include <common>\nuniform float uRadius;\nvarying vec3 vCapPos;');
            shader.fragmentShader = shader.fragmentShader.replace('#include <color_fragment>', `
                #include <color_fragment>
                float dist = length(vCapPos.xy);
                float ring = sin(dist * 200.0);
                float dark = smoothstep(-0.2, 0.2, ring);
                diffuseColor.rgb = mix(diffuseColor.rgb * 0.7, diffuseColor.rgb, dark);
                float angle = atan(vCapPos.y, vCapPos.x);
                float crack = pow(abs(sin(angle * 4.0)), 100.0) * 0.4;
                diffuseColor.rgb -= crack;
            `);
        };
    }
}
