
# libraries/myLibraries/CMakeLists.txt
#impl of glfw
set(CONTEXT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Context")
add_library(context_interface INTERFACE)
target_include_directories(context_interface INTERFACE ${CONTEXT_INCLUDE_DIR})

#impl of glm
set(MATHLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mathLib")
add_library(mathlib_interface INTERFACE)
target_include_directories(mathlib_interface INTERFACE ${MATHLIB_INCLUDE_DIR})


set(OPENGL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/openGL")
add_library(opengl_interface INTERFACE)
target_include_directories(opengl_interface INTERFACE ${OPENGL_INCLUDE_DIR})


set(VULKAN_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vulkan")
add_library(vulkan_interface INTERFACE)
target_include_directories(vulkan_interface INTERFACE ${VULKAN_INCLUDE_DIR})


set(WEBGL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/webGL")
add_library(webgl_interface INTERFACE)
target_include_directories(webgl_interface INTERFACE ${WEBGL_INCLUDE_DIR})


set(WEBGPU_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/webGpu")
add_library(webgpu_interface INTERFACE)
target_include_directories(webgpu_interface INTERFACE ${WEBGPU_INCLUDE_DIR})


