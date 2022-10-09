import {Item} from './item';

export interface WasmModule {
    ItemVector: typeof ItemVector;
    getTotal: (items: Vector<Item>) => number;
    ItemStatus: {
        ItemStatus_InStock: number;
        ItemStatus_OutOfStock: number;
        ItemStatus_Unknown: number;
    }
    printEnum: (status: number) => void;
}

export interface Vector<T> {
    push_back: (record: T) => void;
}

export var ItemVector: {
    new(): Vector<Item>;
}