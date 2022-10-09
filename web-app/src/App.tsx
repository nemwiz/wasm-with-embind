import React, {useEffect, useState} from 'react';
import './App.css';
import DummyCppLibrary from './dummy-cpp-library';
import {WasmModule} from './model/wasm';
import {Item} from './model/item';
import {getRandomNumberInRange} from './random';
import {animals, uniqueNamesGenerator} from 'unique-names-generator';
import ItemsTable from './components/ItemsTable';

const INITIAL_PRICE = 345;

function App() {

    const [wasmModule, setWasmModule] = useState<WasmModule>();
    const [items, setItems] = useState<Item[]>([
        {id: 1, price: INITIAL_PRICE, name: uniqueNamesGenerator({dictionaries: [animals]}), status: 0}
    ]);
    const [total, setTotal] = useState<number>(INITIAL_PRICE);

    useEffect(() => {
        DummyCppLibrary().then((wasmModule: WasmModule) => setWasmModule(wasmModule));
    }, []);


    const addDummyItemAndCalculateTotal = () => {

        if (wasmModule) {

            const newItemId = items[items.length - 1].id + 1;
            const newItems = items.concat([{
                id: newItemId,
                name: uniqueNamesGenerator({dictionaries: [animals]}),
                price: getRandomNumberInRange(1, 1000),
                status: wasmModule.ItemStatus.ItemStatus_InStock
            }]);

            const itemVector = new wasmModule.ItemVector();
            newItems.forEach(item => itemVector.push_back(item));

            setTotal(wasmModule.getTotal(itemVector));
            setItems(newItems);
        }

    };

    return (
        <div className="App">
            <header className="App-header">
                <p>
                    This is a dummy shopping cart. By pressing the button below, you will add dummy items to the cart
                    and the C++ library will calculate the total.
                </p>

                <ItemsTable items={items} total={total}/>
                <button className={'App-button'} onClick={() => addDummyItemAndCalculateTotal()}>Add item
                </button>
            </header>

        </div>
    );
}

export default App;
