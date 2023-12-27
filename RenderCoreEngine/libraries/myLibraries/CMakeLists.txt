
# libraries/myLibraries/CMakeLists.txt
#impl of glfw
set(GLFW_CONTEXT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfwContext")
add_library(glfw_context_interface INTERFACE)
target_include_directories(glfw_context_interface INTERFACE ${GLFW_CONTEXT_INCLUDE_DIR})

#impl of glm
set(MATHLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mathLib")
add_library(mathlib_interface INTERFACE)
target_include_directories(mathlib_interface INTERFACE ${MATHLIB_INCLUDE_DIR})



