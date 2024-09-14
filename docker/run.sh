#!/usr/bin/env sh
IMAGE=fileo-dev

docker run -it --rm  \
    -u ${UID} \
    -v ${PWD}:/code \
    -w /code \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -v /run/user/1000/gdm/Xauthority:/Xauthority \
    -e DISPLAY=${DISPLAY} \
    -e XAUTHORITY=/Xauthority \
    ${IMAGE}
