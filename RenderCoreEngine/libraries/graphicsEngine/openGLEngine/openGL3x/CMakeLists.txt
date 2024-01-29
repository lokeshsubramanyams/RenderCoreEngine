#libraries/openglEngine/openGL3x/CMakeLists.txt
file(GLOB PARENT_SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/../*.h ${CMAKE_CURRENT_SOURCE_DIR}/../*.cpp)

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(ALL_SOURCE_FILES ${SOURCE_FILES} ${PARENT_SOURCE_FILES})

message(STATUS "ALL_SOURCE_FILES-->:${ALL_SOURCE_FILES}")

add_library(openGLEngine_module ${ALL_SOURCE_FILES})

add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
message(STATUS "libraries/openglEngine/openGL3x-->:${CMAKE_CURRENT_BINARY_DIR}")

target_include_directories(openGLEngine_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )
target_link_libraries(openGLEngine_module PUBLIC  graphicEngine_module debugg_module )


target_include_directories(openGLEngine_module PUBLIC  ${EMSCRIPTEN_INCLUDE_DIR})
target_include_directories(openGLEngine_module PUBLIC  ${CMAKE_CURRENT_BINARY_DIR}/shaders)

add_definitions(-DEMSCRIPTEN)

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS ${ALL_SOURCE_FILES})
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()
