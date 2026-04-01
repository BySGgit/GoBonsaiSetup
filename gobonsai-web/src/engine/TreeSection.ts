import * as THREE from "three";
import { TreeLeaf } from "./TreeLeaf";
import { TreeFlower } from "./TreeFlower";
import { MSVCRand } from "./MSVCRand";
import { TREE_CONSTANTS } from "./TreeConstants";
import { GeometryService } from "./GeometryService";
import { TreeTrunkParams } from "./TreeState";
import {
  ITreeSectionData,
  IVisualState,
  ITransformState,
  IWorkingBuffers,
} from "./TreeInterfaces";
import {
  Float32,
  D3DXQUATERNION,
  D3DXMATRIX,
  D3DXVECTOR3,
} from "./math/MathTypes";

import { TransformService } from "./math/TransformService";
import { Sub416510Rotation } from "./math/Sub416510Rotation";
import { SectionRuntimeType } from "./SectionRuntimeType";

/** Debug: show wireframe skeleton instead of solid meshes */
export let DEBUG_WIREFRAME = false;
export function setDebugWireframe(on: boolean): void {
  DEBUG_WIREFRAME = on;
}

export class TreeSection
  implements ITreeSectionData, IVisualState, ITransformState, IWorkingBuffers
{
  public parent: TreeSection | null;
  public level: number;
  public children: TreeSection[] = [];
  public leaves: TreeLeaf[] = [];
  public flowers: TreeFlower[] = [];

  public currentBranchScale: Float32 = 0.0;
  public branchPosition: Float32 = 1.0;
  public branchBaseRadius: Float32;
  public branchTipRadius: Float32;

  // ITransformState
  public rotationQuaternion: D3DXQUATERNION = new THREE.Quaternion(); // this + 320
  public transformMatrix: D3DXMATRIX = new THREE.Matrix4(); // this + 352

  public rotation: D3DXQUATERNION = new THREE.Quaternion(); // Alias for rotationQuaternion
  public targetRotation: D3DXQUATERNION = new THREE.Quaternion();
  private currentEuler: THREE.Euler = new THREE.Euler();
  private targetEuler: THREE.Euler = new THREE.Euler();
  public sway: THREE.Vector3 = new THREE.Vector3(0, 0, 0);

  public hasWire: boolean = false;
  public isPruned: boolean = false;

  // ITreeSectionData (from C offsets)
  public prevData0: number = 0; // this + 76
  public prevData1: number = 0; // this + 77
  public prevData2: number = 0; // this + 78
  public prevData3: number = 0; // this + 79
  /** sub_416510 «рабочие» DWORD кватерниона (+80..+83), копируются в prevData перед slerp */
  public quaternionBlob80u0: number = 0;
  public quaternionBlob80u1: number = 0;
  public quaternionBlob80u2: number = 0;
  public quaternionBlob80u3: number = 0;
  public baseGrowth: Float32 = 1.0; // this + 108
  public currentGrowth: Float32 = 0.0; // this + 109
  public age: Float32 = 0.0; // this + 110
  public growthRate: Float32 = 0.0; // this + 111
  public growthTarget: Float32 = 0.0; // this + 112
  public maxGrowth: Float32 = 5.0; // this + 113 (reduced for smoother multi-segment growth)
  public energy: Float32 = 1.0; // this + 114

  /** this+420 — накопление «production» за кадр (агрегат как в sub_414E10 / sub_40DC90) */
  public energyProduction420: Float32 = 0;
  /** this+432 — энергетический бюджет, выставляется до слота +36 (sub_40DC90) */
  public energyBudget432: Float32 = 0;
  /** this+436 — расход за кадр; на корне — сумма по поддереву после sub_414E10 */
  public energySpent436: Float32 = 0;
  /** this+428 — вес доли parent+432 у ребёнка (sub_414E10); синхронизируется из геометрии */
  public energyWeight428: Float32 = 1.0;
  /** this+188 — «отцеплен» от иерархии роста; sub_414E10 пропускает узел */
  public worldDetached188: boolean = false;

  /** this+424 — накопительный интеграл +420 (sub_414E10: += this+420 каждый кадр) */
  public energyAccumulator424: Float32 = 0;
  /** this+440 — счётчик проходов sub_414E10 (sub_414E10: += 1.0 на узел за кадр) */
  public energyTickCounter440: Float32 = 0;
  /**
   * После sub_40DC90 на границе года: *(root+428)=1.0 (отдельно от веса child+432 в sub_414E10).
   * Используется как семя годового бюджета; полная семантика C — см. sub_414CE0 + тип секции.
   */
  public sub414CE0SeedBudget428: Float32 = 0;

  /** this+444 — радиус ветки (sub_417C90, sub_4188E0; матрицы в sub_418F10) */
  public twigRadius444: Float32 = 0;
  /** this+448 — длина/масштаб сегмента (sub_418BD0, sub_418F10) */
  public twigLength448: Float32 = 0;
  /** this+36 — скаляр толщины: max(+444, +448*0.5) в хвосте sub_414E10 */
  public meshScalar36: Float32 = 0;

  /**
   * this+4 — класс/тип секции в exe (`*(_DWORD *)(this+4)` для byte_4D8229/822A и др.).
   * Пока 0 у всех узлов; задать при появлении Seed/Bud/Twig/Leaf как в rdata.
   */
  /** По умолчанию базовая секция (5); корень перезаписывается на Seed (8). */
  public sectionRuntimeType4: number = SectionRuntimeType.TreeSection;
  /**
   * this+512 — множитель к parent+428 в sub_414CE0 при byte_4D8229 (см. v2/BonsaiNode pruneRatio).
   */
  public ce512EnergyAllowanceScale: Float32 = 1.0;

  /** this+480 — DWORD: lateral spawn (sub_4188E0 ++); в sub_414E10 суммируется с детьми */
  public rollupDword480: number = 0;
  /** this+484 — DWORD: тик twig (sub_417C90 ++); в sub_414E10 суммируется с детьми +1 на внутреннем узле */
  public rollupDword484: number = 0;
  /** Кадровый вклад в +480 при sub_4188E0 (не сериализуется — обнуляется каждый кадр) */
  public spawnDelta480: number = 0;

  /** this+512 — byte flag: true = length growing (sub_418BD0), false = branching (sub_417F40) */
  public growthFlag512: boolean = true;
  /** this+456 — smoothed health energy (sub_417C90: += (prod/20 - this)*0.1) */
  public healthEnergy456: Float32 = 0.5;
  /** this+516 — leaf count (sub_415AB0 increments) */
  public leafCount516: number = 0;
  /** this+236 — marked for detach (vtable slot +44 → sub_40EEE0) */
  public markedForDetach236: boolean = false;
  /** Bud: accumulated leaf spawn angle (sub_415AB0 uses this+512 as float on bud) */
  public leafSpawnAngle: number = 0;

  // ─── Light tracing fields (sub_40E460 / sub_4143E0) ─────────────
  /** this+196..+204 — light response direction (updated by ray-march sub_40E460) */
  public lightResponseVec: THREE.Vector3 = new THREE.Vector3(0, 1, 0);
  /** this+208 — smoothed scalar: (dot*intensity + old*10)/11 from sub_40E460 */
  public smoothedLightA: Float32 = 0.1;
  /** this+212 — smoothed scalar: (intensity + old*20)/21 from sub_40E460 */
  public smoothedLightB: Float32 = 0.1;
  /** this+216..+224 — previous direction, slerps toward +196 in sub_4143E0 */
  public prevDirectionVec: THREE.Vector3 = new THREE.Vector3(0, 1, 0);
  /** this+228 — slow copy of +208 (coeff 0.1) from sub_4143E0 */
  public smoothTargetA: Float32 = 0.1;
  /** this+232 — slow copy of +212 (coeff 0.1) from sub_4143E0 */
  public smoothTargetB: Float32 = 0.1;

  // ─── Physics fields (sub_414870 / sub_414A70 / sub_414BB0) ──────
  /** this+460 — total weight of subtree (mass + children) */
  public totalWeight460: number = 0;
  /** this+464 — stored mass of this section alone */
  public storedMass464: number = 0;
  /** this+468..+476 — center of mass in local coords */
  public centroid468: THREE.Vector3 = new THREE.Vector3(0, 0, 0);

  // ─── World object fields (sub_40F140) ───────────────────────────
  /** this+488..+496 — linear velocity for detached sections */
  public velocity488: THREE.Vector3 = new THREE.Vector3(0, 0, 0);
  /** this+500..+508 — angular velocity for detached sections */
  public angularVelocity500: THREE.Vector3 = new THREE.Vector3(0, 0, 0);

  /** sub_416510 v34 — отклик секции на свет (0..1), обновляется метаболизмом */
  public lastLightFactor: Float32 = 1.0;
  /** sub_416510 *((float*)this+52) — множитель в v34 (синхронизируется с baseGrowth в росте) */
  public metabolismLightScale: Float32 = 1.0;
  /** sub_416510 *((float*)this+53) — в формуле v34 умножается на 0.5 */
  public metabolismLightOffset: Float32 = 0.5;
  /** sub_416510.c:286–287 — вспомогательные накопления (this+105 / +106) */
  public growthScratchA: Float32 = 0;
  public growthScratchB: Float32 = 0;
  /** sub_416510.c:161 — пропуск прироста на этот кадр */
  public skipGrowthTick: boolean = false;

  public isContinuation: boolean = false;

  // IVisualState (from C offsets) — стартовая тёплая кора (до первого кадра роста)
  public colorR: Float32 = 0.45; // this + 128
  public colorG: Float32 = 0.3; // this + 129
  public colorB: Float32 = 0.19; // this + 130
  public colorA: Float32 = 1.0; // this + 131

  // IWorkingBuffers (from C offsets)
  public intermediateVector: D3DXVECTOR3 = new THREE.Vector3(); // this + 35..37
  public scaleFactor: Float32 = 1.0; // this + 41
  public rotationAxis: D3DXVECTOR3 = new THREE.Vector3(); // this + 46
  public normalizedVector: D3DXVECTOR3 = new THREE.Vector3(); // this + 50
  public directionVector: D3DXVECTOR3 = new THREE.Vector3(); // this + 51[0..2]

  public group: THREE.Group = new THREE.Group();
  public mesh: THREE.Group;

  private wireMesh: THREE.Group | null = null;
  private cutCap: THREE.Mesh | null = null;
  private rng: MSVCRand;

  constructor(
    parent: TreeSection | null = null,
    level: number = 0,
    rng: MSVCRand,
    overrideBaseRadius?: number,
  ) {
    this.parent = parent;
    this.level = level;
    this.rng = rng;

    const { GEOMETRY } = TREE_CONSTANTS;

    this.group.userData = { isTreeSection: true, level, controller: this };

    // Initialize rotations to identity. Specific angles are set by addBranch or root init.
    this.targetRotation.identity();
    this.rotationQuaternion.identity();
    this.rotation.identity();

    this.mesh = new THREE.Group();
    this.group.add(this.mesh);

    // Радиус и сужение (sub_4093B0.c)
    this.branchBaseRadius =
      overrideBaseRadius ??
      GEOMETRY.BASE_RADIUS_FACTOR * Math.pow(GEOMETRY.RADIUS_DECAY, level);
    this.branchTipRadius =
      this.branchBaseRadius *
      (level === 0 ? GEOMETRY.TAPER_ROOT : GEOMETRY.TAPER_BRANCH);

    this.twigRadius444 = this.branchBaseRadius;
    this.twigLength448 = GEOMETRY.HEIGHT_FACTOR as Float32;

    // HEIGHT_FACTOR
    const sectionHeight = GEOMETRY.HEIGHT_FACTOR;

    // sub_4093B0.c generates a single frustum (cylinder) per section with 32 radial segments
    // The outer loop in C (v46 < 2) processes exactly 2 rings: bottom and top.
    const segmentMesh = GeometryService.createBranchSegment(
      this.branchTipRadius,
      this.branchBaseRadius,
      sectionHeight,
      level,
      this.rng,
      0.0,
      1.0,
    );

    segmentMesh.userData = {
      isSegment: true,
      segmentIndex: 0,
      parentSection: this,
    };
    this.mesh.add(segmentMesh);

    if (parent) parent.group.add(this.group);
    Sub416510Rotation.initBlob80Identity(this);
  }

  /**
   * sub_4159C0 + sub_417440.c — первая почка на семени (без полной геометрии sub_416030).
   * Углы как в C: v5[0], v5[2] ∈ [-0.08, 0.08], v5[1]=0.
   */
  public static createBudFromSeed(
    parent: TreeSection,
    rng: MSVCRand,
    yawJitter: number,
    rollJitter: number,
  ): TreeSection {
    const bud = new TreeSection(
      parent,
      parent.level + 1,
      rng,
      0.01,
    );
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.twigRadius444 = 0.01 as Float32;
    bud.twigLength448 =
      (TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR * 0.12) as Float32;
    bud.energyWeight428 = 1.0 as Float32;
    bud.sub414CE0SeedBudget428 = 1.0 as Float32;
    TransformService.rotationYawPitchRoll(
      bud.targetRotation,
      yawJitter,
      0,
      rollJitter,
    );
    bud.rotationQuaternion.copy(bud.targetRotation);
    bud.rotation.copy(bud.targetRotation);
    Sub416510Rotation.syncBlob80FromQuaternion(bud);
    parent.children.push(bud);
    bud.updateAttachmentPosition(parent);
    return bud;
  }

  /** После updateMatrixWorld: this+352 для следующего кадра sub_401540(this+352). */
  public static syncTransformMatricesFromWorld(root: TreeSection): void {
    const stack: TreeSection[] = [root];
    while (stack.length) {
      const s = stack.pop()!;
      s.transformMatrix.copy(s.group.matrixWorld);
      for (let i = s.children.length - 1; i >= 0; i--)
        stack.push(s.children[i]);
    }
  }

  public getRadiusAt(t: number): number {
    // sub_4093B0.c:127 - Линейное затухание радиуса от основания к вершине
    // В оригинале затухание идет по всей длине структуры, здесь аппроксимируем для секции
    const baseRadius = this.branchBaseRadius;
    const tipRadius = this.branchTipRadius;
    return baseRadius * (1.0 - t) + tipRadius * t;
  }

  /** Позиция дочерней секции вдоль локальной оси Y родителя (sub_415C10 / иерархия сцены). */
  public updateAttachmentPosition(parent: TreeSection): void {
    const { GEOMETRY } = TREE_CONSTANTS;
    // Match the visual top of the parent mesh: base height * mesh scaleY.
    // parent.mesh.scale.y is set in update() BEFORE children call this.
    const visualHeight = GEOMETRY.HEIGHT_FACTOR * parent.mesh.scale.y;
    this.group.position.y = (this.branchPosition as number) * visualHeight;
  }

  public update(
    ageFactor: number,
    lightIntensity: number,
    trunkParams: TreeTrunkParams,
    globalHealth: number,
    wind: THREE.Vector3,
    dayOfYear: number,
    deltaTime: number,
  ): void {
    const { ANIMATION } = TREE_CONSTANTS;

    this.mesh.children.forEach((child) => {
      if (
        child instanceof THREE.Mesh &&
        child.material instanceof THREE.MeshStandardMaterial
      ) {
        if (child.material.userData.shader) {
          child.material.userData.shader.uniforms.uTreeAgeFactor.value =
            ageFactor;
        }
      }
    });

    Sub416510Rotation.apply(
      this,
      trunkParams.bend,
      this.lastLightFactor,
      deltaTime,
    );

    const stabilityFactor = Math.pow(4.0, 6 - this.level);
    const swayFactor =
      (0.002 + (1.0 - globalHealth) * 0.005) *
      (wind.length() / stabilityFactor);
    const swayX =
      Math.sin(Date.now() * 0.0005 + this.level) * wind.x * swayFactor;
    const swayZ =
      Math.cos(Date.now() * 0.0006 + this.level) * wind.z * swayFactor;

    this.group.quaternion.copy(this.rotationQuaternion);
    this.group.rotateX(swayX);
    this.group.rotateZ(swayZ);

    const { GEOMETRY } = TREE_CONSTANTS;

    // Height: prefer C-truth twigLength448 when available, fall back to growthRate-based
    const baseHeight = GEOMETRY.HEIGHT_FACTOR;
    const twigLen = this.twigLength448 as number;
    let currentHeightScale: number;
    if (twigLen > 0.001 && twigLen !== baseHeight) {
      // Section length was set by C-parity growth engine
      currentHeightScale = Math.max(0.05, twigLen / baseHeight);
    } else {
      // Legacy path: length from growthRate progress
      const growthProgress = this.maxGrowth > 0
        ? Math.min(1.0, this.growthRate / this.maxGrowth) : 1.0;
      const hasContinuation = this.children.some((c) => c.isContinuation);
      currentHeightScale = hasContinuation ? 1.0 : Math.max(0.01, growthProgress);
      // Root/initial sections: always show full height
      if (twigLen >= baseHeight - 0.01) currentHeightScale = 1.0;
    }

    // Radius: trunkParams.thickness is the global visual scale (from stats, ~10).
    // templateRadius gives per-level taper. Divide by branchBaseRadius to normalize.
    const templateRadius =
      GEOMETRY.BASE_RADIUS_FACTOR *
      Math.pow(GEOMETRY.RADIUS_DECAY, this.level);
    const radScale =
      (trunkParams.thickness * templateRadius) /
      Math.max(1e-6, this.branchBaseRadius as number);

    if (trunkParams.thickness > 0.01) {
      this.mesh.scale.set(radScale, currentHeightScale, radScale);
      this.group.visible = true;

      if (this.wireMesh)
        this.wireMesh.scale.set(radScale, currentHeightScale, radScale);

      this.children.forEach((child) => child.updateAttachmentPosition(this));
    } else {
      this.group.visible = false;
    }

    const tw = 0.82;
    const tr = Math.min(
      1,
      Math.max(0, this.colorR * (tw + (1 - tw) * trunkParams.color.r)),
    );
    const tg = Math.min(
      1,
      Math.max(0, this.colorG * (tw + (1 - tw) * trunkParams.color.g)),
    );
    const tb = Math.min(
      1,
      Math.max(0, this.colorB * (tw + (1 - tw) * trunkParams.color.b)),
    );

    const mat =
      this.mesh.children[0] instanceof THREE.Mesh
        ? (this.mesh.children[0].material as THREE.MeshStandardMaterial)
        : null;
    if (mat) {
      if (DEBUG_WIREFRAME) {
        mat.wireframe = true;
        mat.opacity = 0.9;
        mat.transparent = true;
        const t = this.sectionRuntimeType4;
        if (t === SectionRuntimeType.TreeSectionLeaf) mat.color.setHex(0x00ff00);
        else if (t === SectionRuntimeType.TreeSectionBud) mat.color.setHex(0xff00ff);
        else if (t === SectionRuntimeType.TreeSectionTwig) mat.color.setHex(0xffaa00);
        else if (t === SectionRuntimeType.TreeSectionSeed) mat.color.setHex(0xff0000);
        else mat.color.setHex(0x00aaff);
      } else {
        mat.wireframe = false;
        mat.opacity = 1.0;
        mat.transparent = false;
        mat.color.setRGB(tr, tg, tb);
      }
      mat.roughness = 0.72 + (1.0 - globalHealth) * 0.22;
      mat.metalness = 0.02;
    }

    this.children.forEach((child) =>
      child.update(
        ageFactor,
        lightIntensity,
        trunkParams,
        globalHealth,
        wind,
        dayOfYear,
        deltaTime,
      ),
    );

    // Листва появляется при достаточной толщине (ориентировочно)
    const foliageVisible = trunkParams.thickness > 1.0;
    this.leaves.forEach((leaf) => {
      leaf.mesh.visible = foliageVisible;
      if (foliageVisible) {
        // Листья на фиксированной высоте, так как ветка не растягивается
        leaf.update(
          lightIntensity,
          ageFactor,
          globalHealth,
          wind,
          dayOfYear,
          deltaTime,
        );
      }
    });

    this.flowers.forEach((flower) => {
      flower.group.visible = foliageVisible;
      if (foliageVisible) {
        flower.update(dayOfYear, globalHealth, deltaTime);
      }
    });
  }

  public serialize(): any {
    const targetEuler = new THREE.Euler().setFromQuaternion(
      this.targetRotation,
    );
    const rotationEuler = new THREE.Euler().setFromQuaternion(this.rotation);
    return {
      level: this.level,
      branchPosition: this.branchPosition,
      branchBaseRadius: this.branchBaseRadius,
      branchTipRadius: this.branchTipRadius,
      targetRotation: { x: targetEuler.x, y: targetEuler.y, z: targetEuler.z },
      rotation: { x: rotationEuler.x, y: rotationEuler.y, z: rotationEuler.z },
      children: this.children.map((c) => c.serialize()),
      leaves: this.leaves.map((l) => ({ size: l.size, energy: l.energy })),
      flowers: this.flowers.map((f) => ({
        bloomProgress: f["bloomProgress"],
        isFalling: f["isFalling"],
      })),
      hasWire: this.hasWire,
      isPruned: this.isPruned,
      isContinuation: this.isContinuation,

      // ITreeSectionData
      prevData0: this.prevData0,
      prevData1: this.prevData1,
      prevData2: this.prevData2,
      prevData3: this.prevData3,
      quaternionBlob80u0: this.quaternionBlob80u0,
      quaternionBlob80u1: this.quaternionBlob80u1,
      quaternionBlob80u2: this.quaternionBlob80u2,
      quaternionBlob80u3: this.quaternionBlob80u3,
      baseGrowth: this.baseGrowth,
      currentGrowth: this.currentGrowth,
      age: this.age,
      growthRate: this.growthRate,
      growthTarget: this.growthTarget,
      maxGrowth: this.maxGrowth,
      energy: this.energy,
      lastLightFactor: this.lastLightFactor,
      metabolismLightScale: this.metabolismLightScale,
      metabolismLightOffset: this.metabolismLightOffset,
      growthScratchA: this.growthScratchA,
      growthScratchB: this.growthScratchB,
      energyProduction420: this.energyProduction420,
      energyBudget432: this.energyBudget432,
      energySpent436: this.energySpent436,
      energyWeight428: this.energyWeight428,
      worldDetached188: this.worldDetached188,
      energyAccumulator424: this.energyAccumulator424,
      energyTickCounter440: this.energyTickCounter440,
      sub414CE0SeedBudget428: this.sub414CE0SeedBudget428,
      twigRadius444: this.twigRadius444,
      twigLength448: this.twigLength448,
      meshScalar36: this.meshScalar36,
      sectionRuntimeType4: this.sectionRuntimeType4,
      ce512EnergyAllowanceScale: this.ce512EnergyAllowanceScale,
      rollupDword480: this.rollupDword480,
      rollupDword484: this.rollupDword484,

      // IVisualState
      colorR: this.colorR,
      colorG: this.colorG,
      colorB: this.colorB,
      colorA: this.colorA,
    };
  }

  public static deserialize(
    data: any,
    parent: TreeSection | null,
    rng: MSVCRand,
  ): TreeSection {
    const section = new TreeSection(
      parent,
      data.level,
      rng,
      data.branchBaseRadius,
    );
    section.branchPosition = data.branchPosition ?? 1.0;
    if (data.branchTipRadius !== undefined)
      section.branchTipRadius = data.branchTipRadius;

    // ITreeSectionData
    section.prevData0 = data.prevData0 ?? 0;
    section.prevData1 = data.prevData1 ?? 0;
    section.prevData2 = data.prevData2 ?? 0;
    section.prevData3 = data.prevData3 ?? 0;
    section.quaternionBlob80u0 = data.quaternionBlob80u0 ?? 0;
    section.quaternionBlob80u1 = data.quaternionBlob80u1 ?? 0;
    section.quaternionBlob80u2 = data.quaternionBlob80u2 ?? 0;
    section.quaternionBlob80u3 = data.quaternionBlob80u3 ?? 0;
    section.baseGrowth = data.baseGrowth ?? 1.0;
    section.currentGrowth = data.currentGrowth ?? 0.0;
    section.age = data.age ?? 0.0;
    section.growthRate = data.growthRate ?? 0.0;
    section.growthTarget = data.growthTarget ?? 0.0;
    section.maxGrowth = data.maxGrowth ?? 10.0;
    section.energy = data.energy ?? 1.0;
    section.lastLightFactor = data.lastLightFactor ?? 1.0;
    section.metabolismLightScale =
      data.metabolismLightScale ?? section.baseGrowth;
    section.metabolismLightOffset =
      data.metabolismLightOffset ?? data.lightResponseBias ?? 0.5;
    section.growthScratchA = data.growthScratchA ?? 0;
    section.growthScratchB = data.growthScratchB ?? 0;
    section.energyProduction420 = data.energyProduction420 ?? 0;
    section.energyBudget432 = data.energyBudget432 ?? 0;
    section.energySpent436 = data.energySpent436 ?? 0;
    section.energyWeight428 = data.energyWeight428 ?? 1.0;
    section.worldDetached188 = data.worldDetached188 ?? false;
    section.energyAccumulator424 = data.energyAccumulator424 ?? 0;
    section.energyTickCounter440 = data.energyTickCounter440 ?? 0;
    section.sub414CE0SeedBudget428 = data.sub414CE0SeedBudget428 ?? 0;
    section.twigRadius444 = data.twigRadius444 ?? section.branchBaseRadius;
    section.twigLength448 =
      data.twigLength448 ?? (TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR as number);
    section.meshScalar36 = data.meshScalar36 ?? 0;
    {
      const raw = data.sectionRuntimeType4;
      if (raw === undefined || raw === null || raw === 0) {
        section.sectionRuntimeType4 =
          parent === null && data.level === 0
            ? SectionRuntimeType.TreeSectionSeed
            : SectionRuntimeType.TreeSection;
      } else {
        section.sectionRuntimeType4 = raw;
      }
    }
    section.ce512EnergyAllowanceScale =
      data.ce512EnergyAllowanceScale ?? (1.0 as Float32);
    section.rollupDword480 = data.rollupDword480 ?? 0;
    section.rollupDword484 = data.rollupDword484 ?? 0;
    section.spawnDelta480 = 0;
    section.skipGrowthTick = false;

    // IVisualState
    section.colorR = data.colorR ?? 0.45;
    section.colorG = data.colorG ?? 0.3;
    section.colorB = data.colorB ?? 0.19;
    section.colorA = data.colorA ?? 1.0;

    if (data.targetRotation) {
      const euler = new THREE.Euler(
        data.targetRotation.x,
        data.targetRotation.y,
        data.targetRotation.z,
      );
      section.targetRotation.setFromEuler(euler);
    }

    if (data.rotation) {
      const euler = new THREE.Euler(
        data.rotation.x,
        data.rotation.y,
        data.rotation.z,
      );
      section.rotation.setFromEuler(euler);
    } else {
      section.rotation.copy(section.targetRotation);
    }
    section.rotationQuaternion.copy(section.rotation);
    if (data.quaternionBlob80u0 === undefined) {
      Sub416510Rotation.syncBlob80FromQuaternion(section);
    }

    section.isPruned = data.isPruned ?? false;
    section.isContinuation = data.isContinuation ?? false;

    if (data.children) {
      section.children = data.children.map((c: any) =>
        TreeSection.deserialize(c, section, rng),
      );
    }

    if (data.leaves) {
      section.leaves = data.leaves.map((ld: any) => {
        const leaf = new TreeLeaf(section.group, rng);
        leaf.size = ld.size;
        leaf.energy = ld.energy;
        return leaf;
      });
    }

    if (data.flowers) {
      section.flowers = data.flowers.map((fd: any) => {
        const flower = new TreeFlower(section.group, rng);
        flower["bloomProgress"] = fd.bloomProgress ?? 0;
        flower["isFalling"] = fd.isFalling ?? false;
        return flower;
      });
    }

    if (data.hasWire) {
      section.hasWire = true;
      section.createWireVisuals();
    }

    return section;
  }

  public prune(target: THREE.Object3D): boolean {
    // Check if we clicked a child's group
    const index = this.children.findIndex((child) => child.group === target);
    if (index !== -1) {
      this.group.remove(this.children[index].group);
      this.children.splice(index, 1);
      return true;
    }

    // Check if we clicked this section's mesh directly
    const isThisMesh = this.mesh.children.some(
      (child) =>
        child === target ||
        (child instanceof THREE.Group &&
          child.children.includes(target as any)),
    );
    if (isThisMesh) {
      // In the original game, cutting a section removes all its children and foliage
      this.children.forEach((child) => this.group.remove(child.group));
      this.children = [];

      this.leaves.forEach((l) => this.group.remove(l.mesh));
      this.leaves = [];

      this.flowers.forEach((f) => this.group.remove(f.group));
      this.flowers = [];

      this.isPruned = true;
      this.addCutVisual(0);
      return true;
    }

    for (const child of this.children) if (child.prune(target)) return true;
    return false;
  }

  public applyWire(target: THREE.Object3D): boolean {
    const isThisMesh = this.mesh.children.some(
      (child) =>
        child === target ||
        (child instanceof THREE.Group &&
          child.children.includes(target as any)),
    );
    if (this.group === target || isThisMesh) {
      const euler = new THREE.Euler().setFromQuaternion(this.targetRotation);
      euler.x += (this.rng.randFloat() - 0.5) * 0.5;
      euler.z += (this.rng.randFloat() - 0.5) * 0.5;
      this.targetRotation.setFromEuler(euler);
      this.hasWire = true;
      this.createWireVisuals();
      return true;
    }
    for (const child of this.children) if (child.applyWire(target)) return true;
    return false;
  }

  private addCutVisual(segmentIndex: number): void {
    if (this.cutCap) this.mesh.remove(this.cutCap);
    const lastSegment = this.mesh.children[segmentIndex] as THREE.Mesh;
    if (!lastSegment || !lastSegment.geometry) return;

    const radius = (lastSegment.geometry as THREE.CylinderGeometry).parameters
      .radiusTop;
    this.cutCap = GeometryService.createCutCap(radius);
    this.cutCap.position.y = TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR; // Cap goes at the top of the section
    this.mesh.add(this.cutCap);
  }

  private createWireVisuals(): void {
    if (this.wireMesh) return;
    this.wireMesh = new THREE.Group();
    const wireMaterial = new THREE.MeshStandardMaterial({
      color: 0x888888,
      metalness: 0.8,
      roughness: 0.2,
    });
    const segments = 10;
    const radius = this.branchBaseRadius + 0.01;
    for (let i = 0; i < segments; i++) {
      const wireGeo = new THREE.TorusGeometry(radius, 0.005, 8, 12, Math.PI);
      const wire = new THREE.Mesh(wireGeo, wireMaterial);
      wire.position.y = (i / segments) * TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR;
      wire.rotation.x = Math.PI / 2;
      wire.rotation.z = (i / segments) * Math.PI * 4;
      this.wireMesh.add(wire);
    }
    this.group.add(this.wireMesh);
  }

  public addBranch(
    atPosition: number = 1.0,
    isContinuation: boolean = false,
  ): TreeSection | null {
    const nextLevel = this.level + 1;
    if (nextLevel < TREE_CONSTANTS.GROWTH.MAX_LEVEL) {
      const child = new TreeSection(
        this,
        nextLevel,
        this.rng,
        this.getRadiusAt(atPosition),
      );
      child.branchPosition = atPosition;
      child.isContinuation = isContinuation;

      if (isContinuation) {
        child.targetRotation.copy(this.targetRotation);
        child.rotationQuaternion.copy(this.rotationQuaternion);
        child.rotation.copy(this.rotation);
      } else {
        const yaw = (this.rng.randFloat() - 0.5) * 1.2;
        const pitch = (this.rng.randFloat() - 0.5) * 1.0;
        TransformService.rotationYawPitchRoll(
          child.targetRotation,
          yaw,
          pitch,
          0,
        );
        child.rotationQuaternion.copy(child.targetRotation);
        child.rotation.copy(child.targetRotation);
      }
      Sub416510Rotation.syncBlob80FromQuaternion(child);

      this.children.push(child);
      child.updateAttachmentPosition(this);
      return child;
    }
    return null;
  }
}
