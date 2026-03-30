export class MSVCRand {
    private state: number;

    constructor(seed: number = 1) {
        this.state = seed;
    }

    srand(seed: number): void {
        this.state = seed;
    }

    rand(): number {
        this.state = (Math.imul(this.state, 214013) + 2531011) & 0x7FFFFFFF;
        return (this.state >> 16) & 0x7FFF;
    }

    randFloat(): number {
        return this.rand() / 32767.0;
    }
}
