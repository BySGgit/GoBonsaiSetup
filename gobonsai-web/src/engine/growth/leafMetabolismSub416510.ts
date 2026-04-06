import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { GrowthConstants } from "../config/GrowthConstants";
import { MSVCRand } from "../MSVCRand";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { SectionColorService } from "../SectionColorService";
import { Float32 } from "../math/MathTypes";
import {
    createNumericPropertyBinding,
    createSub4032WideString,
    createSub408600Entry,
    sub401DD0DestroyIniEntry,
    sub4032D0Assign,
    sub408600Register,
    subAtexitRegister,
} from "../config/IniRegistrySub408600";

/**
 * sub_416510 — leaf metabolism: light → energy → production → growth.
 *
 * Вызывается из MetabolismService.update один раз за кадр после clearGrowthSkipFlags;
 * generic updateBranchEnergyTree не обходит TreeSectionLeaf (нет двойного расхода).
 */

const _inv = new THREE.Matrix4();
const _normalMat = new THREE.Matrix3();
const _lightWorld = new THREE.Vector3();
const _lightLocal = new THREE.Vector3();
const _localUp = new THREE.Vector3(0, 1, 0);
const _baseGrowthMultiplierMeta4DBB14 = createSub408600Entry();
const _lightThresholdMinMeta4DBB80 = createSub408600Entry();
const _lightThresholdMaxMeta4DBB5C = createSub408600Entry();
const _randomGrowthFactorMeta4DBB38 = createSub408600Entry();
let _sub416510InitFlags4DBBA4 = 0;

function sub472460CleanupStub(): void {
    sub401DD0DestroyIniEntry(_baseGrowthMultiplierMeta4DBB14);
}

function sub472490CleanupStub(): void {
    sub401DD0DestroyIniEntry(_lightThresholdMinMeta4DBB80);
}

function sub472480CleanupStub(): void {
    sub401DD0DestroyIniEntry(_lightThresholdMaxMeta4DBB5C);
}

function sub472470CleanupStub(): void {
    sub401DD0DestroyIniEntry(_randomGrowthFactorMeta4DBB38);
}

function ensureSub416510IniBindings(): void {
    if ((_sub416510InitFlags4DBBA4 & 1) === 0) {
        _sub416510InitFlags4DBBA4 |= 1;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "lightThresholdMin", 0x11);
        sub408600Register(
            key,
            _lightThresholdMinMeta4DBB80,
            createNumericPropertyBinding(GrowthConstants, "FLT_4D63B4"),
        );
        subAtexitRegister(sub472490CleanupStub);
    }
    if ((_sub416510InitFlags4DBBA4 & 2) === 0) {
        _sub416510InitFlags4DBBA4 |= 2;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "lightThresholdMax", 0x11);
        sub408600Register(
            key,
            _lightThresholdMaxMeta4DBB5C,
            createNumericPropertyBinding(GrowthConstants, "FLT_4D63B8"),
        );
        subAtexitRegister(sub472480CleanupStub);
    }
    if ((_sub416510InitFlags4DBBA4 & 4) === 0) {
        _sub416510InitFlags4DBBA4 |= 4;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "randomGrowthFactor", 0x12);
        sub408600Register(
            key,
            _randomGrowthFactorMeta4DBB38,
            createNumericPropertyBinding(GrowthConstants, "FLT_4D63BC"),
        );
        subAtexitRegister(sub472470CleanupStub);
    }
    if ((_sub416510InitFlags4DBBA4 & 8) === 0) {
        _sub416510InitFlags4DBBA4 |= 8;
        const key = createSub4032WideString();
        sub4032D0Assign(key, "baseGrowthMultiplier", 0x15);
        sub408600Register(
            key,
            _baseGrowthMultiplierMeta4DBB14,
            createNumericPropertyBinding(GrowthConstants, "FLT_4D63B0"),
        );
        subAtexitRegister(sub472460CleanupStub);
    }
}

/**
 * Process leaf-specific metabolism for all leaf sections in the tree.
 */
export function processLeafMetabolism(
    root: TreeSection,
    lightDirection: THREE.Vector3,
    lightIntensity: number,
    rng: MSVCRand,
    treeAge: number,
    deltaTime: number,
): void {
    ensureSub416510IniBindings();
    const stack: TreeSection[] = [root];
    while (stack.length) {
        const section = stack.pop()!;
        if (section.worldDetached188) continue;

        if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
            updateLeafSub416510(
                section,
                lightDirection,
                lightIntensity,
                rng,
                treeAge,
                deltaTime,
            );
        }

        for (const child of section.children) stack.push(child);
    }
}

/**
 * sub_416510 core logic for a single leaf section.
 * Свет: как в MetabolismService — transformMatrix (+352) + getNormalMatrix.
 */
function updateLeafSub416510(
    section: TreeSection,
    lightDirection: THREE.Vector3,
    lightIntensity: number,
    rng: MSVCRand,
    treeAge: number,
    deltaTime: number,
): void {
    const b4 = GrowthConstants.FLT_4D63B4 as number;
    const b8 = GrowthConstants.FLT_4D63B8 as number;
    const bC = GrowthConstants.FLT_4D63BC as number;
    const c4 = GrowthConstants.FLT_4D63C4 as number;
    const spentScale = GrowthConstants.SUB40DC90_METABOLISM_SPENT_SCALE as number;
    const simTicks = Math.min(2, deltaTime * 60);

    const energyAtStart = section.energy as number;

    // §2: v34 — тот же путь, что MetabolismService для нелистовых терминальных узлов
    if (lightDirection.lengthSq() > 1e-12) {
        _lightWorld.copy(lightDirection).normalize().multiplyScalar(lightIntensity);
    } else {
        const lv = GrowthConstants.LIGHT_VECTOR;
        _lightWorld.set(lv.x * lightIntensity, lv.y * lightIntensity, lv.z * lightIntensity);
    }

    _inv.copy(section.transformMatrix);
    _normalMat.getNormalMatrix(_inv);
    _lightLocal.copy(_lightWorld).applyNormalMatrix(_normalMat);

    // sub_416510: после sub_401540 локальный свет (v46,v47,v48); v21 = dot с (flt_4D538C,flt_4D5390,flt_4D5394).
    // full.c дефолт (0,1,0) → v21 = v47 = тот же dot с локальным +Y (см. GUIDES/ida_extracted_truth_log.md § sub_416510).
    const v21 =
        _localUp.x * _lightLocal.x + _localUp.y * _lightLocal.y + _localUp.z * _lightLocal.z;
    const v22 = Math.abs(v21);

    let v34 = (section.metabolismLightScale as number) * v22
        + (section.metabolismLightOffset as number) * 0.5;
    if (v34 >= 0) {
        if (v34 > 1.0) v34 = 1.0;
    } else {
        v34 = 0;
    }
    section.lastLightFactor = v34 as Float32;

    // §3: parent budget (как в прежней реализации)
    if (section.parent) {
        const parentBudget = section.parent.energyBudget432 as number;
        if (parentBudget <= 0.01) {
            const drain = rng.randFloat() * 0.025 * (1.0 - parentBudget / 0.01);
            section.energy = Math.max(0, (section.energy as number) - drain) as Float32;
        }
    }

    // Maintenance cost (sub_416510 / MetabolismService: v24 * b8 * simTicks)
    let v29 = (v34 - b4) / (0.0 - b4);
    if (v29 < 0) v29 = 0;
    if (v29 > 1) v29 = 1;
    const v24 = v29;
    let energy = (section.energy as number) - v24 * b8 * simTicks;
    if (energy < 0) energy = 0;
    if (energy > 1) energy = 1;
    section.energy = energy as Float32;

    const energyVal = section.energy as number;

    // §4: sub_416510 — отрыв листа (один вызов rand, как в декомпиле листовой ветки)
    if (energyVal === 0 || (1.0 - energyVal) * bC > rng.randFloat()) {
        section.markedForDetach236 = true;
        section.skipGrowthTick = true;
        const localSpent = Math.max(0, energyAtStart - (section.energy as number));
        section.energySpent436 = Math.min(1, localSpent * spentScale) as Float32;
        return;
    }

    SectionColorService.applyFrom416510(section, treeAge);

    section.currentGrowth = ((section.baseGrowth as number) * energyVal) as Float32;

    const growthRate = section.growthRate as number;
    // +420 / +424 для листьев: только через updateEnergyScratches → aggregateEnergy420436PostOrder
    // → applySub414E10PostOrderTail (иначе дубль с growthScratchA×scale).

    const maxGrowth = section.maxGrowth as number;
    if (maxGrowth > growthRate) {
        const v27 = v34 * c4;
        const increment = (rng.randFloat() * 0.5 + 0.5) * (energyVal * v27);
        let newRate = growthRate + increment;
        newRate = Math.min(newRate, maxGrowth);
        section.growthRate = newRate as Float32;
        section.growthTarget = (newRate + newRate) as Float32;
    }

    const localSpent = Math.max(0, energyAtStart - (section.energy as number));
    section.energySpent436 = Math.min(1, localSpent * spentScale) as Float32;
}
