#libraries/WebGpuEngine/CMakeLists.txt

set(SOURCE_FILES "")

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(webGpuEngine_module ${SOURCE_FILES})

target_include_directories(webGpuEngine_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )

target_link_libraries(webGpuEngine_module PUBLIC platform_module mathLib_interface renderCore_module )

if(EMSCRIPTEN)
target_include_directories(webGpuEngine_module INTERFACE  "${EMSCRIPTEN_INCLUDE_DIR}/")
endif()

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS SOURCE_FILES)
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()