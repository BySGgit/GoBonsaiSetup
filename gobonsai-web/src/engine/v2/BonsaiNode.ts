import * as THREE from 'three';
import { MSVCRand } from '../MSVCRand';
import { BonsaiConfig, NodeType } from './BonsaiConfig';

/**
 * BonsaiNode — основной класс узла дерева.
 * Точно повторяет структуру BonsaiPot из оригинала (544 байта).
 * Каждый узел имеет свою энергию, радиус, матрицу трансформации.
 * 
 * Карта полей оригинала:
 * +0   vtable
 * +4   type (NodeType)
 * +104 localMatrix (4x4)
 * +168 children (list)
 * +172 childCount
 * +180 parent
 * +196 currentEnergy
 * +200 energyConsumed  
 * +204 targetThickness (a1[51])
 * +208 targetBend (a1[52])
 * +212-220 position (vec3)
 * +224-232 growthDirection (vec3)
 * +236-248 currentColor (vec4)
 * +252-264 targetColor (vec4)
 * +276 controller ref
 * +304 currentRotation (quat)
 * +320 targetRotation (quat)
 * +420 photosynthesisEnergy
 * +424 previousRadius
 * +428 radius (current energy/radius)
 * +432 energyBudget (total available)
 * +436 energySpent
 * +440 age (in days)
 * +444 trunkRadius
 * +456 health (0-1)
 * +480 shootCount
 * +484 depth (level in hierarchy)
 * +512 pruneRatio / isPruned
 * +520 budCount
 */
export class BonsaiNode {
    // +4: Тип узла
    public type: NodeType;

    // +168, +172: Дочерние узлы
    public children: BonsaiNode[] = [];

    // +180: Родитель
    public parent: BonsaiNode | null;

    // +104: Локальная матрица трансформации
    public localMatrix: THREE.Matrix4 = new THREE.Matrix4();

    // +196: Текущая энергия узла
    public currentEnergy: number = 0;

    // +200: Потреблённая энергия
    public energyConsumed: number = 0;

    // +204: Целевая толщина ствола (sub_408880:12 — a1[51])
    public targetThickness: number = 0;

    // +208: Целевой изгиб (sub_408880:13 — a1[52])
    public targetBend: number = 0;

    // +212-220: Позиция в пространстве (локальная)
    public position: THREE.Vector3 = new THREE.Vector3();

    // +224-232: Вектор направления роста
    public growthDirection: THREE.Vector3 = new THREE.Vector3(0, 1, 0);

    // +236-248: Текущий цвет (RGBA)
    public currentColor: THREE.Vector4 = new THREE.Vector4(1, 1, 1, 1);

    // +252-264: Целевой цвет
    public targetColor: THREE.Vector4 = new THREE.Vector4(1, 1, 1, 1);

    // +304: Текущий кватернион вращения
    public currentRotation: THREE.Quaternion = new THREE.Quaternion();

    // +320: Целевой кватернион вращения
    public targetRotation: THREE.Quaternion = new THREE.Quaternion();

    // +420: Энергия от фотосинтеза
    public photosynthesisEnergy: number = 0;

    // +424: Предыдущий радиус
    public previousRadius: number = 0;

    // +428: Текущий радиус (энергетический)
    public radius: number = 0;

    // +432: Бюджет энергии (общий доступный)
    public energyBudget: number = 0;

    // +436: Потраченная энергия
    public energySpent: number = 0;

    // +440: Возраст (в днях)
    public age: number = 0;

    // +444: Радиус ствола (физический)
    public trunkRadius: number = 0;

    // +456: Здоровье (0-1)
    public health: number = 1.0;

    // +480: Счётчик побегов
    public shootCount: number = 0;

    // +484: Глубина в иерархии
    public depth: number = 0;

    // +512: Соотношение обрезки / флаг
    public pruneRatio: number = 0;

    // +520: Счётчик почек
    public budCount: number = 0;

    // Three.js объект для рендеринга
    public object3D: THREE.Object3D = new THREE.Object3D();

    // RNG
    private rng: MSVCRand;

    constructor(
        type: NodeType,
        parent: BonsaiNode | null,
        rng: MSVCRand,
        depth: number = 0
    ) {
        this.type = type;
        this.parent = parent;
        this.rng = rng;
        this.depth = depth;

        if (parent) {
            parent.children.push(this);
            parent.object3D.add(this.object3D);
        }
    }

    /** Количество дочерних узлов (+172) */
    get childCount(): number {
        return this.children.length;
    }

    /**
     * sub_408880 — Инициализация параметров роста.
     * Вызывается при создании нового узла.
     */
    public initGrowthParams(): void {
        const rng = this.rng;

        // a1[51] = ((rand/32767) * 0.7 + 0.8) * 9.0
        this.targetThickness = (rng.randFloat() * 0.699999988079071 + 0.800000011920929) * 9.0;

        // a1[52] = ((rand/32767) * 0.4 + 0.8) * 5.0
        this.targetBend = (rng.randFloat() * 0.4000000357627869 + 0.800000011920929) * 5.0;

        // a1[56] = rand * 4.0 - 2.0 (growth direction X)
        const gdx = rng.randFloat() * 4.0 - 2.0;
        // a1[57] = 0.0 (growth direction Y)
        // a1[58] = rand * 4.0 - 2.0 (growth direction Z)
        const gdz = rng.randFloat() * 4.0 - 2.0;
        this.growthDirection.set(gdx, 0.0, gdz);

        // a1[59-61] = a1[63-65] = random colors
        const r = rng.randFloat();
        const g = rng.randFloat();
        const b = rng.randFloat();
        this.currentColor.set(r, g, b, 1.0);
        this.targetColor.set(r, g, b, 1.0);

        // a1[62] = a1[66] = 1.0 (alpha)
        // a1[67] = rand * 0.8 + 0.2 (age)
        this.age = rng.randFloat() * 0.800000011920929 + 0.2000000029802322;

        // a1[68] = rand (targetAge, stored externally)

        // flt_4D7E88 = a1[51] — глобальная толщина ствола
    }

    /**
     * sub_417C90 — Обновление стебля (stem update).
     * Вызывается каждый кадр для каждого узла типа STEM.
     */
    public updateStem(): void {
        const cfg = BonsaiConfig;

        // Рост радиуса: v9 = energy * radiusGrowRate / trunkRadius
        // Защита от деления на 0 и замкнутого круга
        const safeRadius = Math.max(0.01, this.trunkRadius);
        let radiusGrowth = (this.photosynthesisEnergy + 0.001) * cfg.radiusGrowRate / safeRadius;
        if (radiusGrowth > 0.1) radiusGrowth = 0.1;
        this.trunkRadius += radiusGrowth;

        // QuaternionSlerp: D3DXQuaternionSlerp(+304, +304, +320, slerpRate)
        // sub_417C90:24
        this.currentRotation.slerp(this.targetRotation, cfg.quaternionSlerpRate);
        this.currentRotation.normalize();

        // Обновление здоровья: sub_417C90:59-76
        // Если энергия >= minBudEnergy -> здоровье растёт, иначе падает
        if (this.energyBudget >= cfg.minBudEnergy) {
            this.health = Math.min(1.0, this.health + cfg.healthEnergyAdjustment);
        } else {
            this.health = Math.max(0.0, this.health - cfg.healthEnergyAdjustment);
        }

        // Если здоровье <= 0 и родитель здоров -> умирание (sub_417C90:77-86)
        if (this.health <= 0 && this.parent && this.parent.health > 0) {
            const deathChance = this.trunkRadius * 4.0;
            if (this.rng.randFloat() > deathChance
                || ((this.age <= 2000.0 || this.trunkRadius <= 0.1)
                    && this.age > 1000.0
                    && this.rng.randFloat() < 0.01)) {
                this.detach();
            }
        }

        // Применяем трансформацию к Three.js объекту
        this.object3D.quaternion.copy(this.currentRotation);
    }

    /**
     * sub_417620 — Рост листового узла.
     * Вызывается для узлов типа LEAF.
     */
    public updateLeaf(): void {
        const cfg = BonsaiConfig;
        const parent = this.parent;
        if (!parent) return;

        // sub_417620:34-35: Если у родителя только 1 ребёнок,
        // budCount = trunkRadius * 2.5 + 1
        if (parent.childCount === 1) {
            this.budCount = Math.floor(this.trunkRadius * 2.5 + 1.0);
        }

        // sub_417620:36-53: Обновление здоровья листа
        if (this.energyBudget >= cfg.minBudEnergy) {
            this.health = Math.min(1.0, this.health + 0.001);
        } else {
            this.health = Math.max(0.0, this.health - 0.001);
        }

        // sub_417620:54-113: Если здоровье > 0, пытаемся создать побег
        if (this.health > 0) {
            if (this.budCount > 0 && this.energyBudget >= cfg.minBudEnergy) {
                // Вероятность создания побега: energy * 0.04 / maxBudEnergy
                const spawnProb = this.energyBudget * 0.04 / cfg.maxBudEnergy;
                const clampedProb = Math.max(0, Math.min(0.04, spawnProb));

                if (clampedProb > this.rng.randFloat()) {
                    this.spawnShoot();
                }
            }
        } else {
            // Здоровье <= 0: удаляемся
            this.detach();
        }
    }

    /**
     * sub_417620:70-111 — Создание нового побега из листа.
     */
    private spawnShoot(): void {
        const cfg = BonsaiConfig;
        const parent = this.parent;
        if (!parent) return;

        // Расход энергии на создание побега
        this.energySpent += cfg.minBudEnergy;

        // Случайные углы (sub_417620:71-75)
        const yaw = this.rng.randFloat() * Math.PI * 2 - Math.PI;
        const pitch = this.rng.randFloat() * 0.8 - 0.8; // rand * (0 - (-0.8)) - 0.8

        // Создаём новый стебель
        const newStem = new BonsaiNode(NodeType.STEM, parent, this.rng, this.depth);
        newStem.initGrowthParams();

        // Устанавливаем направление роста
        const euler = new THREE.Euler(pitch, 0, -yaw);
        newStem.targetRotation.setFromEuler(euler);
        newStem.currentRotation.copy(newStem.targetRotation);

        // Перенос матрицы трансформации (sub_4158D0, sub_4159C0)
        // Упрощённо: устанавливаем позицию относительно родителя
        newStem.trunkRadius = this.trunkRadius * 0.75;

        ++this.shootCount;

        // Распределение энергии (sub_417620:98-110)
        const parentEnergy = parent.energyBudget;
        const energyRatio = this.radius * parentEnergy / this.energyBudget;
        const childEnergy = (this.rng.randFloat() * 0.7 + 0.3) * energyRatio
            * (Math.min(this.energyBudget, cfg.maxBudEnergy) / parentEnergy);
        
        this.radius -= childEnergy;
        this.pruneRatio = this.radius / parent.radius;
        newStem.radius = childEnergy;
        newStem.previousRadius = this.previousRadius;

        // Уменьшаем счётчик почек
        this.budCount--;
        if (this.budCount <= 0) {
            this.pruneRatio = 0;
            this.radius = 0;
        }
    }

    /**
     * sub_417FF0 — Билатеральное ветвление (branching).
     * Создаёт пару побегов на противоположных сторонах.
     */
    public branch(): void {
        const cfg = BonsaiConfig;
        if (this.childCount === 0) {
            // Нет детей — вызываем корневое ветвление (sub_418660)
            this.branchRoot();
            return;
        }

        // sub_417FF0:53-68: Расчёт доступной энергии на ветвление
        // v33 = apicalGrowthStrength ^ (depth - 1)
        let apicalFactor = 1.0;
        const apical = cfg.apicalGrowthStrength;
        for (let i = 0; i < this.depth - 1; i++) {
            apicalFactor *= (1.0 - apical);
        }

        // v16 = energyBudget - energySpent
        const availableEnergy = this.energyBudget - this.energySpent;
        // v17 = apicalGrowthStrength * (availableEnergy * apicalFactor)
        const branchEnergy = apical * (availableEnergy * apicalFactor);

        if (branchEnergy < cfg.minBudEnergy) return;

        // Обновляем потраченную энергию
        this.energySpent += branchEnergy;

        // sub_417FF0:119-126: Расчёт угла ветвления
        // Используется randomBudRotation и направление света
        const baseAngle = this.rng.randFloat() * cfg.randomBudRotation * 2 - cfg.randomBudRotation;

        // Чередование: нечётные побеги получают +π/2
        let angle = baseAngle;
        if (this.shootCount % 2 === 0) {
            angle += Math.PI / 2;
        }

        const pitchScale = this.rng.randFloat() * 0.5 + 1.0;

        // === Первый побег ===
        const stem1 = new BonsaiNode(NodeType.STEM, this, this.rng, this.depth + 1);
        stem1.initGrowthParams();
        
        const euler1 = new THREE.Euler(0, pitchScale, -angle);
        stem1.targetRotation.setFromEuler(euler1);
        stem1.currentRotation.copy(stem1.targetRotation);

        ++this.shootCount;

        // Энергия первого побега (sub_417FF0:145)
        const energy1 = (this.rng.randFloat() * 0.8 + 0.2) * branchEnergy;
        stem1.radius = energy1;

        // === Второй побег (противоположная сторона) ===
        const oppositeAngle = angle + Math.PI;
        const pitchScale2 = this.rng.randFloat() * 0.5 + 1.0;

        const stem2 = new BonsaiNode(NodeType.STEM, this, this.rng, this.depth + 1);
        stem2.initGrowthParams();

        const euler2 = new THREE.Euler(0, pitchScale2, -oppositeAngle);
        stem2.targetRotation.setFromEuler(euler2);
        stem2.currentRotation.copy(stem2.targetRotation);

        ++this.shootCount;

        // Энергия второго побега (sub_417FF0:171)
        const energy2 = (this.rng.randFloat() * 0.8 + 0.2) * branchEnergy;
        stem2.radius = energy2;
    }

    /**
     * sub_418660 — Корневое ветвление (первый побег от корня).
     */
    private branchRoot(): void {
        const cfg = BonsaiConfig;

        // sub_418660:24-25
        const yaw = this.rng.randFloat() * Math.PI * 2 - Math.PI;
        const pitch = this.rng.randFloat() * 0.3; // (0.3 - 0.0) * rand + 0.0

        // Создаём первый побег
        const stem = new BonsaiNode(NodeType.STEM, this, this.rng, this.depth + 1);
        stem.initGrowthParams();

        const euler = new THREE.Euler(0, pitch, -yaw);
        stem.targetRotation.setFromEuler(euler);
        stem.currentRotation.copy(stem.targetRotation);

        ++this.shootCount;

        // sub_418660:42: Второй побег с вероятностью 0.2
        if (this.energyBudget >= cfg.minBudEnergy && this.rng.randFloat() < 0.2) {
            const oppositeYaw = yaw + Math.PI;
            const pitch2 = this.rng.randFloat() * 0.9 + 0.4;

            const stem2 = new BonsaiNode(NodeType.STEM, this, this.rng, this.depth + 1);
            stem2.initGrowthParams();

            const euler2 = new THREE.Euler(0, pitch2, -oppositeYaw);
            stem2.targetRotation.setFromEuler(euler2);
            stem2.currentRotation.copy(stem2.targetRotation);

            ++this.shootCount;

            // sub_418660:63: Энергия второго побега
            stem2.radius = (this.rng.randFloat() * 0.1 + 0.9) * (pitch / 0.3);
        }
    }

    /**
     * sub_416510 — Метаболизм узла (фотосинтез + вращение).
     * Вызывается для каждого листового/стеблевого узла.
     */
    public updateMetabolism(lightDir: THREE.Vector3): void {
        const cfg = BonsaiConfig;

        // Вычисление освещённости через dot product
        const worldUp = new THREE.Vector3(0, 1, 0);
        worldUp.applyQuaternion(this.currentRotation);
        
        const dotProduct = Math.abs(worldUp.dot(lightDir));
        const lightFactor = Math.max(0.1, dotProduct); // Минимум 0.1 чтобы всегда был рост

        // Энергия = radius * light * health * production + базовая
        this.photosynthesisEnergy = (this.trunkRadius * lightFactor * this.health * cfg.leafEnergyProduction) + 0.0005;

        // Накапливаем энергию
        this.currentEnergy += this.photosynthesisEnergy;
    }

    /**
     * sub_417440 — Обновление направления роста (wiggle).
     * Добавляет небольшое случайное отклонение.
     */
    public updateGrowthDirection(): void {
        if (this.childCount > 0 || this.energyBudget <= 0) return;

        // sub_417440:11-15
        const dx = this.rng.randFloat() * 0.16 - 0.08;
        const dz = this.rng.randFloat() * 0.16 - 0.08;

        // Создаём небольшое отклонение и применяем к целевому вращению
        const wiggle = new THREE.Euler(dx, 0, dz);
        const wiggleQuat = new THREE.Quaternion().setFromEuler(wiggle);
        this.targetRotation.multiply(wiggleQuat);
    }

    /**
     * Рекурсивное обновление всего поддерева.
     */
    public updateRecursive(lightDir: THREE.Vector3): void {
        // Обновляем метаболизм
        this.updateMetabolism(lightDir);

        // Обновляем в зависимости от типа
        switch (this.type) {
            case NodeType.STEM:
                this.updateStem();
                break;
            case NodeType.LEAF:
                this.updateLeaf();
                break;
            case NodeType.ROOT:
                // Корень просто передаёт энергию вниз
                break;
        }

        // Обновляем рост
        this.updateGrowthDirection();

        // Рекурсия по детям
        // Итерируем по копии, т.к. дети могут добавляться/удаляться
        const childrenCopy = [...this.children];
        for (const child of childrenCopy) {
            child.updateRecursive(lightDir);
        }
    }

    /**
     * Отсоединение узла от родителя (смерть/обрезка).
     */
    public detach(): void {
        if (!this.parent) return;
        const idx = this.parent.children.indexOf(this);
        if (idx !== -1) {
            this.parent.children.splice(idx, 1);
            this.parent.object3D.remove(this.object3D);
        }
        this.parent = null;
    }

    /**
     * Подсчёт общего количества узлов в поддереве.
     */
    public countNodes(): number {
        let count = 1;
        for (const child of this.children) {
            count += child.countNodes();
        }
        return count;
    }

    /**
     * Сериализация для сохранения.
     */
    public serialize(): any {
        return {
            type: this.type,
            depth: this.depth,
            radius: this.radius,
            trunkRadius: this.trunkRadius,
            health: this.health,
            age: this.age,
            energyBudget: this.energyBudget,
            currentEnergy: this.currentEnergy,
            targetThickness: this.targetThickness,
            targetBend: this.targetBend,
            position: { x: this.position.x, y: this.position.y, z: this.position.z },
            growthDirection: { x: this.growthDirection.x, y: this.growthDirection.y, z: this.growthDirection.z },
            currentRotation: { x: this.currentRotation.x, y: this.currentRotation.y, z: this.currentRotation.z, w: this.currentRotation.w },
            targetRotation: { x: this.targetRotation.x, y: this.targetRotation.y, z: this.targetRotation.z, w: this.targetRotation.w },
            currentColor: { x: this.currentColor.x, y: this.currentColor.y, z: this.currentColor.z, w: this.currentColor.w },
            shootCount: this.shootCount,
            budCount: this.budCount,
            children: this.children.map(c => c.serialize()),
        };
    }

    /**
     * Десериализация из сохранения.
     */
    public static deserialize(data: any, parent: BonsaiNode | null, rng: MSVCRand): BonsaiNode {
        const node = new BonsaiNode(data.type, parent, rng, data.depth);
        node.radius = data.radius ?? 0;
        node.trunkRadius = data.trunkRadius ?? 0;
        node.health = data.health ?? 1;
        node.age = data.age ?? 0;
        node.energyBudget = data.energyBudget ?? 0;
        node.currentEnergy = data.currentEnergy ?? 0;
        node.targetThickness = data.targetThickness ?? 0;
        node.targetBend = data.targetBend ?? 0;
        
        if (data.position) node.position.set(data.position.x, data.position.y, data.position.z);
        if (data.growthDirection) node.growthDirection.set(data.growthDirection.x, data.growthDirection.y, data.growthDirection.z);
        if (data.currentRotation) node.currentRotation.set(data.currentRotation.x, data.currentRotation.y, data.currentRotation.z, data.currentRotation.w);
        if (data.targetRotation) node.targetRotation.set(data.targetRotation.x, data.targetRotation.y, data.targetRotation.z, data.targetRotation.w);
        if (data.currentColor) node.currentColor.set(data.currentColor.x, data.currentColor.y, data.currentColor.z, data.currentColor.w);

        node.shootCount = data.shootCount ?? 0;
        node.budCount = data.budCount ?? 0;

        if (data.children) {
            for (const childData of data.children) {
                BonsaiNode.deserialize(childData, node, rng);
            }
        }

        return node;
    }
}
