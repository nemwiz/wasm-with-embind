#ifndef ITEM_HPP
#define ITEM_HPP

#include "common.h"
#include "item-status.hpp"

namespace dummy
{
    struct Item;
    typedef std::vector<Item> ItemVector;

    struct Item
    {
        int32t id;
        String name;
        int32t price;
        ItemStatus status;

        Item()
        {
            id = 0;
            status = ItemStatus_InStock;
        }

        Item(int32t id, int32t price, const String &name, ItemStatus status)
        {
            this->id = id;
            this->price = price;
            this->name = name;
            this->status = status;
        }

        friend std::ostream &operator<<(std::ostream &os, const Item &item)
        {
            os << "Item ("
               << "id: [" << item.id << "]"
               << "price: [" << item.price << "]"
               << " name: [" << item.name << "]"
               << " status: [" << item.status << "]"
               << ")";
            return os;
        }
    };
};

#endif