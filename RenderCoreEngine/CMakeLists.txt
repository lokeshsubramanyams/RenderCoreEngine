# CMakeList.txt : CMake project for RenderCoreEngine, include source and define
# project specific logic here.

#RenderCoreEngine/CMakeLists.txt

cmake_minimum_required (VERSION 3.10)

project (RenderCoreEngine)

add_subdirectory(libraries)
add_executable (RenderCoreEngine "src/RCEngine.cpp" "src/RCEngine.hpp")
#myLibraries
target_link_libraries(RenderCoreEngine PRIVATE glfw_context_interface  mathlib_interface)
#3rdParty
target_link_libraries(RenderCoreEngine PRIVATE glfw_interface glm_interface)



if (CMAKE_VERSION VERSION_GREATER 3.10)
  set_property(TARGET RenderCoreEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
