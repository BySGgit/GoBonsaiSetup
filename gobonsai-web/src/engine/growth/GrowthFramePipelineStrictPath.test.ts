import { describe, it, expect } from "vitest";
import * as THREE from "three";
import { MSVCRand } from "../MSVCRand";
import { GrowthController } from "../GrowthController";
import { GrowthFramePipeline } from "./GrowthFramePipeline";
import { TreeSection } from "../TreeSection";
import { WorldGrowthState } from "../world/WorldGrowthState";
import { SectionRuntimeType } from "../SectionRuntimeType";
import { Sub416510Rotation } from "../math/Sub416510Rotation";
import { writeUnifiedBudget428 } from "./sub414CE0";

describe("GrowthFramePipeline strict path", () => {
  it("calls tickEnvironment before physics even in strict mode", () => {
    const rng = new MSVCRand(42);
    const growth = new GrowthController(rng);
    const stats = growth.initStats();
    const root = new TreeSection(null, 0, rng);
    root.sectionRuntimeType4 = SectionRuntimeType.TreeSectionSeed;
    writeUnifiedBudget428(root, 1.0);
    root.targetRotation.identity();
    root.rotationQuaternion.identity();
    root.rotation.identity();
    Sub416510Rotation.syncBlob80FromQuaternion(root);

    const scene = new THREE.Scene();
    scene.add(root.group);
    const worldGrowth = new WorldGrowthState();
    const pipeline = new GrowthFramePipeline(growth);

    let tickCalls = 0;
    pipeline.run({
      deltaTime: 1 / 60,
      timeSpeed: 1,
      stats,
      root,
      worldGrowth,
      lightIntensity: 1,
      wind: new THREE.Vector3(0, 0, 0),
      treeRoots: [],
      tickEnvironment: () => {
        tickCalls++;
      },
      rng,
      scene,
      strictExeSimPath: true,
    });

    expect(tickCalls).toBe(1);
  });
});

