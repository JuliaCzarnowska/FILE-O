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
To get X11 forwarding working and be able to open graphical programs
inside the container you need to run `sudo xhost +`. This has a cleaner
solution but it's not implemented yet.

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

Configure VSCode CMake extension to find dependencies installed by Conan.
Add the following to your workspace `.vscode/settings.json`:

```
"cmake.configureArgs": ["-DCMAKE_TOOLCHAIN_FILE=conan/conan_toolchain.cmake"]
```