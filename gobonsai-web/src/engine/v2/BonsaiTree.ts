import * as THREE from 'three';
import { MSVCRand } from '../MSVCRand';
import { BonsaiConfig, NodeType } from './BonsaiConfig';
import { BonsaiNode } from './BonsaiNode';

/**
 * BonsaiTree — контроллер дерева (аналог BonsaiController из оригинала).
 * Владеет корневым узлом и управляет глобальными параметрами:
 * энергия, здоровье, полив, день года, обновление роста.
 * 
 * Логика из full.c: updateGrowth (sub_40DC90 area, lines 12663-12768)
 */
export class BonsaiTree {
    // Корневой узел дерева
    public root: BonsaiNode;

    // Глобальная энергия дерева (full.c: *(v0 + 196))
    public totalEnergy: number = 1.0;

    // День года (full.c: *(v0 + 216))
    public dayOfYear: number = 0;

    // Направление света
    public lightDirection: THREE.Vector3 = new THREE.Vector3(0.5, 1.0, 0.3).normalize();

    // Скорость времени
    public timeSpeed: number = 1.0;

    // Полив (влага)
    public waterLevel: number = 0.5;

    // Three.js корневая группа
    public scene: THREE.Group = new THREE.Group();

    // RNG
    public rng: MSVCRand;

    // Текущий «год» для ветвления
    private previousYearIndex: number = 0;

    constructor(seed?: number) {
        this.rng = new MSVCRand(seed ?? Date.now());

        // Создаём корневой узел (sub_408700)
        this.root = new BonsaiNode(NodeType.ROOT, null, this.rng, 0);
        this.root.initGrowthParams();
        this.root.radius = 1.0;
        this.root.energyBudget = 1.0;
        this.root.health = 1.0;

        this.scene.add(this.root.object3D);

        // sub_408700:46-60: Копируем начальные параметры
        this.root.currentEnergy = this.root.targetThickness;
        this.root.energyConsumed = this.root.targetBend;

        // Создаём первый стебель (sub_408700 вызывает sub_408880, потом сразу создаётся
        // первый узел-стебель через sub_417440 -> sub_4159C0)
        this.createInitialStem();
    }

    /**
     * Создание начального стебля дерева.
     */
    private createInitialStem(): void {
        const stem = new BonsaiNode(NodeType.STEM, this.root, this.rng, 1);
        stem.initGrowthParams();
        stem.radius = this.root.targetThickness;
        stem.trunkRadius = 0.5; // Видимый начальный размер
        stem.energyBudget = this.totalEnergy;
        stem.health = 1.0;
        stem.age = 100; // Стартовый возраст для немедленного роста

        // Начальный лист на конце стебля
        const leaf = new BonsaiNode(NodeType.LEAF, stem, this.rng, 2);
        leaf.initGrowthParams();
        leaf.radius = stem.radius * 0.5;
        leaf.trunkRadius = 0.1;
        leaf.health = 1.0;
        leaf.energyBudget = this.totalEnergy * 0.5;
        leaf.budCount = 3;
    }

    /**
     * Главный цикл обновления — вызывается каждый кадр.
     * Логика из full.c updateGrowth (lines 12663-12768).
     */
    public update(deltaTime: number): void {
        const cfg = BonsaiConfig;
        if (!cfg.updateGrowth) return;

        const dt = deltaTime * this.timeSpeed * 5;

        // dayOfYear += dt
        this.dayOfYear += dt;

        // Проверка нового года
        const currentYearIndex = Math.floor(this.dayOfYear / 365.0);
        if (currentYearIndex > this.previousYearIndex) {
            this.previousYearIndex = currentYearIndex;
            this.onNewYear();
        }

        // Распределяем энергию ВНИЗ по дереву
        this.distributeEnergy(this.root, this.totalEnergy);

        // Рекурсивное обновление всех узлов
        this.root.updateRecursive(this.lightDirection);

        // Собираем фотосинтез и траты
        const totalPhoto = this.collectPhotosynthesis(this.root);
        const totalSpent = this.collectEnergySpent(this.root);
        this.totalEnergy = this.totalEnergy - totalSpent + totalPhoto;

        // Утечка
        this.totalEnergy *= cfg.energyLeak;
        this.totalEnergy = Math.max(0.01, this.totalEnergy); // Никогда не 0

        // Влага
        this.waterLevel = Math.max(0, this.waterLevel - 0.0001 * dt);

        // Рандомные обрезки
        if (cfg.randomAutoCuts && this.rng.randFloat() < 0.01) {
            this.randomAutoCut();
        }
    }

    /**
     * Распределение энергии вниз по дереву.
     * Каждый узел получает долю от родителя.
     */
    private distributeEnergy(node: BonsaiNode, available: number): void {
        node.energyBudget = available;
        if (node.children.length === 0) return;
        const perChild = available / node.children.length;
        for (const child of node.children) {
            this.distributeEnergy(child, perChild);
        }
    }

    /**
     * full.c:12720-12728: Обработка нового года.
     * Вызывает sub_408A30 для корневого стебля и запускает ветвление.
     */
    private onNewYear(): void {
        const cfg = BonsaiConfig;

        // sub_408A30: Обновление целей для корневого стебля
        if (this.root.children.length > 0) {
            const mainStem = this.root.children[0];
            this.updateYearlyTargets(mainStem);
        }

        // full.c:12724: Уменьшение энергии при смене года
        // v7 = energy * 0.9
        // energy = v7 * (1.0 - flt_4D7EF4)
        this.totalEnergy *= 0.9;

        // Ветвление: вызываем branch() для подходящих узлов
        this.triggerBranching(this.root);
    }

    /**
     * sub_408A30 — Обновление годовых целей для узла.
     */
    private updateYearlyTargets(node: BonsaiNode): void {
        const rng = this.rng;

        // sub_408A30:36-43: Новые целевые цвета
        node.targetColor.set(rng.randFloat(), rng.randFloat(), rng.randFloat(), 1.0);

        // sub_408A30:48: Новый целевой возраст
        node.age += rng.randFloat() * 0.8 + 0.2;

        // sub_408A30:52-54: Новая целевая толщина
        const thickFactor = rng.randFloat() * 0.2 + 0.9;
        node.targetThickness *= thickFactor;
        if (node.targetThickness < 10.0) {
            node.targetThickness = 10.0;
        }

        // sub_408A30:56-57: Новый целевой изгиб
        const bendFactor = rng.randFloat() * 0.2 + 0.9;
        node.targetBend = bendFactor * node.targetBend * 2.0;
        if (node.targetBend > 15.0) {
            node.targetBend = 15.0;
        }

        // Рекурсия по детям
        for (const child of node.children) {
            this.updateYearlyTargets(child);
        }
    }

    /**
     * Запуск ветвления для подходящих узлов.
     */
    private triggerBranching(node: BonsaiNode): void {
        const cfg = BonsaiConfig;

        if (node.type === NodeType.STEM && node.energyBudget >= cfg.minBudEnergy) {
            // sub_417FF0: Ветвление стебля
            if (node.childCount > 0 && node.depth < 10) {
                node.branch();
            }
        }

        for (const child of [...node.children]) {
            this.triggerBranching(child);
        }
    }

    /**
     * Подсчёт листьев.
     */
    private countLeaves(): number {
        return this.countNodesByType(this.root, NodeType.LEAF);
    }

    private countNodesByType(node: BonsaiNode, type: NodeType): number {
        let count = node.type === type ? 1 : 0;
        for (const child of node.children) {
            count += this.countNodesByType(child, type);
        }
        return count;
    }

    /**
     * Сбор фотосинтеза со всех узлов.
     */
    private collectPhotosynthesis(node: BonsaiNode): number {
        let total = node.photosynthesisEnergy;
        node.photosynthesisEnergy = 0; // Сброс после сбора
        for (const child of node.children) {
            total += this.collectPhotosynthesis(child);
        }
        return total;
    }

    /**
     * Сбор потраченной энергии со всех узлов.
     */
    private collectEnergySpent(node: BonsaiNode): number {
        let total = node.energySpent;
        node.energySpent = 0;
        for (const child of node.children) {
            total += this.collectEnergySpent(child);
        }
        return total;
    }

    /**
     * Полив дерева.
     */
    public water(amount: number = 0.3): void {
        this.waterLevel = Math.min(1.0, this.waterLevel + amount);
        this.totalEnergy += amount * 0.5;
    }

    /**
     * Обрезка ветки.
     */
    public prune(node: BonsaiNode): void {
        if (node === this.root) return;
        node.detach();
    }

    /**
     * Случайная обрезка (full.c:12696-12717).
     */
    private randomAutoCut(): void {
        const allNodes = this.getAllNodes();
        const stems = allNodes.filter(n => n.type === NodeType.STEM && n.health > 0);
        if (stems.length > 0 && this.rng.randFloat() < 0.01) {
            const target = stems[Math.floor(this.rng.randFloat() * stems.length)];
            target.detach();
        }
    }

    /**
     * Получение всех узлов дерева.
     */
    public getAllNodes(): BonsaiNode[] {
        const nodes: BonsaiNode[] = [];
        this.collectNodes(this.root, nodes);
        return nodes;
    }

    private collectNodes(node: BonsaiNode, result: BonsaiNode[]): void {
        result.push(node);
        for (const child of node.children) {
            this.collectNodes(child, result);
        }
    }

    /**
     * Получение статистики дерева (для UI).
     */
    public getStats(): {
        totalEnergy: number;
        health: number;
        waterLevel: number;
        dayOfYear: number;
        nodeCount: number;
        leafCount: number;
        age: number;
    } {
        return {
            totalEnergy: this.totalEnergy,
            health: this.root.children.length > 0 ? this.root.children[0].health : 0,
            waterLevel: this.waterLevel,
            dayOfYear: this.dayOfYear % 365,
            nodeCount: this.root.countNodes(),
            leafCount: this.countLeaves(),
            age: Math.floor(this.dayOfYear / 365),
        };
    }

    /**
     * Сериализация для сохранения в localStorage.
     */
    public serialize(): any {
        return {
            totalEnergy: this.totalEnergy,
            dayOfYear: this.dayOfYear,
            waterLevel: this.waterLevel,
            timeSpeed: this.timeSpeed,
            root: this.root.serialize(),
        };
    }

    /**
     * Загрузка из сохранения.
     */
    public static deserialize(data: any, seed?: number): BonsaiTree {
        const tree = new BonsaiTree(seed);
        
        // Удаляем дефолтные узлы
        tree.root.object3D.clear();
        tree.root.children = [];

        tree.totalEnergy = data.totalEnergy ?? 1.0;
        tree.dayOfYear = data.dayOfYear ?? 0;
        tree.waterLevel = data.waterLevel ?? 0.5;
        tree.timeSpeed = data.timeSpeed ?? 1.0;
        tree.previousYearIndex = Math.floor(tree.dayOfYear / 365.0);

        // Восстанавливаем дерево
        if (data.root) {
            tree.scene.remove(tree.root.object3D);
            tree.root = BonsaiNode.deserialize(data.root, null, tree.rng);
            tree.scene.add(tree.root.object3D);
        }

        return tree;
    }
}
