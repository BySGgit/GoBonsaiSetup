export class BonsaiAudio {
    private audioCtx: AudioContext | null = null;
    private windNoise: AudioWorkletNode | null = null;
    private gainNode: GainNode | null = null;
    private lowPass: BiquadFilterNode | null = null;
    private ambientGain: GainNode | null = null;
    private birdTimer: any = null;

    constructor() {}

    public async init() {
        if (this.audioCtx) return;
        this.audioCtx = new (window.AudioContext || (window as any).webkitAudioContext)();
        
        this.ambientGain = this.audioCtx.createGain();
        this.ambientGain.gain.value = 0.05;
        this.ambientGain.connect(this.audioCtx.destination);

        // Создаем процедурный шум ветра
        await this.createWind();
    }

    private async createWind() {
        if (!this.audioCtx) return;

        // Эмуляция розового шума для ветра
        const bufferSize = 2 * this.audioCtx.sampleRate;
        const noiseBuffer = this.audioCtx.createBuffer(1, bufferSize, this.audioCtx.sampleRate);
        const output = noiseBuffer.getChannelData(0);
        let lastOut = 0.0;
        for (let i = 0; i < bufferSize; i++) {
            const white = Math.random() * 2 - 1;
            output[i] = (lastOut + (0.02 * white)) / 1.02;
            lastOut = output[i];
            output[i] *= 3.5; // Усиление
        }

        const noise = this.audioCtx.createBufferSource();
        noise.buffer = noiseBuffer;
        noise.loop = true;

        this.lowPass = this.audioCtx.createBiquadFilter();
        this.lowPass.type = 'lowpass';
        this.lowPass.frequency.value = 400;
        this.lowPass.Q.value = 1;

        this.gainNode = this.audioCtx.createGain();
        this.gainNode.gain.value = 0.05;

        noise.connect(this.lowPass);
        this.lowPass.connect(this.gainNode);
        this.gainNode.connect(this.audioCtx.destination);
        
        noise.start();
    }

    public updateWind(intensity: number, speed: number) {
        if (!this.lowPass || !this.gainNode || !this.audioCtx) return;
        
        const targetFreq = 200 + (intensity * 800) + (speed * 200);
        const targetGain = 0.02 + (intensity * 0.1);
        
        this.lowPass.frequency.setTargetAtTime(targetFreq, this.audioCtx.currentTime, 0.1);
        this.gainNode.gain.setTargetAtTime(targetGain, this.audioCtx.currentTime, 0.1);

        // Управление общей громкостью эмбиента в зависимости от дня/ночи
        if (this.ambientGain) {
            const ambientTarget = intensity > 0.3 ? 0.05 : 0.01; // Днем громче
            this.ambientGain.gain.setTargetAtTime(ambientTarget, this.audioCtx.currentTime, 1.0);
        }

        // Запуск случайных птиц днем
        if (intensity > 0.6 && !this.birdTimer) {
            this.startAmbient();
        } else if (intensity < 0.4 && this.birdTimer) {
            this.stopAmbient();
        }
    }

    private startAmbient() {
        if (this.birdTimer) return;
        const scheduleBird = () => {
            this.playBird();
            const next = 5000 + Math.random() * 15000;
            this.birdTimer = setTimeout(scheduleBird, next);
        };
        scheduleBird();
    }

    private stopAmbient() {
        if (this.birdTimer) {
            clearTimeout(this.birdTimer);
            this.birdTimer = null;
        }
    }

    public playBird() {
        if (!this.audioCtx || !this.ambientGain) return;
        
        const osc = this.audioCtx.createOscillator();
        const g = this.audioCtx.createGain();
        
        osc.type = 'sine';
        const baseFreq = 2000 + Math.random() * 1000;
        osc.frequency.setValueAtTime(baseFreq, this.audioCtx.currentTime);
        
        // "Чириканье"
        for(let i = 0; i < 3; i++) {
            const t = this.audioCtx.currentTime + i * 0.1;
            osc.frequency.exponentialRampToValueAtTime(baseFreq + 500, t + 0.05);
            osc.frequency.exponentialRampToValueAtTime(baseFreq, t + 0.1);
        }
        
        g.gain.setValueAtTime(0, this.audioCtx.currentTime);
        g.gain.linearRampToValueAtTime(0.02, this.audioCtx.currentTime + 0.05);
        g.gain.exponentialRampToValueAtTime(0.001, this.audioCtx.currentTime + 0.3);
        
        osc.connect(g);
        g.connect(this.ambientGain);
        this.ambientGain.connect(this.audioCtx.destination);
        
        osc.start();
        osc.stop(this.audioCtx.currentTime + 0.3);
    }

    public playWater() {
        if (!this.audioCtx) return;
        
        const osc = this.audioCtx.createOscillator();
        const gain = this.audioCtx.createGain();
        
        osc.type = 'sine';
        osc.frequency.setValueAtTime(800 + Math.random() * 400, this.audioCtx.currentTime);
        osc.frequency.exponentialRampToValueAtTime(100, this.audioCtx.currentTime + 0.2);
        
        gain.gain.setValueAtTime(0.1, this.audioCtx.currentTime);
        gain.gain.exponentialRampToValueAtTime(0.01, this.audioCtx.currentTime + 0.2);
        
        osc.connect(gain);
        gain.connect(this.audioCtx.destination);
        
        osc.start();
        osc.stop(this.audioCtx.currentTime + 0.2);
    }

    public playPrune() {
        if (!this.audioCtx) return;
        
        const osc = this.audioCtx.createOscillator();
        const gain = this.audioCtx.createGain();
        
        // "Щелчок" ножниц (белый шум + фильтр)
        const bufferSize = this.audioCtx.sampleRate * 0.05;
        const buffer = this.audioCtx.createBuffer(1, bufferSize, this.audioCtx.sampleRate);
        const data = buffer.getChannelData(0);
        for (let i = 0; i < bufferSize; i++) {
            data[i] = Math.random() * 2 - 1;
        }
        
        const noise = this.audioCtx.createBufferSource();
        noise.buffer = buffer;
        
        const filter = this.audioCtx.createBiquadFilter();
        filter.type = 'highpass';
        filter.frequency.setValueAtTime(2000, this.audioCtx.currentTime);
        
        gain.gain.setValueAtTime(0.1, this.audioCtx.currentTime);
        gain.gain.exponentialRampToValueAtTime(0.001, this.audioCtx.currentTime + 0.05);
        
        noise.connect(filter);
        filter.connect(gain);
        gain.connect(this.audioCtx.destination);
        
        noise.start();
        noise.stop(this.audioCtx.currentTime + 0.05);
    }
}
