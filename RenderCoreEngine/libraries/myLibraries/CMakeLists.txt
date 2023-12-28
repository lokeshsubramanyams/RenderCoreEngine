
# libraries/myLibraries/CMakeLists.txt
#impl of glfw
set(CONTEXT_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Context")
add_library(context_interface INTERFACE)
target_include_directories(context_interface INTERFACE ${CONTEXT_INCLUDE_DIR})

#impl of glm
set(MATHLIB_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/mathLib")
add_library(mathlib_interface INTERFACE)
target_include_directories(mathlib_interface INTERFACE ${MATHLIB_INCLUDE_DIR})



