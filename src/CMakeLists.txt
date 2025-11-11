qt_add_executable(qt-tsdb-explorer main.cpp)

target_link_libraries(qt-tsdb-explorer PRIVATE Qt6::Core Qt6::Widgets Qt6::Sql)