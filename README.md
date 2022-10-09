# Wasm with Embind

An improved guide for compiling WASM with Emscripten and Embind.

### Prerequisite

In order to use this repo, following tools are required.

- [Docker](https://docs.docker.com/get-docker/)
- [NodeJS](https://nodejs.org/en/)

### Getting started

This repo consists of 2 sections:

- `lib` a simple library written in C++ that compiles to WASM
- `web-app` a React web app that consumes the WASM module

### Compiling to WASM

- `cd` into `lib`
- Run `./build-wasm.sh`

This script will produce a WASM module which is stored in `dummy-cpp-library.js` and copy it over to the `web-app/src`.

Note: You need to run this script every time you make changes in the C++ code.

### Running the web app

- `cd` into `web-app`
- `npm install`
- `npm start`

The app is available on `http://localhost:3000`.