/**
 * Публичные точки входа движка. Подробная карта: ./ENGINE.md
 */

export { BonsaiController } from "./BonsaiController";
export { BonsaiAudio } from "./BonsaiAudio";
export { PotService } from "./PotService";
export { EnvironmentService } from "./EnvironmentService";

export { TreeSection } from "./TreeSection";
export { TreeRoot } from "./TreeRoot";
export { TreeLeaf } from "./TreeLeaf";
export { TreeFlower } from "./TreeFlower";

export { GrowthController, type GrowthStats } from "./GrowthController";
export { GrowthFramePipeline } from "./growth/GrowthFramePipeline";
export { resolveStrictExeSimPath } from "./growth/strictExeSimPath";
export { sub414CE0Yearly } from "./growth/sub414CE0";
export { maybeRandomAutoCutsSub40DC902 } from "./growth/sub40DC90RandomAutoCuts";
export { MSVCRand } from "./MSVCRand";

export { WorldGrowthState } from "./world/WorldGrowthState";
export { seasonFactorSub40EE60 } from "./world/seasonCurveSub40EE60";

export { TREE_CONSTANTS } from "./TreeConstants";
export { GrowthConstants } from "./config/GrowthConstants";
export { SectionRuntimeType } from "./SectionRuntimeType";
export {
  dispatchVirtualSlot36,
  runVirtualSlot36Tree,
  maybeSeedSpawnSub417440,
} from "./growth/virtualSlot36";
export { setSlot36SimulationDay } from "./growth/frameState";
export { twigUpdateSub417C90 } from "./growth/twigUpdateSub417C90";
export { twigLengthGrowthSub418BD0 } from "./growth/twigLengthGrowthSub418BD0";
export { branchingDispatcherSub417F40 } from "./growth/branchingDispatcherSub417F40";
export {
  serviceLightTraceQueue,
  rebuildLeafQueue,
  updateLightSpatialBoundsSub450BD0,
  lightTraceInnerRadius36,
} from "./growth/lightTracingSub40E460";
export { perFramePhysicsSub4143E0 } from "./growth/perFramePhysicsSub4143E0";
export {
  processDetachFlags,
  getWorldObjects,
  clearWorldObjects,
} from "./growth/detachPipelineSub40EEE0";
export { updateWorldObjectsSub40F140 } from "./growth/worldObjectPipelineSub40F140";
export {
  resolveMaterialColor,
  setMaterialColorMode,
} from "./growth/materialCurveSub4151B0";
export {
  propagateTransformsSub450BD0,
  syncGroupQuaternionsFromRotationForMetabolism,
} from "./growth/transformChainSub450BD0";
export { processLeafMetabolism } from "./growth/leafMetabolismSub416510";
