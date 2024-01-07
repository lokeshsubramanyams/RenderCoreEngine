#libraries/context/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(platform_module ${SOURCE_FILES})
set_target_properties(platform_module PROPERTIES LINKER_LANGUAGE CXX)
target_include_directories(platform_module PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/"
"${CMAKE_CURRENT_SOURCE_DIR}/windows"
"${CMAKE_CURRENT_SOURCE_DIR}/browser")
target_link_libraries(platform_module PUBLIC mathLib_interface)

