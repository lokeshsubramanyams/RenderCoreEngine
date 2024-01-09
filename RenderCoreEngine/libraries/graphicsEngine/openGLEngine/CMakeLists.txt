#libraries/openglEngine/CMakeLists.txt

set(SOURCE_FILES "")
if(EMSCRIPTEN)
  file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/opengl3x/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/opengl3x/*.cpp)
else()
  file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/opengl4x/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/opengl4x/*.cpp)
endif()

add_library(openGLEngine_module ${SOURCE_FILES})

target_include_directories(openGLEngine_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )

target_link_libraries(openGLEngine_module PUBLIC platform_module mathLib_interface renderCore_module )

if(EMSCRIPTEN)
    target_include_directories(openGLEngine_module PRIVATE  "${EMSCRIPTEN_CACHE_INCLUDE_DIR}/")
    #target_include_directories(platform_module INTERFACE  "${EMSCRIPTEN_INCLUDE_DIR}/")
else()
    target_include_directories(openGLEngine_module PUBLIC  "${VCPKG_INSTALL_INCLUDE_DIR}/")
endif()

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS SOURCE_FILES)
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()