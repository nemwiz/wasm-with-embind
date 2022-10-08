cmake_minimum_required(VERSION 3.10.0)

set(CMAKE_BUILD_TYPE Release)
set(BUILD_TYPE "library")

project(dummy-cpp-library VERSION 0.0.1 DESCRIPTION "Dummy C++ library demo that compiles to WebAssembly")
set(CMAKE_CXX_FLAGS_DEBUG "-DLIB_LOG -DDEBUG")

include(cmake_platforms/wasm.cmake)


