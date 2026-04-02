import * as THREE from "three";
import { TreeSection } from "../TreeSection";
import { MSVCRand } from "../MSVCRand";
import { GrowthConstants } from "../config/GrowthConstants";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { Float32 } from "../math/MathTypes";

/**
 * sub_40E230 + sub_40E460 — light tracing pipeline.
 *
 * Each frame: pick origins from queue, generate a ray (random or direct light),
 * march through the tree collecting hits, updating lightResponseVec (+196..+212)
 * on each intersected section, applying decay through leaves and twigs.
 *
 * Hit-test: sub_450E30 + sub_450CD0 — broad sub_450860(this+8,this+20 после sub_450A80),
 * narrow sub_450970(this+24,this+36). Перед трассировкой: updateLightSpatialBoundsSub450BD0.
 * Концы луча как в sub_40E460.c:68–71: p0 = pos − dir·200, p1 = pos + dir·200.
 * Экранирование twig: sub_44EE20 (отрезок луча × сегмент ветки).
 */

const MAX_HITS = 30;
/** sub_40E0A0: в exe один лист за тик; при наличии листьев держим 1 для паритета. */
const TRACES_PER_FRAME_LEAVES = 1;
/** Пока нет листьев (только twig-источники) — чуть больше лучей, иначе +196 почти не обновляется. */
const TRACES_PER_FRAME_TWIG_FALLBACK = 8;
/** sub_40E460.c:66–71 — длина полуотрезка луча для sub_450E30/sub_44EE20 */
const RAY_HALF_LEN = 200.0;

const _tmpVec = new THREE.Vector3();
const _tmpDir = new THREE.Vector3();
const _tmpPos = new THREE.Vector3();
const _rayOrigin = new THREE.Vector3();
const _rayP0 = new THREE.Vector3();
const _rayP1 = new THREE.Vector3();
const _randDir = new THREE.Vector3();
const _twigBase = new THREE.Vector3();
const _twigTip = new THREE.Vector3();
/** sub_44EE20: кратчайшее расстояние между отрезками (порт с классики «distance between segments»). */
const _uSeg = new THREE.Vector3();
const _vSeg = new THREE.Vector3();
const _wSeg = new THREE.Vector3();
const _c1Seg = new THREE.Vector3();
const _c2Seg = new THREE.Vector3();
const _deltaRay = new THREE.Vector3();
const _860Tmp = new THREE.Vector3();
/** this+24 — мировая позиция узла для sub_450970 (узкий тест). */
const _worldPos24 = new THREE.Vector3();
const _spatialWorld = new THREE.Vector3();
const _mergeCenterScratch = new THREE.Vector3();
const _mergeDirScratch = new THREE.Vector3();
const _hitSections: TreeSection[] = [];
/** sub_450E10 sort key: sqrt(lenSq)*t (hit[+4] в exe) — по убыванию. */
const _hitSortT: number[] = [];

/** sub_40E0A0: очередь источников лучей (в C — только листья). */
let _leafQueue: TreeSection[] = [];
let _leafQueueIndex = 0;
/** true если в очереди только настоящие листья (не twig-fallback). */
let _lightQueueIsLeafOnly = false;

/** Детерминированный RNG, если пайплайн вызван без rng (редко). */
let _fallbackTraceRng: MSVCRand | undefined;

function traceRng(rng: MSVCRand | undefined): MSVCRand {
    if (rng) return rng;
    if (!_fallbackTraceRng) _fallbackTraceRng = new MSVCRand(0x40e460);
    return _fallbackTraceRng;
}

/**
 * sub_40D610.c — случайный единичный вектор (z равномерно в [-1,1], азимут 2π).
 * Два чтения rand: v6 = 2*(v1/32767)-1.
 */
function sub40D610UnitSphere(out: THREE.Vector3, rng: MSVCRand): void {
    const v1 = rng.rand();
    const r1 = v1 / 32767.0;
    const v6 = r1 + r1 - 1.0;
    const v3 = rng.randFloat() * Math.PI * 2;
    const v4 = 1.0 - v6 * v6;
    const v5 = Math.sqrt(Math.max(0, v4));
    out.set(Math.cos(v3) * v5, Math.sin(v3) * v5, v6);
}

/**
 * sub_40E230.c:66–76: offset = sub_40D610() * a1[5]. В TS: масштаб от размера листа / радиуса ветки.
 */
function lightTracePayloadScaleA1_5(section: TreeSection): number {
    if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
        const m = section.maxGrowth as number;
        return Math.max(0.04, m * 0.35);
    }
    if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig) {
        const r = section.twigRadius444 as number;
        return Math.max(0.03, r * 1.2);
    }
    return 0.08;
}

/** Начало луча: лист — мировая позиция группы; ветка — кончик (+448 по локальной +Y). */
function getLightTraceRayOrigin(section: TreeSection, out: THREE.Vector3): void {
    section.group.getWorldPosition(out);
    if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig) {
        const len = Math.max(0.02, section.twigLength448 as number);
        _tmpVec.set(0, len, 0);
        _tmpVec.applyQuaternion(section.group.quaternion);
        out.add(_tmpVec);
    }
}

function collectTerminalTwigs(section: TreeSection, out: TreeSection[]): void {
    if (section.worldDetached188) return;
    if (section.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig) {
        const hasTwigChild = section.children.some(
            (c) => c.sectionRuntimeType4 === SectionRuntimeType.TreeSectionTwig,
        );
        if (!hasTwigChild) {
            out.push(section);
        }
    }
    for (const c of section.children) {
        collectTerminalTwigs(c, out);
    }
}

export function rebuildLeafQueue(root: TreeSection): void {
    _leafQueue = [];
    _leafQueueIndex = 0;
    _lightQueueIsLeafOnly = false;
    const stack: TreeSection[] = [root];
    while (stack.length) {
        const s = stack.pop()!;
        if (s.worldDetached188) continue;
        if (s.sectionRuntimeType4 === SectionRuntimeType.TreeSectionLeaf) {
            _leafQueue.push(s);
        }
        for (const c of s.children) stack.push(c);
    }
    if (_leafQueue.length > 0) {
        _lightQueueIsLeafOnly = true;
        return;
    }
    // APPROX(original): в exe без листьев очереди нет; берём только концевые twig (кончики кроны), не все сегменты.
    collectTerminalTwigs(root, _leafQueue);
}

/**
 * sub_40E0A0 equivalent: service one leaf per tick from the queue.
 * Call once per frame from the pipeline.
 */
export function serviceLightTraceQueue(
    root: TreeSection,
    _wind: THREE.Vector3,
    rng?: MSVCRand,
): void {
    if (_leafQueue.length === 0) return;

    const r = traceRng(rng);
    const directP = GrowthConstants.FLT_4D8CF0_DIRECT_LIGHT_PERCENT as number;

    const budget = _lightQueueIsLeafOnly
        ? TRACES_PER_FRAME_LEAVES
        : TRACES_PER_FRAME_TWIG_FALLBACK;
    const n = Math.min(budget, _leafQueue.length);
    for (let i = 0; i < n; i++) {
        _leafQueueIndex = _leafQueueIndex % _leafQueue.length;
        const leaf = _leafQueue[_leafQueueIndex];
        _leafQueueIndex++;

        if (leaf.worldDetached188) continue;

        // sub_40E230: позиция + sub_40D610 * a1[5]
        getLightTraceRayOrigin(leaf, _rayOrigin);
        sub40D610UnitSphere(_tmpVec, r);
        _rayOrigin.addScaledVector(_tmpVec, lightTracePayloadScaleA1_5(leaf));

        let dir: THREE.Vector3;
        // sub_40E230.c: if (flt_4D8CF0 > rand/32767) → прямой свет
        if (directP > r.randFloat()) {
            dir = GrowthConstants.LIGHT_VECTOR.clone().normalize();
        } else {
            const pitch = r.randFloat() * Math.PI * 0.5;
            const yaw = r.randFloat() * Math.PI * 2;
            _randDir.set(
                Math.sin(pitch) * Math.cos(yaw),
                Math.cos(pitch),
                Math.sin(pitch) * Math.sin(yaw),
            ).normalize();
            dir = _randDir;
        }

        rayMarchSub40E460(root, _rayOrigin, dir, 1.0);
    }
}

/**
 * sub_40E460: march a ray through the tree, updating light fields on hit sections.
 */
function rayMarchSub40E460(
    root: TreeSection,
    pos: THREE.Vector3,
    dir: THREE.Vector3,
    initialIntensity: number,
): void {
    // sub_40E460.c:68–73 → sub_450E30: p0 = pos − dir·200, p1 = pos + dir·200, delta = p1−p0
    _rayP0.copy(dir).multiplyScalar(-RAY_HALF_LEN).add(pos);
    _rayP1.copy(dir).multiplyScalar(RAY_HALF_LEN).add(pos);
    _deltaRay.subVectors(_rayP1, _rayP0);
    const lenSq = _deltaRay.lengthSq();

    _hitSections.length = 0;
    _hitSortT.length = 0;
    collectHitsSub450CD0(root, _rayP0, _rayP1, _deltaRay, lenSq);

    const indices = _hitSections.map((_, i) => i);
    indices.sort((a, b) => _hitSortT[b] - _hitSortT[a]);

    let intensity = initialIntensity;

    for (const i of indices) {
        const section = _hitSections[i];

        // 3a: update lightResponseVec
        const rate = (section.smoothedLightA as number + 0.01) * 10.0;
        _tmpVec.copy(dir).multiplyScalar(intensity + 0.01);
        _tmpVec.addScaledVector(section.lightResponseVec, rate);
        if (_tmpVec.lengthSq() > 1e-12) _tmpVec.normalize();
        section.lightResponseVec.copy(_tmpVec);

        // 3b: dot product
        const dot = section.lightResponseVec.dot(dir);
        const x = Math.max(0, Math.min(1, -dot));

        // 3c: update smoothed accumulators
        section.smoothedLightA = ((x * intensity + (section.smoothedLightA as number) * 10.0) / 11.0) as Float32;
        section.smoothedLightB = ((intensity + (section.smoothedLightB as number) * 20.0) / 21.0) as Float32;

        // 3e: decay intensity by section type
        const typeId = section.sectionRuntimeType4;
        const decayAmt = GrowthConstants.FLT_4D62EC_LIGHT_DECAY_AMOUNT as number;
        if (typeId === SectionRuntimeType.TreeSectionLeaf) {
            // Leaf decay (byte_4D8227): sub_40D6D0(section) · dir
            if (section.directionVector.lengthSq() > 1e-12) {
                _tmpDir.copy(section.directionVector).normalize();
            } else {
                _tmpDir.set(0, 1, 0).applyQuaternion(section.group.quaternion).normalize();
            }
            const absDot = Math.abs(_tmpDir.dot(dir));
            intensity *= (1.0 - decayAmt * absDot);
        } else if (typeId === SectionRuntimeType.TreeSectionTwig) {
            // byte_4D822A: sub_40E460 + sub_44EE20(луч p0–p1, отрезок ветки)
            const radius = section.twigRadius444 as number;
            const len = Math.max(0.02, section.twigLength448 as number);
            section.group.getWorldPosition(_twigBase);
            _twigTip.set(0, len, 0);
            _twigTip.applyQuaternion(section.group.quaternion);
            _twigTip.add(_twigBase);
            const distSq = segmentSegmentDistanceSq(_rayP0, _rayP1, _twigBase, _twigTip);
            const r2 = radius * radius;
            if (r2 > distSq) {
                intensity *= 0.5;
            }
        }

        if (intensity < 0.01) break;
    }
}

/**
 * this+36 (и «собственная» сфера до sub_450A80): meshScalar36 либо fallback из геометрии.
 */
export function lightTraceInnerRadius36(section: TreeSection): number {
    const m = section.meshScalar36 as number;
    if (m > 1e-5) return m;
    const r = section.twigRadius444 as number;
    const L = section.twigLength448 as number;
    return Math.max(0.1, r, L * 0.5);
}

/**
 * sub_450A80 — минимальная сфера, содержащая две сферы (parent broad vs child broad).
 */
function mergeEnclosingSpheres(
    parentCenter: THREE.Vector3,
    parentR: number,
    childCenter: THREE.Vector3,
    childR: number,
    outCenter: THREE.Vector3,
): number {
    _mergeDirScratch.subVectors(childCenter, parentCenter);
    const dSq = _mergeDirScratch.lengthSq();
    const d = Math.sqrt(dSq);
    if (d < 1e-8) {
        outCenter.copy(parentCenter);
        return Math.max(parentR, childR);
    }
    if (parentR >= d + childR - 1e-5) {
        outCenter.copy(parentCenter);
        return parentR;
    }
    if (childR >= d + parentR - 1e-5) {
        outCenter.copy(childCenter);
        return childR;
    }
    const newR = (d + parentR + childR) * 0.5;
    _mergeDirScratch.multiplyScalar(1 / d);
    outCenter.copy(parentCenter).addScaledVector(_mergeDirScratch, newR - parentR);
    return newR;
}

function updateLightSpatialBoundsRecursive(section: TreeSection): void {
    if (section.worldDetached188) {
        section.lightSpatialRadius20 = 0;
        return;
    }
    for (const c of section.children) {
        updateLightSpatialBoundsRecursive(c);
    }
    section.group.getWorldPosition(_spatialWorld);
    const rSelf = lightTraceInnerRadius36(section);
    _mergeCenterScratch.copy(_spatialWorld);
    let rMerge = rSelf;
    for (const c of section.children) {
        if (c.worldDetached188 || c.lightSpatialRadius20 <= 1e-8) continue;
        rMerge = mergeEnclosingSpheres(
            _mergeCenterScratch,
            rMerge,
            c.lightSpatialCenter8,
            c.lightSpatialRadius20,
            _mergeCenterScratch,
        );
    }
    section.lightSpatialCenter8.copy(_mergeCenterScratch);
    section.lightSpatialRadius20 = rMerge;
}

/**
 * Вызывать после `updateMatrixWorld` на корне: sub_450BD0-подобная фаза + sub_450A80 по детям.
 */
export function updateLightSpatialBoundsSub450BD0(root: TreeSection): void {
    updateLightSpatialBoundsRecursive(root);
}

/**
 * sub_450860.c — расстояние² от отрезка [p0,p1] к центру bound (+8); delta = p1−p0, lenSq = |delta|².
 */
function sub450860DistanceSq(
    delta: THREE.Vector3,
    p0: THREE.Vector3,
    center: THREE.Vector3,
    p1: THREE.Vector3,
    lenSq: number,
): number {
    _860Tmp.subVectors(center, p0);
    const v10 = _860Tmp.dot(delta);
    if (lenSq > v10) {
        if (v10 > 0) {
            const v15 = v10 / lenSq;
            _tmpDir.copy(delta).multiplyScalar(v15).add(p0);
            _860Tmp.subVectors(_tmpDir, center);
        } else {
            _860Tmp.subVectors(p0, center);
        }
        return _860Tmp.lengthSq();
    }
    _860Tmp.subVectors(p1, center);
    return _860Tmp.lengthSq();
}

/**
 * sub_450970.c — ближайшая точка на отрезке к point (+24); возвращает dist² и параметр t∈[0,1] вдоль delta.
 */
function sub450970ClosestSqAndT(
    delta: THREE.Vector3,
    p0: THREE.Vector3,
    point: THREE.Vector3,
    p1: THREE.Vector3,
    lenSq: number,
): { closeDistSq: number; tAlong01: number } {
    _860Tmp.subVectors(point, p0);
    const v11 = _860Tmp.dot(delta);
    if (lenSq > v11) {
        if (v11 > 0) {
            const tRaw = v11 / lenSq;
            _tmpDir.copy(delta).multiplyScalar(tRaw).add(p0);
            _860Tmp.subVectors(_tmpDir, point);
            return { closeDistSq: _860Tmp.lengthSq(), tAlong01: Math.max(0, Math.min(1, tRaw)) };
        }
        _860Tmp.subVectors(p0, point);
        return { closeDistSq: _860Tmp.lengthSq(), tAlong01: 0 };
    }
    _860Tmp.subVectors(p1, point);
    return { closeDistSq: _860Tmp.lengthSq(), tAlong01: 1 };
}

/**
 * sub_450CD0.c — рекурсия по детям только если прошли broad-phase (+20/+8).
 * Декомпил с багом в рекурсивном вызове; здесь: sub_450CD0(child, …).
 */
function collectHitsSub450CD0(
    section: TreeSection,
    p0: THREE.Vector3,
    p1: THREE.Vector3,
    delta: THREE.Vector3,
    lenSq: number,
): void {
    if (_hitSections.length >= MAX_HITS) return;
    if (section.worldDetached188) return;
    if (lenSq < 1e-14) return;

    section.group.getWorldPosition(_worldPos24);

    const outerR =
        section.lightSpatialRadius20 > 1e-6
            ? section.lightSpatialRadius20
            : lightTraceInnerRadius36(section);
    const center8 =
        section.lightSpatialRadius20 > 1e-6
            ? section.lightSpatialCenter8
            : _worldPos24;

    const d860 = sub450860DistanceSq(delta, p0, center8, p1, lenSq);
    const outerSq = outerR * outerR;
    if (outerSq < d860) return;

    const innerR = lightTraceInnerRadius36(section);
    const innerSq = innerR * innerR;
    const { closeDistSq, tAlong01 } = sub450970ClosestSqAndT(
        delta,
        p0,
        _worldPos24,
        p1,
        lenSq,
    );
    if (innerSq > closeDistSq && _hitSections.length < MAX_HITS) {
        const sqrtLen = Math.sqrt(lenSq);
        _hitSections.push(section);
        _hitSortT.push(sqrtLen * tAlong01);
    }

    for (const child of section.children) {
        collectHitsSub450CD0(child, p0, p1, delta, lenSq);
    }
}

/**
 * sub_44EE20 — минимальное расстояние между отрезками P1–Q1 и P2–Q2 (квадрат).
 * Порт логики из «closest distance of approach» (Graphics Gems / Ericson).
 */
function segmentSegmentDistanceSq(
    p1: THREE.Vector3,
    q1: THREE.Vector3,
    p2: THREE.Vector3,
    q2: THREE.Vector3,
): number {
    const EPS = 1e-10;
    _uSeg.subVectors(q1, p1);
    _vSeg.subVectors(q2, p2);
    _wSeg.subVectors(p1, p2);
    const a = _uSeg.dot(_uSeg);
    const b = _uSeg.dot(_vSeg);
    const c = _vSeg.dot(_vSeg);
    const d = _uSeg.dot(_wSeg);
    const e = _vSeg.dot(_wSeg);
    const D = a * c - b * b;
    let sN: number;
    let sD = D;
    let tN: number;
    let tD = D;

    if (D < EPS) {
        sN = 0;
        sD = 1;
        tN = e;
        tD = c;
    } else {
        sN = b * e - c * d;
        tN = a * e - b * d;
        if (sN < 0) {
            sN = 0;
            tN = e;
            tD = c;
        } else if (sN > sD) {
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }

    if (tN < 0) {
        tN = 0;
        if (-d < 0) sN = 0;
        else if (-d > a) sN = sD;
        else {
            sN = -d;
            sD = a;
        }
    } else if (tN > tD) {
        tN = tD;
        if (-d + b < 0) sN = 0;
        else if (-d + b > a) sN = sD;
        else {
            sN = -d + b;
            sD = a;
        }
    }

    const sc = Math.abs(sN) < EPS ? 0 : sN / sD;
    const tc = Math.abs(tN) < EPS ? 0 : tN / tD;

    _c1Seg.copy(_uSeg).multiplyScalar(sc).add(p1);
    _c2Seg.copy(_vSeg).multiplyScalar(tc).add(p2);
    return _c1Seg.distanceToSquared(_c2Seg);
}
