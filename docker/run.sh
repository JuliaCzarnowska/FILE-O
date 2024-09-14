#!/usr/bin/env sh
IMAGE=fileo-dev

docker run -it --rm  \
    -u ${UID} \
    -v ${PWD}:/code \
    -w /code \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e DISPLAY=${DISPLAY} \
    ${IMAGE}

# If I run with local userid cmake can't find conan files in /conan
# TODO: fix