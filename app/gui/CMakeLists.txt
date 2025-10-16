# Use Qt5
find_package(Qt5 COMPONENTS Widgets REQUIRED)
set(QT_PACKAGE Qt5)
set(QT_WIDGETS_TARGET Qt5::Widgets)


add_executable(dragon2_gui WIN32
    main.cpp
    MainWindow.h
    MainWindow.cpp
    MainWindow.ui
)

target_link_libraries(dragon2_gui PRIVATE
    dragon2_core
    ${QT_WIDGETS_TARGET}
)

# Icono/props de Windows (opcional):
set_target_properties(dragon2_gui PROPERTIES WIN32_EXECUTABLE TRUE)
