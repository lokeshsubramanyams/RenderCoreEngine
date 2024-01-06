#libraries/debug/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(debug_module ${SOURCE_FILES})
set_target_properties(debug_module PROPERTIES LINKER_LANGUAGE CXX)
# Specify include directories
target_include_directories(debug_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
