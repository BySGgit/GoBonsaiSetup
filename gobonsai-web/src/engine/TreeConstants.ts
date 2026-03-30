export const TREE_CONSTANTS = {
    // sub_408D60.c: Animation steps
    ANIMATION: {
        AGE_STEP: 0.1,
        TRUNK_STEP: 0.25,
        BEND_STEP: 0.25,
        COLOR_STEP: 0.1,
    },

    // sub_416510.c: Metabolism
    METABOLISM: {
        LIGHT_THRESHOLD: 0.4,
        ENERGY_DECAY_BASE: 0.025,
        HEALTH_DECAY_RATE: 0.025,
        ENERGY_GAIN_RATE: 0.025,
        MAINTENANCE_COST_BASE: 0.005,
        CRITICAL_ENERGY: 0.1,
    },

    // sub_408A30.c: Growth & Branching
    GROWTH: {
        MAX_LEVEL: 6,
        YEARLY_AGE_MIN: 0.2,
        YEARLY_AGE_MAX: 1.0,
        THICKNESS_FACTOR_MIN: 0.9,
        THICKNESS_FACTOR_MAX: 1.1,
        BEND_LIMIT: 15.0, 
        THICKNESS_MIN: 10.0, 
    },

    // sub_4093B0.c: Geometry
    GEOMETRY: {
        BASE_RADIUS_FACTOR: 0.03, // v47 = trunkThickness * 0.03
        SEGMENTS_PER_SECTION: 12, 
        RADIAL_SEGMENTS: 32,      // Inner loop breaks at v9 > 32
        HEIGHT_FACTOR: 2.5,
        RADIUS_DECAY: 0.95, 
        TAPER_ROOT: 0.95,
        TAPER_BRANCH: 0.8,
    },

    // Roots logic (crawling effect)
    ROOTS: {
        BASE_RADIUS: 0.08,
        RADIUS_DECAY: 0.8,
        SEGMENTS: 12,
        SEGMENT_HEIGHT: 0.05,
        GNARL_LEVEL_0: 0.8,
        GNARL_LEVEL_N: 1.2,
        MAX_LEVEL: 3,
    }
};
