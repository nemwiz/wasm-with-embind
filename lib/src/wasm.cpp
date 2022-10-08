#include "common.h"
#include "record.hpp"

#include <emscripten/bind.h>

using namespace emscripten;
using namespace dummy;

// Useful for debugging, see https://emscripten.org/docs/porting/Debugging.html#handling-c-exceptions-from-javascript
std::string getExceptionMessage(intptr_t exceptionPtr) {
  return std::string(reinterpret_cast<std::exception *>(exceptionPtr)->what());
}

EMSCRIPTEN_BINDINGS(wasm_module) {
    emscripten::function("getExceptionMessage", &getExceptionMessage);
}