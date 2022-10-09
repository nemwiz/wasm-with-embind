rm -rf dist
docker run --rm -v $(pwd):/src -u $(id -u):$(id -g) emscripten/emsdk emcmake cmake . -B dist
docker run --rm -v $(pwd):/src -u $(id -u):$(id -g) emscripten/emsdk emmake make -C /src/dist/
cp dist/dummy-cpp-library.js ../web-app/src/