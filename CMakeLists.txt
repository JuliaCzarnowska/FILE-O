cmake_minimum_required(VERSION 3.28)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

# Set the project props
project(fileo LANGUAGES CXX C)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
include(GNUInstallDirs)
set(CMAKE_PREFIX_PATH "/usr/lib/x86_64-linux-gnu/cmake/") # TODO: fix this hardcoded path

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2)
qt_add_executable(fileo main.cpp)

set_source_files_properties(rsrc/qml/Main.qml PROPERTIES
QT_RESOURCE_ALIAS Main.qml
)

qt_add_qml_module(fileo
    URI FileoModule
    VERSION 1.0
    QML_FILES
        rsrc/qml/Main.qml
    IMPORTS
        QtQuick

)

target_link_libraries(fileo 
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::QuickControls2
)