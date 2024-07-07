
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_PREFIX_PATH "C:/Users/julia/Qt/6.7.0/mingw_64") # TODO: fix this hardcoded path

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick QuickControls2)
qt_standard_project_setup()
qt_add_executable(fileo main.cpp)

# Places QML modules in ":/qrc/qml/" 
qt_policy(SET QTP0001 NEW)

set_source_files_properties(rsrc/qml/Main.qml PROPERTIES
QT_RESOURCE_ALIAS Main.qml
)

qt_add_qml_module(fileo
    URI FileoModule
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