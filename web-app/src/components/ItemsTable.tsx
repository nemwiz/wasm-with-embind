import React, {FC} from 'react';
import {Item} from '../model/item';

const ItemsTable: FC<{items: Item[], total: number}> = ({items, total}) => {
    return (
        <table className={'App-table'}>
            <thead>
            <tr>
                <th>Id</th>
                <th>Name</th>
                <th>Price</th>
            </tr>
            </thead>
            <tbody>
            {items.map((item) =>
                <tr key={item.id}>
                    <td>{item.id}</td>
                    <td>{item.name}</td>
                    <td>{item.price}$</td>
                </tr>)}
            <tr>
                <td></td>
                <td>
                    <b>Total</b>
                </td>
                <td>
                    <b>{total} $</b>
                </td>
            </tr>
            </tbody>
        </table>
    )
};

export default ItemsTable;