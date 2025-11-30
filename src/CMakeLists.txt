qt_add_executable(qt-tsdb-explorer
        mainwindow.ui
        mainwindow.cpp
        main.cpp
)

target_link_libraries(qt-tsdb-explorer PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)
target_include_directories(qt-tsdb-explorer PRIVATE "${CMAKE_BINARY_DIR}/generated")