#libraries/context/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(context_module ${SOURCE_FILES})
set_target_properties(context_module PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(context_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_link_libraries(context_module PUBLIC mathLib_interface)

