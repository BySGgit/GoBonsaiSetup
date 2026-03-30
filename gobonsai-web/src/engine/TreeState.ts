import * as THREE from 'three';

export interface TreeTrunkParams {
    thickness: number;
    bend: number;
    color: THREE.Color;
}

export interface TreeBranchState {
    level: number;
    currentBranchScale: number;
    branchPosition: number;
    branchBaseRadius: number;
    branchTipRadius: number;
    rotation: THREE.Vector3;
    targetRotation: THREE.Vector3;
    hasWire: boolean;
    isPruned: boolean;
}

export interface BonsaiState {
    age: number;
    targetAge: number;
    energy: number;
    health: number;
    trunkThickness: number;
    targetThickness: number;
    trunkBend: number;
    targetBend: number;
    color: THREE.Color;
    targetColor: THREE.Color;
}
