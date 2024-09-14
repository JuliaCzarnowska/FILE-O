BUILD_TYPE=Debug

cmake -B ${PWD}/build \
    -G Ninja \
    -DCMAKE_BUILD_TYPE=${BUILD_TYPE} \
    -DCMAKE_PREFIX_PATH=/conan \
    -DCMAKE_TOOLCHAIN_FILE=/conan/conan_toolchain.cmake \
    ${PWD}
