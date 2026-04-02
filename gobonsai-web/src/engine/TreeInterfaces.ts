import { Float32, D3DXVECTOR3, D3DXQUATERNION, D3DXMATRIX } from './math/MathTypes';

/**
 * C Structure Offset Mappings
 * Based on decompiled_c_to_ts_migration_guide.md
 */

export interface ITreeSectionData {
    // Core Fields (TreeSection / Node)
    prevData0: number;       // this + 76
    prevData1: number;       // this + 77
    prevData2: number;       // this + 78
    prevData3: number;       // this + 79
    baseGrowth: Float32;     // this + 108
    currentGrowth: Float32;  // this + 109
    age: Float32;            // this + 110
    growthRate: Float32;     // this + 111
    growthTarget: Float32;   // this + 112
    maxGrowth: Float32;      // this + 113
    energy: Float32;         // this + 114
    /** sub_416510: *((float*)this+52), *((float*)this+53) */
    metabolismLightScale?: Float32;
    metabolismLightOffset?: Float32;
    /** @deprecated сохранённые стейты */
    lightResponseBias?: Float32;
}

export interface IVisualState {
    colorR: Float32; // this + 128
    colorG: Float32; // this + 129
    colorB: Float32; // this + 130
    colorA: Float32; // this + 131
}

export interface ITransformState {
    rotationQuaternion: D3DXQUATERNION; // this + 320
    /** sub_4146F0 +352: inverse(world), см. TreeSection.syncTransformMatricesFromWorld */
    transformMatrix: D3DXMATRIX;
}

export interface IWorkingBuffers {
    intermediateVector: D3DXVECTOR3; // this + 35..37
    scaleFactor: Float32;            // this + 41
    rotationAxis: D3DXVECTOR3;       // this + 46
    normalizedVector: D3DXVECTOR3;   // this + 50
    directionVector: D3DXVECTOR3;    // this + 51[0..2]
}

export interface IGlobalGrowthConfig {
    baseGrowthMultiplier: Float32; // flt_4D63B0
    lightThresholdMin: Float32;    // flt_4D63B4
    lightThresholdMax: Float32;    // flt_4D63B8
    randomGrowthFactor: Float32;   // flt_4D63BC
    slerpFactor: Float32;          // flt_4D63C0
    rotationAdjustment: Float32;   // flt_4D638C
    angleLimitMin: Float32;        // flt_4D6388
    auxRotationConstant: Float32;  // flt_4CA5E8
    lightVector: D3DXVECTOR3;      // flt_4D5390, flt_4D538C, flt_4D5394
}

export interface IGlobalFlags {
    initFlag1: boolean; // dword_4DBBA4 & 1
    initFlag2: boolean; // dword_4DBBA4 & 2
    initFlag3: boolean; // dword_4DBBA4 & 4
    branchingEvent: boolean; // dword_4DBBA4 & 8
}
