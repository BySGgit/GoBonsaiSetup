# GoBonsai Reverse Engineering → TypeScript Migration Guide (Expanded Offsets)

**Перед переносом логики в TS** имеет смысл сначала разобрать декомпил и зафиксировать спецификацию оригинала: см. **[c_truth_extraction_workflow.md](./c_truth_extraction_workflow.md)** (иерархия источников, артефакты Hex-Rays, чеклист на функцию, выходные артефакты).

## 1. System Mapping (C → TS)

### MetabolismService.ts

- sub_416510.c
- sub_4162XX.c

**Responsibility:**

- Light calculation (dot product)
- Energy updates
- Clamping [0..1]
- Random decay

---

### GrowthController.ts

- sub_416510.c (partial)
- sub_415XXX.c

**Responsibility:**

- Growth rate
- Branching logic
- Death conditions

---

### TreeSection.ts

- sub_414XXX.c

**Responsibility:**

- Tree hierarchy
- Child sections
- Virtual method dispatch (branch/split)

---

### TransformService.ts

- sub_408470.c
- Quaternion parts of sub_416510.c

**Responsibility:**

- Rotation
- Quaternion math
- Slerp

---

### math/

- sub_401540.c
- sub_401180.c
- sub_4010C0.c
- sub_40FDE0.c

**Responsibility:**

- Vector operations
- Matrix transforms
- Interpolation

---

### utils/random.ts

- rand() usages

---

### config/growthConstants.ts

- flt_4D63B4
- flt_4D63B8
- flt_4D63BC
- flt_4D63C4

---

### VisualState.ts

- this + 128..131

**Responsibility:**

- Color
- Shader parameters

---

## 2. Key Function Decomposition

### sub_416510.c

Split into:

- Metabolism → light + energy
- Growth → branching + growth
- Transform → rotation + slerp
- Visual → color updates

---

## 3. Expanded Offset Mapping (Full)

### Core Fields (TreeSection / Node)

| Offset     | Meaning            | TS Field      |
| ---------- | ------------------ | ------------- |
| this + 76  | prevData0          | prevData0     |
| this + 77  | prevData1          | prevData1     |
| this + 78  | prevData2          | prevData2     |
| this + 79  | prevData3          | prevData3     |
| this + 108 | baseGrowth         | baseGrowth    |
| this + 109 | currentGrowth      | currentGrowth |
| this + 110 | age                | age           |
| this + 111 | growthRate         | growthRate    |
| this + 112 | growthTarget       | growthTarget  |
| this + 113 | maxGrowth          | maxGrowth     |
| this + 114 | energy / health    | energy        |
| this + 128 | colorR             | color.r       |
| this + 129 | colorG             | color.g       |
| this + 130 | colorB             | color.b       |
| this + 131 | colorA             | color.a       |
| this + 320 | rotationQuaternion | rotation      |
| this + 352 | transformMatrix    | transform     |

### Temporary / Working Buffers

| Offset          | Meaning             | Notes                        |
| --------------- | ------------------- | ---------------------------- |
| this + 35..37   | intermediate vector | temp calculations            |
| this + 41       | scale factor        | temp                         |
| this + 46       | rotation axis       | temp quaternion calculations |
| this + 50       | normalized vector   | used for slerp               |
| this + 51[0..2] | direction vector    | up / forward axes            |

### Static / Global Flags

| Offset           | Meaning              | Notes               |
| ---------------- | -------------------- | ------------------- |
| dword_4DBBA4 & 1 | init flag #1         | lazy initialization |
| dword_4DBBA4 & 2 | init flag #2         | lazy initialization |
| dword_4DBBA4 & 4 | init flag #3         | lazy initialization |
| dword_4DBBA4 & 8 | branching event flag | growth decision     |

### Config Constants (Global Floats)

| Name       | Purpose                     |
| ---------- | --------------------------- |
| flt_4D63B0 | base growth multiplier      |
| flt_4D63B4 | light threshold min         |
| flt_4D63B8 | light threshold max         |
| flt_4D63BC | random growth factor        |
| flt_4D63C0 | slerp factor                |
| flt_4D638C | rotation adjustment         |
| flt_4D6388 | angle limit min             |
| flt_4CA5E8 | auxiliary rotation constant |
| flt_4D5390 | light vector x              |
| flt_4D538C | light vector y              |
| flt_4D5394 | light vector z              |

---

## 4. Behavioral Logic Summary

### Energy Update

- Based on light (dot product)
- Clamped [0..1]
- Random decay applied

### Growth

- growthRate \*= energy
- Accumulates over time

### Branching

- Random probability
- Depends on energy and thresholds

### Rotation

- Quaternion axis rotation
- Slerp smoothing

---

## 5. Migration Strategy

### Step 1

Implement math layer

### Step 2

Implement MetabolismService

### Step 3

Implement GrowthController

### Step 4

Implement Transform logic

### Step 5

Connect TreeSection

---

## 6. Agent Usage Pattern (Gemini)

### Task Template

```
Use these C functions:
- sub_416510.c

Implement ONLY metabolism logic into MetabolismService.ts

Do not output code
Apply changes via IDE tools
```

---

## 7. Critical Notes

- Decompiled code has no semantic names
- Offsets define structure (fully expanded now)
- One C function = multiple TS systems

---

## 8. Next Steps

- Expand mapping for all sub_41XXXX
- Build typed interfaces for TreeSection using offsets
- Replace pointer logic with structured objects

---

END
