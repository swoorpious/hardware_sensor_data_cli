cmake_minimum_required(VERSION 4.0)
project(hardware_sensor_data_cli)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/ftxui)


add_executable(hardware_sensor_data_cli src/main.cpp)


target_link_libraries(hardware_sensor_data_cli
        PRIVATE ftxui::screen
        PRIVATE ftxui::dom
        PRIVATE ftxui::component
)
target_include_directories(hardware_sensor_data_cli PRIVATE external/ftxui/include)

target_compile_definitions(hardware_sensor_data_cli
        PRIVATE
        $<$<CONFIG:Debug>:BUILD_DEBUG>
        $<$<CONFIG:Release>:BUILD_RELEASE>
)
