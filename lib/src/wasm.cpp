#include "common.h"
#include "item.hpp"
#include "item-status.hpp"
#include "order.hpp"

#include <emscripten/bind.h>

using namespace emscripten;
using namespace dummy;

// Useful for debugging, see https://emscripten.org/docs/porting/Debugging.html#handling-c-exceptions-from-javascript
std::string getExceptionMessage(intptr_t exceptionPtr) {
  return std::string(reinterpret_cast<std::exception *>(exceptionPtr)->what());
}

EMSCRIPTEN_BINDINGS(wasm_module) {
    emscripten::function("getExceptionMessage", &getExceptionMessage);

    function("getTotal", &Order::calculateTotal);
    function("printEnum", &Order::printEnum);

    register_vector<Item>("ItemVector");

    value_object<Item>("Item")
        .field("id", &Item::id)
        .field("price", &Item::price)
        .field("name", &Item::name)
        .field("status", &Item::status);

    enum_<ItemStatus>("ItemStatus")
        .value("ItemStatus_InStock", ItemStatus::ItemStatus_InStock)
        .value("ItemStatus_OutOfStock", ItemStatus::ItemStatus_OutOfStock)
        .value("ItemStatus_Unknown", ItemStatus::ItemStatus_Unknown);

}