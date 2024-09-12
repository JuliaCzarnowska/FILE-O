cmake_minimum_required(VERSION 3.28)

if (NOT DEFINED CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
endif()

# Set the project props
project(fileo LANGUAGES CXX C)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_PREFIX_PATH "/opt/qt/6.8.0/gcc_64/lib/cmake/") # TODO: fix this hardcoded path
set(APP_NAME ${CMAKE_PROJECT_NAME})
set(APP_VERSION ${CMAKE_PROJECT_VERSION})

include(cmake/Components.cmake)

# Boost
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost COMPONENTS ${BOOST_COMPONENTS} REQUIRED)

# QT6
find_package(Qt6 REQUIRED COMPONENTS ${QT_COMPONENTS})
set(${APP_NAME}_QT_QUICK ON)

qt_standard_project_setup(REQUIRES 6.8)
qt_add_executable(fileo main.cpp)

# Places QML modules in ":/qrc/qml/", to omit warning
qt_policy(SET QTP0001 NEW)

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
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickControls2
        Boost::filesystem
)