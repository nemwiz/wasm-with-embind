message(STATUS "Compiling WASM module...")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_definitions(-DICA_TEST)

set(EXECUTABLE_NAME ${PROJECT_NAME})
set(EXECUTABLE_SOURCE src/wasm.cpp)

add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_SOURCE})
target_include_directories(${EXECUTABLE_NAME} PRIVATE .)
set_target_properties(${EXECUTABLE_NAME} PROPERTIES LINK_FLAGS "-sENVIRONMENT=web -s SINGLE_FILE=1 -s MODULARIZE -s 'EXPORT_NAME=DummyCppLibrary' --bind")
