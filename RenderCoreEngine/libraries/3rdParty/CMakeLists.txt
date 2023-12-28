
# libraries/3rdParty/CMakeLists.txt

#glew-opengl
set(GLEW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glew-2.2.0/include")
add_library(glew_interface INTERFACE)
target_include_directories(glew_interface INTERFACE ${GLEW_INCLUDE_DIR})


  set(GLEW_STATIC_LIB "${CMAKE_CURRENT_SOURCE_DIR}/glew-2.2.0/lib/x64/glew32.lib")
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/glew-2.2.0/bin/Release/x64/glew32.dll" ${CMAKE_BINARY_DIR} COPYONLY)


#glfw

set(GLFW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3.9/include")
add_library(glfw_interface INTERFACE)
target_include_directories(glfw_interface INTERFACE ${GLFW_INCLUDE_DIR})

#emscriptien

set(EMSCRIPTEN_INCLUDE_DIR "C:/emsdk/upstream/emscripten/cache/sysroot/include")
add_library(emscripten_interface INTERFACE)
target_include_directories(emscripten_interface INTERFACE ${EMSCRIPTEN_INCLUDE_DIR})


#glm
set(GLM_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glm-0.9.9")
add_library(glm_interface INTERFACE)
target_include_directories(glm_interface INTERFACE ${GLM_INCLUDE_DIR})


