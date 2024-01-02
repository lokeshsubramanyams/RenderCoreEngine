#libraries/CMakeLists.txt

#3rd-Party
add_subdirectory(3rdParty)
#myLibraries
add_subdirectory(mylibraries)

add_library(LIBRARIES_LINK_LIB INTERFACE)

#all includes of vcpkg libraries
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE vcpkg_interface)

#common for all platforms
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${glm_library})#3rdParty
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${assimp_library})#3rdParty
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE context_interface)#myLibraries
target_link_libraries(LIBRARIES_LINK_LIB INTERFACE mathlib_interface)#myLibraries


if(WEBASSEMBLY)

    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${emscripten_library})#3rdParty
    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE webgl_interface)#myLibrary

  if(OPENGL)

    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${glew_library})#3rdParty
    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE opengl_interface)#myLibrary

  elseif(WEBGPU)

    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE webgpu_interface)#myLibrary

  endif()

elseif(WINX64)

    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${glfw3_library})

  if(OPENGL)

    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${glew_library})#3rdParty
    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE opengl_interface)#myLibrary

  elseif(VULKAN)

    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${vulkansdk_interface})#3rdParty
    target_link_libraries(LIBRARIES_LINK_LIB INTERFACE vulkan_interface)#myLibraries
    
    #this need to check after all the platforms done
  #elseif(WEBGPU)

   # target_link_libraries(LIBRARIES_LINK_LIB INTERFACE ${emscripten_library})#3rdParty
   # target_link_libraries(LIBRARIES_LINK_LIB INTERFACE webgpu_interface)#myLibrary

  endif()

endif()


if(DEBUG)
  target_link_libraries(LIBRARIES_LINK_LIB INTERFACE debug_interface)#myLibrary
endif()