cmake_minimum_required(VERSION 3.17)
project(BrillaBoy)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(BrillaBoy main.cpp CPU.cpp Table.cpp Opcodes.cpp CPU.h GUI.cpp GUI.h)

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY})
target_compile_options(${PROJECT_NAME} PRIVATE "-fobjc-arc")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-framework Foundation -framework QuartzCore -framework Metal")