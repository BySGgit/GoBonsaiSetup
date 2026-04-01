/**
 * Per-frame global state shared across growth modules.
 * Mirrors C globals like dword_4D7EE8 + 216 (simulation day).
 * Extracted to avoid circular imports between virtualSlot36 ↔ branching.
 */
let _simulationDay = 0;

export function setSlot36SimulationDay(day: number): void {
    _simulationDay = day;
}

export function getSlot36SimulationDay(): number {
    return _simulationDay;
}
