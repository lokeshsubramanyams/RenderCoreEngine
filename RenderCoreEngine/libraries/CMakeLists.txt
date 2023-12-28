

# libraries/CMakeLists.txt

add_subdirectory(3rdParty)
add_subdirectory(mylibraries)

add_library(LIBRARIES_LINK_LIB INTERFACE)

#3rdParty
if(OPENGL)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE glew_interface)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${GLEW_STATIC_LIB})
endif()

if(WINX64)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE glfw_interface)
endif()

if(WEBASSEMBLY)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE emscripten_interface)
endif()

target_link_libraries(LIBRARIES_LINK_LIB INTERFACE glm_interface)

#myLibraries
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE context_interface)
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE mathlib_interface)