#libraries/openglEngine/openGL3x/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
message(STATUS "libraries/openglEngine/openGL3x-->:${CMAKE_CURRENT_BINARY_DIR}")


add_library(openGLEngine_module ${SOURCE_FILES})
target_include_directories(openGLEngine_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )
target_link_libraries(openGLEngine_module PUBLIC  graphicEngine_module )


target_include_directories(openGLEngine_module PUBLIC  ${EMSCRIPTEN_INCLUDE_DIR})
target_include_directories(openGLEngine_module PUBLIC  ${CMAKE_CURRENT_BINARY_DIR}/shaders)

add_definitions(-DEMSCRIPTEN)

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS SOURCE_FILES)
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()
