#libraries/CMakeLists.txt

add_subdirectory(3rdParty)
add_subdirectory(mylibraries)

add_library(LIBRARIES_LINK_LIB INTERFACE)

############################Common#####################################################
  #glm,mathLib
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE glm_interface)#3rdParty
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE context_interface)#myLibraries
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE mathlib_interface)#myLibraries

  ###################Platform Specific ##################################################

if(WINX64)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE glfw_interface)
endif()


if(OPENGL OR  VULKAN)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE glew_interface)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${GLEW_STATIC_LIB})
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE opengl_interface)
endif()

if(VULKAN)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE vulkan_interface)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE vulkansdk_interface)
endif()

if(WEBGL)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE emscripten_interface)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE webgl_interface)
endif()

if(WEBGPU)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE webgpu_interface)
endif()

if(DEBUG)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE debug_interface)
endif()