# syntax=docker/dockerfile:1

FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
ENV DISPLAY=host.docker.internal:0.0
ENV TZ="Europe/Warsaw"

RUN apt-get update -qq &&  \
    apt-get -yq upgrade && \
    apt-get -yq install \
        software-properties-common sudo wget apt-utils file zip \
        openssh-client gpg-agent socat rsync \
        make ninja-build git \
        python3 python3-pip

# Install conan
RUN python3 -m pip install --upgrade pip setuptools && \
python3 -m pip install conan && \
conan --version

ENV CONAN_SYSREQUIRES_SUDO=0
ENV CONAN_SYSREQUIRES_MODE=enabled

ARG GCC_VER="11"
# Add gcc-${GCC_VER}
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test && \
    apt-get update -qq && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
        gcc-${GCC_VER} g++-${GCC_VER} gdb

# Set gcc-${GCC_VER} as default gcc
RUN update-alternatives --install /usr/bin/gcc gcc $(which gcc-${GCC_VER}) 100
RUN update-alternatives --install /usr/bin/g++ g++ $(which g++-${GCC_VER}) 100

# Add current cmake, from Kitware
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
        | gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null && \
    apt-add-repository 'deb https://apt.kitware.com/ubuntu/ jammy main' && \
    apt-get update -qq && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends cmake

# Install editors
RUN apt-get update -qq && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
        neovim emacs nano

# Install optional dependecies
RUN apt-get update -qq && export DEBIAN_FRONTEND=noninteractive && \
    apt-get install -y --no-install-recommends \
        doxygen graphviz ccache cppcheck

# Install QT6 and its dependencies
RUN apt-get update -qq &&  \
apt-get -yq upgrade && \
apt-get -yq install \
    qt6-base-dev  qt6-declarative-dev\
    libx11-xcb-dev libxcb-dri3-dev libxcb-icccm4-dev libxcb-image0-dev \
    libxcb-keysyms1-dev libxcb-randr0-dev libxcb-render-util0-dev \
    libxcb-render0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-util-dev \
    libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-xkb-dev libgl1-mesa-dev

## Cleanup cached apt data we don't need anymore
RUN apt-get autoremove -y && apt-get clean && \
    rm -rf /var/lib/apt/lists/*

ENV CC="gcc"
ENV CXX="g++"



CMD ["/bin/bash"]
