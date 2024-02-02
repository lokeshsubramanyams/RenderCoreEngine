#libraries/openglEngine/openGL4x/CMakeLists.txt

#file(GLOB PARENT_SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/../*.h ${CMAKE_CURRENT_SOURCE_DIR}/../*.cpp)

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

set(ALL_SOURCE_FILES ${SOURCE_FILES} ${OpenGL_Common_source})

message(STATUS "ALL_SOURCE_FILES-->:${ALL_SOURCE_FILES}")

add_library(openGLEngine_module ${ALL_SOURCE_FILES})


add_subdirectory( ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
message(STATUS "libraries/openglEngine/openGL4x-->:${CMAKE_CURRENT_BINARY_DIR}")


target_include_directories(openGLEngine_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" "${CMAKE_CURRENT_LIST_DIR}/" )
target_link_libraries(openGLEngine_module PUBLIC graphicEngine_module  )

target_include_directories(openGLEngine_module PUBLIC  ${VCPKG_INSTALL_INCLUDE_DIR})
target_include_directories(openGLEngine_module PUBLIC  ${CMAKE_CURRENT_BINARY_DIR}/shaders)

 target_link_libraries(openGLEngine_module PRIVATE ${VCPKG_INSTALL_DIR}/lib/OpenGL32.lib)
 target_link_libraries(openGLEngine_module PRIVATE ${VCPKG_INSTALL_DIR}/lib/glew32.lib)

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS ${ALL_SOURCE_FILES})
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()

