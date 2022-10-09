#ifndef ORDER_HPP
#define ORDER_HPP

#include "common.h"

namespace dummy {

class Order
{
public:
    static long calculateTotal(const ItemVector& items) {

        long total = 0;

        for (size_t i = 0; i < items.size(); ++i) {
            printf("Processing %s with price %d \n", items[i].name.c_str(), items[i].price);
            total = total + items[i].price;
        };

         return total;
    }

    static void printEnum(const ItemStatus& status) {
        printf("Enum value is %d \n", status);
    }

};

};

#endif