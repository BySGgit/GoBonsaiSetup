import * as THREE from 'three';
import { MSVCRand } from './MSVCRand';
import { TREE_CONSTANTS } from './TreeConstants';

const LEAF_VISUAL_SCALE = 2.2;
const LEAF_ALPHA_CUTOFF = 0.35;
const LEAF_BASE_WIDTH = 0.22;
const LEAF_BASE_HEIGHT = 0.28;

export class TreeLeaf {
    private static sharedGeometry: THREE.PlaneGeometry | null = null;
    private static sharedTexture: THREE.CanvasTexture | null = null;

    public mesh: THREE.Mesh;
    public energy: number = 1.0;
    public health: number = 1.0;
    public size: number = 0.0;
    public targetSize: number = 0.25;
    private isDead: boolean = false;
    private isFalling: boolean = false;
    private velocity: THREE.Vector3 = new THREE.Vector3();
    private rotationVelocity: THREE.Vector3 = new THREE.Vector3();
    private rng: MSVCRand;
    private swayOffset: number;

    private static getSharedGeometry(): THREE.PlaneGeometry {
        if (!TreeLeaf.sharedGeometry) {
            TreeLeaf.sharedGeometry = new THREE.PlaneGeometry(
                LEAF_BASE_WIDTH,
                LEAF_BASE_HEIGHT,
                1,
                4,
            );
            TreeLeaf.sharedGeometry.translate(0, LEAF_BASE_HEIGHT * 0.5, 0);
            TreeLeaf.sharedGeometry.rotateY(Math.PI * 0.5);
        }
        return TreeLeaf.sharedGeometry;
    }

    private static getSharedTexture(): THREE.CanvasTexture {
        if (TreeLeaf.sharedTexture) return TreeLeaf.sharedTexture;

        const size = 128;
        const canvas = document.createElement('canvas');
        canvas.width = size;
        canvas.height = size;
        const ctx = canvas.getContext('2d');
        if (!ctx) {
            const fallback = new THREE.CanvasTexture(canvas);
            TreeLeaf.sharedTexture = fallback;
            return fallback;
        }

        ctx.clearRect(0, 0, size, size);
        ctx.save();
        ctx.translate(size * 0.5, size * 0.05);
        ctx.beginPath();
        ctx.moveTo(0, 0);
        ctx.bezierCurveTo(size * 0.24, size * 0.30, size * 0.20, size * 0.65, 0, size * 0.9);
        ctx.bezierCurveTo(-size * 0.20, size * 0.65, -size * 0.24, size * 0.30, 0, 0);
        ctx.closePath();
        const grad = ctx.createLinearGradient(0, 0, 0, size * 0.9);
        grad.addColorStop(0, 'rgba(140,220,120,0.92)');
        grad.addColorStop(1, 'rgba(40,120,45,1.0)');
        ctx.fillStyle = grad;
        ctx.fill();
        ctx.restore();

        const tex = new THREE.CanvasTexture(canvas);
        tex.colorSpace = THREE.SRGBColorSpace;
        tex.needsUpdate = true;
        TreeLeaf.sharedTexture = tex;
        return tex;
    }

    constructor(parentGroup: THREE.Group, rng: MSVCRand) {
        this.rng = rng;
        this.swayOffset = this.rng.randFloat() * Math.PI * 2;

        const geometry = TreeLeaf.getSharedGeometry();
        const leafTex = TreeLeaf.getSharedTexture();

        const material = new THREE.MeshStandardMaterial({
            color: 0x2e7d32,
            map: leafTex,
            alphaMap: leafTex,
            alphaTest: LEAF_ALPHA_CUTOFF,
            side: THREE.DoubleSide,
            transparent: true,
            opacity: 0,
            roughness: 0.35,
            metalness: 0,
            emissive: 0x143306,
            emissiveIntensity: 0.35,
        });

        material.onBeforeCompile = (shader) => {
            shader.uniforms.uLeafTime = { value: 0 };
            shader.uniforms.uLeafBend = { value: 0 };
            shader.vertexShader = shader.vertexShader
                .replace(
                    '#include <common>',
                    '#include <common>\nuniform float uLeafTime;\nuniform float uLeafBend;\nvarying vec2 vLeafUv;',
                )
                .replace(
                    '#include <begin_vertex>',
                    '#include <begin_vertex>\n' +
                        'vLeafUv = uv;\n' +
                        'float edge = (1.0 - uv.y);\n' +
                        'float bendWave = sin(uLeafTime * 2.0 + uv.y * 6.2831) * uLeafBend * edge;\n' +
                        'transformed.x += bendWave * 0.08;\n' +
                        'transformed.z += bendWave * 0.04;',
                );
            shader.fragmentShader = shader.fragmentShader
                .replace('#include <common>', '#include <common>\nvarying vec2 vLeafUv;')
                .replace(
                    '#include <dithering_fragment>',
                    '#include <dithering_fragment>\nfloat vein = smoothstep(0.88, 1.0, abs(sin(vLeafUv.y * 30.0)));\ngl_FragColor.rgb += vec3(vein * 0.05);',
                );
            material.userData.shader = shader;
        };

        this.mesh = new THREE.Mesh(geometry, material);
        this.mesh.castShadow = true;
        this.mesh.receiveShadow = false;
        this.mesh.position.set(
            (this.rng.randFloat() - 0.5) * 0.2,
            0.5,
            (this.rng.randFloat() - 0.5) * 0.2,
        );
        this.mesh.rotation.set(
            this.rng.randFloat() * Math.PI,
            this.rng.randFloat() * Math.PI,
            0,
        );
        this.mesh.scale.set(0, 0, 0);

        parentGroup.add(this.mesh);
    }

    update(
        lightIntensity: number,
        globalGrowthFactor: number,
        globalHealth: number,
        wind: THREE.Vector3,
        dayOfYear: number,
        deltaTime: number,
        strictExeSimVisuals: boolean = false,
    ): void {
        const { METABOLISM } = TREE_CONSTANTS;
        const leafMat = this.mesh.material as THREE.MeshStandardMaterial;

        if (this.isDead || this.isFalling) {
            this.velocity.y -= 0.1 * deltaTime;
            this.velocity.x += ((this.rng.randFloat() - 0.5) * 0.05 + wind.x * 0.05) * deltaTime;
            this.velocity.z += ((this.rng.randFloat() - 0.5) * 0.05 + wind.z * 0.05) * deltaTime;

            this.mesh.position.add(this.velocity);
            this.mesh.rotation.x += this.rotationVelocity.x * deltaTime * 60;
            this.mesh.rotation.y += this.rotationVelocity.y * deltaTime * 60;

            const worldPos = new THREE.Vector3();
            this.mesh.getWorldPosition(worldPos);

            if (worldPos.y < 0) {
                this.velocity.set(0, 0, 0);
                this.rotationVelocity.set(0, 0, 0);
                leafMat.opacity -= 0.3 * deltaTime;
                if (leafMat.opacity <= 0) {
                    this.mesh.visible = false;
                    this.isDead = true;
                }
            } else {
                leafMat.opacity -= 0.05 * deltaTime;
            }
            return;
        }

        if (!strictExeSimVisuals) {
            const time = Date.now() * 0.002;
            const swayAmp = wind.length() * 0.2 + 0.1;
            this.mesh.rotation.z = Math.sin(time + this.swayOffset) * swayAmp;
            this.mesh.rotation.x = Math.cos(time * 0.8 + this.swayOffset) * (swayAmp * 0.55);
            const shader = leafMat.userData?.shader;
            if (shader?.uniforms) {
                shader.uniforms.uLeafTime.value = time + this.swayOffset;
                shader.uniforms.uLeafBend.value = swayAmp * this.energy;
            }
        } else {
            const shader = leafMat.userData?.shader;
            if (shader?.uniforms) {
                shader.uniforms.uLeafBend.value = 0;
            }
        }

        if (lightIntensity <= METABOLISM.LIGHT_THRESHOLD) {
            this.energy -= 0.0005 * deltaTime * 60;
        } else {
            this.energy += 0.001 * lightIntensity * deltaTime * 60;
        }

        if (globalHealth < 0.3) this.energy -= 0.002 * deltaTime * 60;
        this.energy = Math.max(0, Math.min(1.0, this.energy));

        if ((this.energy <= 0 && this.rng.randFloat() < 0.01) || (globalHealth < 0.2 && this.rng.randFloat() < 0.005)) {
            this.startFalling();
        }

        if (this.energy > 0.4 && this.size < this.targetSize) {
            this.size += 0.12 * globalGrowthFactor * deltaTime;
        }

        const s = Math.max(0, this.size) * LEAF_VISUAL_SCALE;
        this.mesh.scale.set(s, s, s);

        const targetOpacity = this.energy * 0.95;
        const lerpFactor = 1.0 - Math.pow(0.1, deltaTime);
        leafMat.opacity += (targetOpacity - leafMat.opacity) * lerpFactor;

        let hue = 0.25 + this.energy * 0.1;
        let saturation = 0.6;
        let lightness = 0.2 + this.energy * 0.3;

        if (dayOfYear > 250 && dayOfYear < 320) {
            const autumnFactor = (dayOfYear - 250) / 70;
            hue = 0.25 - autumnFactor * 0.2;
            saturation += autumnFactor * 0.2;
        } else if (dayOfYear >= 320 || dayOfYear < 60) {
            saturation *= 0.5;
            lightness *= 0.8;
        }

        leafMat.color.setHSL(hue, saturation, lightness);
        leafMat.emissiveIntensity = this.energy * 0.5;
    }

    private startFalling(): void {
        if (this.isFalling) return;
        this.isFalling = true;
        this.velocity.set((this.rng.randFloat() - 0.5) * 0.02, 0, (this.rng.randFloat() - 0.5) * 0.02);
        this.rotationVelocity.set(this.rng.randFloat() * 0.1, this.rng.randFloat() * 0.1, this.rng.randFloat() * 0.05);
    }
}
