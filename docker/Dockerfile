# syntax=docker/dockerfile:1

FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
ENV DISPLAY=host.docker.internal:0.0

ARG USERNAME=builder
ARG USER_UID=1000
ARG USER_GID=$USER_UID

# Install system dependencies
RUN apt-get update -qq \
    && apt-get -yq install \
        apt-utils \
        ccache \
        clang-format \
        cppcheck \
        doxygen \
        emacs \
        file zip \
        git \
        gpg-agent \
        graphviz \
        libgl1-mesa-dev \
        libxcb-cursor0 \
        libxcb-icccm4 \
        libxcb-keysyms1 \
        libxcb-shape0 \
        libxkbcommon-x11-0 \
        locales \
        make \
        nano \
        neovim \
        ninja-build \
        openssh-client \
        python3 \
        python3-pip \
        rsync \
        socat \
        software-properties-common \
        sudo \
        wget \
    && rm -rf /var/lib/apt/lists/*
    
# Create the non-root user
RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME -s /bin/bash \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

# Set up locale
USER root
RUN apt update && apt -y install locales \
    && locale-gen en_US.UTF-8 \
    && rm -rf /var/lib/apt/lists/*

ENV LANG="en_US.UTF-8" LANGUAGE="en_US:en" LC_ALL="en_US.UTF-8"

# Install conan
RUN python3 -m pip install --upgrade pip setuptools && \
    python3 -m pip install conan aqtinstall

# Add gcc-${GCC_VER}
ARG GCC_VER="11"
RUN add-apt-repository -y ppa:ubuntu-toolchain-r/test \
    && apt-get update -qq && export DEBIAN_FRONTEND=noninteractive \
    && apt-get install -y --no-install-recommends \
        gcc-${GCC_VER} g++-${GCC_VER} gdb \
    && rm -rf /var/lib/apt/lists/*

# Set gcc-${GCC_VER} as default gcc
RUN update-alternatives --install /usr/bin/gcc gcc $(which gcc-${GCC_VER}) 100
RUN update-alternatives --install /usr/bin/g++ g++ $(which g++-${GCC_VER}) 100

# Add current cmake, from Kitware
# TODO: install a specific version instead of latest
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null \
        | gpg --dearmor - | tee /etc/apt/trusted.gpg.d/kitware.gpg >/dev/null \
    && apt-add-repository 'deb https://apt.kitware.com/ubuntu/ jammy main' \
    && apt-get update -qq \
    && apt-get install -y --no-install-recommends cmake \
    && rm -rf /var/lib/apt/lists/*

# Install QT6 and its dependencies
ARG QT=6.8.0
ARG QT_MODULES=all
ARG QT_HOST=linux
ARG QT_TARGET=desktop
ARG QT_ARCH=
RUN aqt install-qt -O /opt/qt \
    ${QT_HOST} ${QT_TARGET} ${QT} ${QT_ARCH} \
    -m ${QT_MODULES}

ENV PATH /opt/qt/${QT}/gcc_64/bin:$PATH
ENV QT_PLUGIN_PATH /opt/qt/${QT}/gcc_64/plugins/
ENV QML_IMPORT_PATH /opt/qt/${QT}/gcc_64/qml/
ENV QML2_IMPORT_PATH /opt/qt/${QT}/gcc_64/qml/

RUN mkdir /conan \
    && chown $USERNAME /conan

# Run rest of the command as the non-root user.
# This is important because conan saves profiles to $HOME.
USER $USERNAME

# Install dependencies using conan
ENV CONAN_SYSREQUIRES_SUDO=0
ENV CONAN_SYSREQUIRES_MODE=enabled
COPY conan/conanfile.txt conanfile.txt 
RUN conan profile detect \
    && conan install -of /conan conanfile.txt --build=missing \
        --settings=build_type=Debug \
    && conan install -of /conan conanfile.txt --build=missing \
        --settings=build_type=Release

ENV CC="gcc"
ENV CXX="g++"

CMD ["/bin/bash"]
