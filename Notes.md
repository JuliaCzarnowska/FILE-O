# Docker setup
Build the development docker image
```
bash docker/build.sh
```

Start container
```
bash docker/run.sh
```

# Build instructions
Start dev docker container 
```
bash docker/run.sh
```

Configure project and build
```
bash scripts/configure.sh
cmake --build ./build
```

The container doesn't have X forwarding set up, so you have to execute
built binaries from host, e.g.
```
./build/fileo
```

## Visual Studio Code setup
   
<!-- #Important configure argument
"cmake.configureArgs": [
    "-DCMAKE_TOOLCHAIN_FILE=conan/conan_toolchain.cmake"
], -->