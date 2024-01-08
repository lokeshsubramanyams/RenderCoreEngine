#libraries/vulkanEngine/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(vulkanEngine_module ${SOURCE_FILES})
target_include_directories(vulkanEngine_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )

target_link_libraries(vulkanEngine_module PUBLIC platform_module mathLib_interface renderCore_module )

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS SOURCE_FILES)
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()