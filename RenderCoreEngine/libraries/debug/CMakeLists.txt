#libraries/debug/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(debugg_module ${SOURCE_FILES})
set_target_properties(debugg_module PROPERTIES LINKER_LANGUAGE CXX)
# Specify include directories
target_include_directories(debugg_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(debugg_module PUBLIC mathLib_interface)