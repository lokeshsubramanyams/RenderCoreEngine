
# libraries/3rdParty/CMakeLists.txt

#glfw
set(GLFW_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glfw-3.3.9/include")
add_library(glfw_interface INTERFACE)
target_include_directories(glfw_interface INTERFACE ${GLFW_INCLUDE_DIR})

#glm
set(GLM_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/glm-0.9.9")
add_library(glm_interface INTERFACE)
target_include_directories(glm_interface INTERFACE ${GLM_INCLUDE_DIR})
