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
import { sampleMaxGrowth452Sub4159C0 } from "./config/GrowthConstants";
import { getSlot36SimulationDay } from "./growth/frameState";

/** Debug: show wireframe skeleton instead of solid meshes */
export let DEBUG_WIREFRAME = false;
export function setDebugWireframe(on: boolean): void {
  DEBUG_WIREFRAME = on;
}

const VISUAL_SEGMENTS_PER_SECTION = 6;
const VISUAL_LENGTH_SCALE_418F10 = 0.51;
const _tmpTemplatePos240 = new THREE.Vector3();
const _tmpTemplateQuat240 = new THREE.Quaternion();
const _axisY240 = new THREE.Vector3(0, 1, 0);
const _tmpTemplateScale240 = new THREE.Vector3(1, 1, 1);
const _tmpCombinedLocalQuat240 = new THREE.Quaternion();
let _nextTreeSectionDebugId = 1;

export class TreeSection
  implements ITreeSectionData, IVisualState, ITransformState, IWorkingBuffers
{
  public readonly debugId: number;
  public parent: TreeSection | null;
  public level: number;
  public children: TreeSection[] = [];
  public leaves: TreeLeaf[] = [];
  public flowers: TreeFlower[] = [];

  public currentBranchScale: Float32 = 0.0;
  public branchPosition: Float32 = 1.0;
  /**
   * sub_4158D0(sub_4188E0): Translation(0, v22, v11) вЂ” v22 = parent.twigRadius*0.85.
   * Р’ СЃС†РµРЅРµ СЂРѕРґРёС‚РµР»СЏ: РѕС‚РІРѕРґ РѕС‚ РѕСЃРё РІРґРѕР»СЊ Р»РѕРєР°Р»СЊРЅРѕРіРѕ Z (РѕСЃСЊ СЂРѕСЃС‚Р° РґРѕС‡РµСЂРё вЂ” +Y).
   */
  public lateralTransY4158: Float32 = 0;
  /** sub_4158D0: Roll (4-Р№ Р°СЂРіСѓРјРµРЅС‚ v12); РІ TS вЂ” РґРѕРї. РїРѕРІРѕСЂРѕС‚ РІРѕРєСЂСѓРі Р»РѕРєР°Р»СЊРЅРѕР№ Z РїРѕСЃР»Рµ YPR РїРѕС‡РєРё. */
  public lateralRoll4158Z: Float32 = 0;
  /**
   * Some original C spawn paths materialize exact local attachment matrices via sub_4158D0
   * and then consume them in sub_4146F0. Those paths must not be re-synthesized every frame
   * from branchPosition/lateral* approximations.
   */
  public useExactLocalTemplateAttachment240: boolean = false;
  public branchBaseRadius: Float32;
  public branchTipRadius: Float32;

  // ITransformState
  public rotationQuaternion: D3DXQUATERNION = new THREE.Quaternion(); // this + 320
  /** sub_413F50/4158D0: base local template matrix at +240 */
  public localTemplate240: D3DXMATRIX = new THREE.Matrix4();
  /** sub_4146F0: qmemcpy(this+352, D3DXMatrixInverse(world)); РЅРµ РїСЂСЏРјРѕР№ matrixWorld. */
  public transformMatrix: D3DXMATRIX = new THREE.Matrix4();

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
  /** sub_416510 В«СЂР°Р±РѕС‡РёРµВ» DWORD РєРІР°С‚РµСЂРЅРёРѕРЅР° (+80..+83), РєРѕРїРёСЂСѓСЋС‚СЃСЏ РІ prevData РїРµСЂРµРґ slerp */
  public quaternionBlob80u0: number = 0;
  public quaternionBlob80u1: number = 0;
  public quaternionBlob80u2: number = 0;
  public quaternionBlob80u3: number = 0;
  public baseGrowth: Float32 = 1.0; // this + 108
  public currentGrowth: Float32 = 0.0; // this + 109
  public age: Float32 = 0.0; // this + 110
  public growthRate: Float32 = 0.0; // this + 111
  public growthTarget: Float32 = 0.0; // this + 112
  /** C exe: float at this+452 (sub_4159C0 / twig cap РІ sub_418BD0); РІ TS РёРјСЏ РёСЃС‚РѕСЂРёС‡РµСЃРєРѕРµ В«maxGrowthВ». */
  public maxGrowth: Float32 = 5.0;
  public energy: Float32 = 1.0; // this + 114

  /** this+420 вЂ” РЅР°РєРѕРїР»РµРЅРёРµ В«productionВ» Р·Р° РєР°РґСЂ (Р°РіСЂРµРіР°С‚ РєР°Рє РІ sub_414E10 / sub_40DC90) */
  public energyProduction420: Float32 = 0;
  /** this+432 вЂ” СЌРЅРµСЂРіРµС‚РёС‡РµСЃРєРёР№ Р±СЋРґР¶РµС‚, РІС‹СЃС‚Р°РІР»СЏРµС‚СЃСЏ РґРѕ СЃР»РѕС‚Р° +36 (sub_40DC90) */
  public energyBudget432: Float32 = 0;
  /** this+436 вЂ” СЂР°СЃС…РѕРґ Р·Р° РєР°РґСЂ; РЅР° РєРѕСЂРЅРµ вЂ” СЃСѓРјРјР° РїРѕ РїРѕРґРґРµСЂРµРІСѓ РїРѕСЃР»Рµ sub_414E10 */
  public energySpent436: Float32 = 0;
  /** this+428 вЂ” РІРµСЃ РґРѕР»Рё parent+432 Сѓ СЂРµР±С‘РЅРєР° (sub_414E10); СЃРёРЅС…СЂРѕРЅРёР·РёСЂСѓРµС‚СЃСЏ РёР· РіРµРѕРјРµС‚СЂРёРё */
  public energyWeight428: Float32 = 1.0;
  /** this+188 вЂ” В«РѕС‚С†РµРїР»РµРЅВ» РѕС‚ РёРµСЂР°СЂС…РёРё СЂРѕСЃС‚Р°; sub_414E10 РїСЂРѕРїСѓСЃРєР°РµС‚ СѓР·РµР» */
  public worldDetached188: boolean = false;

  /** this+424 вЂ” РЅР°РєРѕРїРёС‚РµР»СЊРЅС‹Р№ РёРЅС‚РµРіСЂР°Р» +420 (sub_414E10: += this+420 РєР°Р¶РґС‹Р№ РєР°РґСЂ) */
  public energyAccumulator424: Float32 = 0;
  /** this+440 вЂ” СЃС‡С‘С‚С‡РёРє РїСЂРѕС…РѕРґРѕРІ sub_414E10 (sub_414E10: += 1.0 РЅР° СѓР·РµР» Р·Р° РєР°РґСЂ) */
  public energyTickCounter440: Float32 = 0;
  /** Runtime parity helper: simulation day when this section was created/spawned. */
  public branchBirthSimulationDay: Float32 = 0;
  /**
   * РџРѕСЃР»Рµ sub_40DC90 РЅР° РіСЂР°РЅРёС†Рµ РіРѕРґР°: *(root+428)=1.0 (РѕС‚РґРµР»СЊРЅРѕ РѕС‚ РІРµСЃР° child+432 РІ sub_414E10).
   * РСЃРїРѕР»СЊР·СѓРµС‚СЃСЏ РєР°Рє СЃРµРјСЏ РіРѕРґРѕРІРѕРіРѕ Р±СЋРґР¶РµС‚Р°; РїРѕР»РЅР°СЏ СЃРµРјР°РЅС‚РёРєР° C вЂ” СЃРј. sub_414CE0 + С‚РёРї СЃРµРєС†РёРё.
   */
  public sub414CE0SeedBudget428: Float32 = 0;

  /** this+444 вЂ” СЂР°РґРёСѓСЃ РІРµС‚РєРё (sub_417C90, sub_4188E0; РјР°С‚СЂРёС†С‹ РІ sub_418F10) */
  public twigRadius444: Float32 = 0;
  /** this+448 вЂ” РґР»РёРЅР°/РјР°СЃС€С‚Р°Р± СЃРµРіРјРµРЅС‚Р° (sub_418BD0, sub_418F10) */
  public twigLength448: Float32 = 0;
  /** this+36 вЂ” СЃРєР°Р»СЏСЂ С‚РѕР»С‰РёРЅС‹: max(+444, +448*0.5) РІ С…РІРѕСЃС‚Рµ sub_414E10 */
  public meshScalar36: Float32 = 0;

  /**
   * this+4 вЂ” РєР»Р°СЃСЃ/С‚РёРї СЃРµРєС†РёРё РІ exe (`*(_DWORD *)(this+4)` РґР»СЏ byte_4D8229/822A Рё РґСЂ.).
   * РџРѕРєР° 0 Сѓ РІСЃРµС… СѓР·Р»РѕРІ; Р·Р°РґР°С‚СЊ РїСЂРё РїРѕСЏРІР»РµРЅРёРё Seed/Bud/Twig/Leaf РєР°Рє РІ rdata.
   */
  /** РџРѕ СѓРјРѕР»С‡Р°РЅРёСЋ Р±Р°Р·РѕРІР°СЏ СЃРµРєС†РёСЏ (5); РєРѕСЂРµРЅСЊ РїРµСЂРµР·Р°РїРёСЃС‹РІР°РµС‚СЃСЏ РЅР° Seed (8). */
  public sectionRuntimeType4: number = SectionRuntimeType.TreeSection;
  /**
   * this+512 вЂ” РјРЅРѕР¶РёС‚РµР»СЊ Рє parent+428 РІ sub_414CE0 РїСЂРё byte_4D8229 (СЃРј. v2/BonsaiNode pruneRatio).
   */
  public ce512EnergyAllowanceScale: Float32 = 1.0;

  /** this+480 вЂ” DWORD: lateral spawn (sub_4188E0 ++); РІ sub_414E10 СЃСѓРјРјРёСЂСѓРµС‚СЃСЏ СЃ РґРµС‚СЊРјРё */
  public rollupDword480: number = 0;
  /** this+484 вЂ” DWORD: С‚РёРє twig (sub_417C90 ++); РІ sub_414E10 СЃСѓРјРјРёСЂСѓРµС‚СЃСЏ СЃ РґРµС‚СЊРјРё +1 РЅР° РІРЅСѓС‚СЂРµРЅРЅРµРј СѓР·Р»Рµ */
  public rollupDword484: number = 0;
  /** РљР°РґСЂРѕРІС‹Р№ РІРєР»Р°Рґ РІ +480 РїСЂРё sub_4188E0 (РЅРµ СЃРµСЂРёР°Р»РёР·СѓРµС‚СЃСЏ вЂ” РѕР±РЅСѓР»СЏРµС‚СЃСЏ РєР°Р¶РґС‹Р№ РєР°РґСЂ) */
  public spawnDelta480: number = 0;

  /** this+512 вЂ” byte flag: true = length growing (sub_418BD0), false = branching (sub_417F40) */
  public growthFlag512: boolean = true;
  /** this+456 вЂ” smoothed health energy (sub_417C90: += (prod/20 - this)*0.1) */
  public healthEnergy456: Float32 = 0.5;
  /** this+516 вЂ” leaf count (sub_415AB0 increments) */
  public leafCount516: number = 0;
  /** this+236 вЂ” marked for detach (vtable slot +44 в†’ sub_40EEE0) */
  public markedForDetach236: boolean = false;
  /** Bud: accumulated leaf spawn angle (sub_415AB0 uses this+512 as float on bud) */
  public leafSpawnAngle: number = 0;

  // в”Ђв”Ђв”Ђ Light tracing fields (sub_40E460 / sub_4143E0) в”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђ
  /** this+196..+204 вЂ” light response direction (updated by ray-march sub_40E460) */
  public lightResponseVec: THREE.Vector3 = new THREE.Vector3(0, 1, 0);
  /** this+208 вЂ” smoothed scalar: (dot*intensity + old*10)/11 from sub_40E460 */
  public smoothedLightA: Float32 = 0.1;
  /** this+212 вЂ” smoothed scalar: (intensity + old*20)/21 from sub_40E460 */
  public smoothedLightB: Float32 = 0.1;
  /** this+216..+224 вЂ” previous direction, slerps toward +196 in sub_4143E0 */
  public prevDirectionVec: THREE.Vector3 = new THREE.Vector3(0, 1, 0);
  /** this+228 вЂ” slow copy of +208 (coeff 0.1) from sub_4143E0 */
  public smoothTargetA: Float32 = 0.1;
  /** this+232 вЂ” slow copy of +212 (coeff 0.1) from sub_4143E0 */
  public smoothTargetB: Float32 = 0.1;

  /**
   * sub_450BD0 + sub_450A80: РѕР±СЉРµРґРёРЅС‘РЅРЅР°СЏ СЃС„РµСЂР° РїРѕРґРґРµСЂРµРІР° РґР»СЏ broad-phase sub_450860
   * (this+8..+16 С†РµРЅС‚СЂ, this+20 СЂР°РґРёСѓСЃ). РЈР·РєРёР№ С‚РµСЃС‚ sub_450970 РѕСЃС‚Р°С‘С‚СЃСЏ РїРѕ this+24 Рё +36.
   */
  public lightSpatialCenter8: THREE.Vector3 = new THREE.Vector3();
  public lightSpatialRadius20: number = 0;

  // в”Ђв”Ђв”Ђ Physics fields (sub_414870 / sub_414A70 / sub_414BB0) в”Ђв”Ђв”Ђв”Ђв”Ђв”Ђ
  /** this+460 вЂ” total weight of subtree (mass + children) */
  public totalWeight460: number = 0;
  /** this+464 вЂ” stored mass of this section alone */
  public storedMass464: number = 0;
  /** this+468..+476 вЂ” center of mass in local coords */
  public centroid468: THREE.Vector3 = new THREE.Vector3(0, 0, 0);

  // в”Ђв”Ђв”Ђ World object fields (sub_40F140) в”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђв”Ђ
  /** this+488..+496 вЂ” linear velocity for detached sections */
  public velocity488: THREE.Vector3 = new THREE.Vector3(0, 0, 0);
  /** this+500..+508 вЂ” angular velocity for detached sections */
  public angularVelocity500: THREE.Vector3 = new THREE.Vector3(0, 0, 0);

  /** sub_416510 v34 вЂ” РѕС‚РєР»РёРє СЃРµРєС†РёРё РЅР° СЃРІРµС‚ (0..1), РѕР±РЅРѕРІР»СЏРµС‚СЃСЏ РјРµС‚Р°Р±РѕР»РёР·РјРѕРј */
  public lastLightFactor: Float32 = 1.0;
  /** sub_416510 *((float*)this+52) вЂ” РјРЅРѕР¶РёС‚РµР»СЊ РІ v34 (СЃРёРЅС…СЂРѕРЅРёР·РёСЂСѓРµС‚СЃСЏ СЃ baseGrowth РІ СЂРѕСЃС‚Рµ) */
  public metabolismLightScale: Float32 = 1.0;
  /** sub_416510 *((float*)this+53) вЂ” РІ С„РѕСЂРјСѓР»Рµ v34 СѓРјРЅРѕР¶Р°РµС‚СЃСЏ РЅР° 0.5 */
  public metabolismLightOffset: Float32 = 0.5;
  /** sub_416510.c:286вЂ“287 вЂ” РІСЃРїРѕРјРѕРіР°С‚РµР»СЊРЅС‹Рµ РЅР°РєРѕРїР»РµРЅРёСЏ (this+105 / +106) */
  public growthScratchA: Float32 = 0;
  public growthScratchB: Float32 = 0;
  /** sub_416510.c:161 вЂ” РїСЂРѕРїСѓСЃРє РїСЂРёСЂРѕСЃС‚Р° РЅР° СЌС‚РѕС‚ РєР°РґСЂ */
  public skipGrowthTick: boolean = false;

  public isContinuation: boolean = false;

  // IVisualState (from C offsets) вЂ” СЃС‚Р°СЂС‚РѕРІР°СЏ С‚С‘РїР»Р°СЏ РєРѕСЂР° (РґРѕ РїРµСЂРІРѕРіРѕ РєР°РґСЂР° СЂРѕСЃС‚Р°)
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
    this.debugId = _nextTreeSectionDebugId++;
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

    // Р Р°РґРёСѓСЃ Рё СЃСѓР¶РµРЅРёРµ (sub_4093B0.c)
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

    // Original sub_4093B0 builds one continuous frustum surface for a section.
    const branchMesh = GeometryService.createBranchSegment(
      this.branchTipRadius,
      this.branchBaseRadius,
      sectionHeight,
      level,
      this.rng,
      0,
      1,
    );
    branchMesh.userData = {
      isBranchSurface: true,
      parentSection: this,
    };
    this.mesh.add(branchMesh);

    // Virtual sub-segments are kept only for raycast/highlight/cut UX.
    const segmentCount = Math.max(1, VISUAL_SEGMENTS_PER_SECTION);
    const segmentHeight = sectionHeight / segmentCount;
    for (let i = 0; i < segmentCount; i++) {
      const tBottom = i / segmentCount;
      const tTop = (i + 1) / segmentCount;
      const radiusBottom =
        this.branchBaseRadius * (1.0 - tBottom) +
        this.branchTipRadius * tBottom;
      const radiusTop =
        this.branchBaseRadius * (1.0 - tTop) + this.branchTipRadius * tTop;
      const segmentMesh = GeometryService.createBranchSegment(
        radiusTop,
        radiusBottom,
        segmentHeight,
        level,
        this.rng,
        tBottom,
        tTop,
      );
      segmentMesh.userData = {
        isSegment: true,
        segmentOverlay: true,
        segmentIndex: i,
        parentSection: this,
      };
      segmentMesh.position.y = i * segmentHeight;
      segmentMesh.castShadow = false;
      segmentMesh.receiveShadow = false;
      segmentMesh.material = new THREE.MeshStandardMaterial({
        color: 0x000000,
        transparent: true,
        opacity: 0,
        depthWrite: false,
        polygonOffset: true,
        polygonOffsetFactor: -2,
        polygonOffsetUnits: -2,
        roughness: 1.0,
        metalness: 0,
      });
      this.mesh.add(segmentMesh);
    }

    if (parent) parent.group.add(this.group);
    Sub416510Rotation.initBlob80Identity(this);
  }

  /**
   * sub_4159C0 + sub_417440.c вЂ” РїРµСЂРІР°СЏ РїРѕС‡РєР° РЅР° СЃРµРјРµРЅРё (Р±РµР· РїРѕР»РЅРѕР№ РіРµРѕРјРµС‚СЂРёРё sub_416030).
   * РЈРіР»С‹ РєР°Рє РІ C: v5[0], v5[2] в€€ [-0.08, 0.08], v5[1]=0.
   */
  public static createBudFromSeed(
    parent: TreeSection,
    rng: MSVCRand,
    yawJitter: number,
    rollJitter: number,
  ): TreeSection {
    const bud = new TreeSection(parent, parent.level + 1, rng, 0.01);
    bud.sectionRuntimeType4 = SectionRuntimeType.TreeSectionBud;
    bud.twigRadius444 = 0.01 as Float32;
    bud.twigLength448 = (TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR *
      0.12) as Float32;
    bud.mesh.visible = false;
    bud.branchBirthSimulationDay = getSlot36SimulationDay() as Float32;
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
    // sub_417440 в†’ sub_4159C0: РѕРґРёРЅ rand РЅР° *(bud+452)
    bud.maxGrowth = sampleMaxGrowth452Sub4159C0(rng);
    // Initial seedв†’bud path is the main apical continuation chain.
    bud.isContinuation = true;
    parent.children.push(bud);
    bud.updateAttachmentPosition(parent);
    return bud;
  }

  /**
   * РџРѕСЃР»Рµ updateMatrixWorld: this+352 РєР°Рє РІ sub_4146F0 (РёРЅРІРµСЂСЃРёСЏ РјРёСЂРѕРІРѕР№ РјР°С‚СЂРёС†С‹ СЃРµРєС†РёРё).
   * sub_401540 / D3DXVec3TransformNormal(+196, this+352) вЂ” С‚РѕС‚ Р¶Рµ РїСѓС‚СЊ, С‡С‚Рѕ inverse+normalMatrix РІ РјРµС‚Р°Р±РѕР»РёР·РјРµ.
   */
  public static syncTransformMatricesFromWorld(root: TreeSection): void {
    const stack: TreeSection[] = [root];
    while (stack.length) {
      const s = stack.pop()!;
      s.transformMatrix.copy(s.group.matrixWorld).invert();
      for (let i = s.children.length - 1; i >= 0; i--)
        stack.push(s.children[i]);
    }
  }

  public getRadiusAt(t: number): number {
    const baseRadius = Math.max(1e-4, this.twigRadius444 as number);
    const ctorTaper =
      this.branchBaseRadius > 1e-6
        ? this.branchTipRadius / this.branchBaseRadius
        : 1.0;
    const tipRadius = Math.max(1e-4, baseRadius * ctorTaper);
    return baseRadius * (1.0 - t) + tipRadius * t;
  }

  public getAttachmentSpan(strictExeSimVisuals: boolean = false): number {
    const { GEOMETRY } = TREE_CONSTANTS;
    const baseHeight = GEOMETRY.HEIGHT_FACTOR;
    const twigLen = this.twigLength448 as number;
    void strictExeSimVisuals;
    return Math.max(baseHeight * 0.02, twigLen * VISUAL_LENGTH_SCALE_418F10);
  }

  /** РџРѕР·РёС†РёСЏ РґРѕС‡РµСЂРЅРµР№ СЃРµРєС†РёРё РІРґРѕР»СЊ Р»РѕРєР°Р»СЊРЅРѕР№ РѕСЃРё Y СЂРѕРґРёС‚РµР»СЏ (sub_415C10 / РёРµСЂР°СЂС…РёСЏ СЃС†РµРЅС‹). */
  public updateAttachmentPosition(
    parent: TreeSection,
    strictExeSimVisuals: boolean = false,
  ): void {
    if (this.useExactLocalTemplateAttachment240) {
      this.localTemplate240.decompose(
        _tmpTemplatePos240,
        _tmpTemplateQuat240,
        _tmpTemplateScale240,
      );
      this.group.position.copy(_tmpTemplatePos240);
      return;
    }

    const visualHeight = parent.getAttachmentSpan(strictExeSimVisuals);
    const branchPos = Math.max(0, this.branchPosition as number);
    const lat = this.lateralTransY4158 as number;
    const roll = this.lateralRoll4158Z as number;
    const seamOverlap =
      branchPos >= 0.98 ? Math.min(0.05, visualHeight * 0.03) : 0;
    // sub_4158D0: lateral offset (a2) is absolute branch radius-space value.
    const radial = Math.abs(lat) > 1e-8 ? lat : 0;
    const px = Math.sin(roll) * radial;
    const py = Math.max(0, branchPos * visualHeight - seamOverlap);
    const pz = Math.cos(roll) * radial;
    this.group.position.set(px, py, pz);

    _tmpTemplatePos240.set(px, py, pz);
    _tmpTemplateQuat240.setFromAxisAngle(_axisY240, roll);
    this.localTemplate240.compose(
      _tmpTemplatePos240,
      _tmpTemplateQuat240,
      _tmpTemplateScale240,
    );
  }

  public update(
    ageFactor: number,
    lightIntensity: number,
    trunkParams: TreeTrunkParams,
    globalHealth: number,
    wind: THREE.Vector3,
    dayOfYear: number,
    deltaTime: number,
    /** strict exe: Р±РµР· РІРёР·СѓР°Р»СЊРЅРѕРіРѕ sway (Date.now + wind) вЂ” РІ C РЅРµС‚ СЌС‚РѕРіРѕ СЃР»РѕСЏ РЅР° group */
    strictExeSimVisuals: boolean = false,
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

    // sub_40D6D0 (Р»РёСЃС‚): РЅРѕСЂРјР°Р»СЊ РїР»Р°СЃС‚РёРЅС‹ РґР»СЏ sub_40E460 lightDecay вЂ” Р»РѕРєР°Р»СЊРЅР°СЏ +Y РІ РјРёСЂ.
    if (this.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
      this.directionVector
        .set(0, 1, 0)
        .applyQuaternion(this.rotationQuaternion);
      this.directionVector.normalize();
    }

    if (this.parent) {
      this.localTemplate240.decompose(
        _tmpTemplatePos240,
        _tmpTemplateQuat240,
        _tmpTemplateScale240,
      );
      this.group.position.copy(_tmpTemplatePos240);
      _tmpCombinedLocalQuat240.multiplyQuaternions(
        _tmpTemplateQuat240,
        this.rotationQuaternion,
      );
      this.group.quaternion.copy(_tmpCombinedLocalQuat240);
      this.group.scale.copy(_tmpTemplateScale240);
    } else {
      this.group.quaternion.copy(this.rotationQuaternion);
    }

    const { GEOMETRY } = TREE_CONSTANTS;

    // Height: sub_418F10 uses this+448 with ~0.51 multiplier for twig visual length.
    const baseHeight = GEOMETRY.HEIGHT_FACTOR;
    const currentHeightScale =
      this.getAttachmentSpan(strictExeSimVisuals) / baseHeight;

    const thicknessInput = Math.max(0.05, trunkParams.thickness as number);
    let radScale =
      Math.max(1e-4, this.twigRadius444 as number) /
      Math.max(1e-4, this.branchBaseRadius);

    const isWoodySection =
      this.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf &&
      this.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionBud;

    if (thicknessInput > 0.01 && isWoodySection) {
      radScale = Math.max(0.001, radScale);
      this.mesh.scale.set(radScale, currentHeightScale, radScale);
      this.mesh.visible = true;
      this.group.visible = true;

      if (this.wireMesh) {
        const wireScale = Math.max(0.05, radScale * 0.85);
        this.wireMesh.scale.set(wireScale, currentHeightScale, wireScale);
      }

      this.children.forEach((child) =>
        child.updateAttachmentPosition(this, strictExeSimVisuals),
      );
    } else {
      this.mesh.visible = false;
      if (this.sectionRuntimeType4 !== SectionRuntimeType.TreeSectionLeaf) {
        this.group.visible = false;
      }
    }

    const tr = Math.min(1, Math.max(0, this.colorR));
    const tg = Math.min(1, Math.max(0, this.colorG));
    const tb = Math.min(1, Math.max(0, this.colorB));

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
        if (t === SectionRuntimeType.TreeSectionLeaf)
          mat.color.setHex(0x00ff00);
        else if (t === SectionRuntimeType.TreeSectionBud)
          mat.color.setHex(0xff00ff);
        else if (t === SectionRuntimeType.TreeSectionTwig)
          mat.color.setHex(0xffaa00);
        else if (t === SectionRuntimeType.TreeSectionSeed)
          mat.color.setHex(0xff0000);
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
        strictExeSimVisuals,
      ),
    );

    const isWinter = dayOfYear >= 320 || dayOfYear < 60;
    const foliageVisible = !isWinter;
    this.leaves.forEach((leaf) => {
      leaf.mesh.visible = foliageVisible;
      if (foliageVisible) {
        // Р›РёСЃС‚СЊСЏ РЅР° С„РёРєСЃРёСЂРѕРІР°РЅРЅРѕР№ РІС‹СЃРѕС‚Рµ, С‚Р°Рє РєР°Рє РІРµС‚РєР° РЅРµ СЂР°СЃС‚СЏРіРёРІР°РµС‚СЃСЏ
        leaf.update(
          lightIntensity,
          ageFactor,
          globalHealth,
          wind,
          dayOfYear,
          deltaTime,
          strictExeSimVisuals,
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
      lateralTransY4158: this.lateralTransY4158,
      lateralRoll4158Z: this.lateralRoll4158Z,
      useExactLocalTemplateAttachment240: this.useExactLocalTemplateAttachment240,
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
      branchBirthSimulationDay: this.branchBirthSimulationDay,
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
    section.lateralTransY4158 = data.lateralTransY4158 ?? 0;
    section.lateralRoll4158Z = data.lateralRoll4158Z ?? 0;
    section.useExactLocalTemplateAttachment240 =
      data.useExactLocalTemplateAttachment240 ?? false;
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
    const loadedWeight428 = data.energyWeight428 ?? 1.0;
    section.worldDetached188 = data.worldDetached188 ?? false;
    section.energyAccumulator424 = data.energyAccumulator424 ?? 0;
    section.energyTickCounter440 = data.energyTickCounter440 ?? 0;
    section.branchBirthSimulationDay =
      data.branchBirthSimulationDay ?? data.birthSimulationDay ?? 0;
    const loadedSeed428 = data.sub414CE0SeedBudget428 ?? 0;
    const unified428 = loadedSeed428 !== 0 ? loadedSeed428 : loadedWeight428;
    section.energyWeight428 = unified428;
    section.sub414CE0SeedBudget428 = unified428;
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

  public prune(
    target: THREE.Object3D,
    options?: { removeSection?: boolean; removeTerminalSection?: boolean },
  ): boolean {
    const removeSection = !!options?.removeSection;
    const removeTerminalSection = options?.removeTerminalSection !== false;
    const clickedSegmentIndex = this.resolveSegmentIndex(target);
    const isThisTarget = this.group === target || clickedSegmentIndex !== null;

    if (isThisTarget) {
      if (removeSection && this.parent) {
        this.detachFromParent();
        return true;
      }

      const segmentCount = this.getSegmentCount();
      const cutIndex = Math.max(
        0,
        Math.min(segmentCount - 1, clickedSegmentIndex ?? segmentCount - 1),
      );
      const cutRatio = (cutIndex + 1) / segmentCount;

      const removedChildren = this.removeChildrenAtOrAbove(
        cutRatio,
        cutIndex < segmentCount - 1,
      );
      if (cutIndex < segmentCount - 1) {
        this.twigLength448 = Math.max(
          0.05,
          (this.twigLength448 as number) * cutRatio,
        ) as Float32;
        this.growthFlag512 = false;
      } else if (
        removedChildren === 0 &&
        removeTerminalSection &&
        this.parent
      ) {
        this.detachFromParent();
        return true;
      }

      this.clearDecorativeFoliage();

      this.isPruned = true;
      this.addCutVisual(cutIndex);
      return true;
    }

    for (const child of this.children)
      if (child.prune(target, options)) return true;
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
    const segmentMeshes = this.getSegmentMeshes();
    const count = Math.max(1, segmentMeshes.length);
    const clampedIndex = Math.max(0, Math.min(count - 1, segmentIndex));
    const lastSegment = segmentMeshes[clampedIndex];
    if (!lastSegment || !lastSegment.geometry) return;

    const radius = (lastSegment.geometry as THREE.CylinderGeometry).parameters
      .radiusTop;
    this.cutCap = GeometryService.createCutCap(radius);
    this.cutCap.position.y =
      ((clampedIndex + 1) / count) * TREE_CONSTANTS.GEOMETRY.HEIGHT_FACTOR;
    this.mesh.add(this.cutCap);
  }

  private getSegmentMeshes(): THREE.Mesh[] {
    return this.mesh.children.filter(
      (child): child is THREE.Mesh => !!child.userData?.isSegment,
    );
  }

  private getSegmentCount(): number {
    return Math.max(1, this.getSegmentMeshes().length);
  }

  private resolveSegmentIndex(target: THREE.Object3D): number | null {
    if (target.userData?.isSegment && target.userData?.parentSection === this) {
      const idx = Number(target.userData.segmentIndex);
      return Number.isFinite(idx) ? idx : this.getSegmentCount() - 1;
    }
    const segmentMeshes = this.getSegmentMeshes();
    for (let i = 0; i < segmentMeshes.length; i++) {
      if (segmentMeshes[i] === target) return i;
    }
    return null;
  }

  private removeChildrenAtOrAbove(
    cutRatio: number,
    forceRemoveContinuation: boolean,
  ): number {
    const kept: TreeSection[] = [];
    let removed = 0;
    for (const child of this.children) {
      const shouldRemove =
        (child.branchPosition as number) >= cutRatio - 1e-4 ||
        (forceRemoveContinuation && child.isContinuation);
      if (shouldRemove) {
        this.group.remove(child.group);
        removed++;
      } else {
        kept.push(child);
      }
    }
    this.children = kept;
    return removed;
  }

  private clearDecorativeFoliage(): void {
    this.leaves.forEach((l) => this.group.remove(l.mesh));
    this.leaves = [];
    this.flowers.forEach((f) => this.group.remove(f.group));
    this.flowers = [];
  }

  private detachFromParent(): void {
    if (!this.parent) return;
    const idx = this.parent.children.indexOf(this);
    if (idx !== -1) {
      this.parent.children.splice(idx, 1);
    }
    if (this.group.parent) {
      this.group.parent.remove(this.group);
    }
    this.parent = null;
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
    const radius = Math.max(0.01, (this.twigRadius444 as number) + 0.01);
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

