#libraries/platform/CMakeLists.txt



set(SOURCE_FILES "")
if(EMSCRIPTEN)
  #file(GLOB_RECURSE PLATFORM_SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/browser/*.h ${CMAKE_CURRENT_SOURCE_DIR}/browser/*.cpp)
    set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.h 
                      ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.cpp
                      ${CMAKE_CURRENT_SOURCE_DIR}/GlfwWindow.h 
                        #${CMAKE_CURRENT_SOURCE_DIR}/browser/RenderSurfaceBrowser.h 
                        #${CMAKE_CURRENT_SOURCE_DIR}/browser/RenderSurfaceBrowser.cpp
                         ${CMAKE_CURRENT_SOURCE_DIR}/browser/RenderSurfaceGlfwBrowser.h 
                        ${CMAKE_CURRENT_SOURCE_DIR}/browser/RenderSurfaceGlfwBrowser.cpp)
else()
  #file(GLOB_RECURSE PLATFORM_SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.h ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp)
  set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.h 
                      ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.cpp
                      ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurfaceGlfw.h 
                      ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurfaceGlfw.cpp
                      ${CMAKE_CURRENT_SOURCE_DIR}/GlfwWindow.h 
                         ${CMAKE_CURRENT_SOURCE_DIR}/windows/RenderSurfaceWin64.h 
                        ${CMAKE_CURRENT_SOURCE_DIR}/windows/RenderSurfaceWin64.cpp)
                     
endif()


add_library(platform_module ${SOURCE_FILES})

if(EMSCRIPTEN)

    target_include_directories(platform_module PUBLIC  "${EMSCRIPTEN_INCLUDE_DIR}")

    target_include_directories(platform_module PUBLIC 
                            "${CMAKE_CURRENT_SOURCE_DIR}/"
                                    "${CMAKE_CURRENT_SOURCE_DIR}/browser"
 )

else()
  
  target_link_libraries(platform_module PRIVATE ${VCPKG_INSTALL_DIR}/lib/glfw3.lib)
  target_include_directories(platform_module PUBLIC  ${VCPKG_INSTALL_INCLUDE_DIR})

  target_include_directories(platform_module PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/"
"${CMAKE_CURRENT_SOURCE_DIR}/windows"
 )
  
endif()

target_link_libraries(platform_module PUBLIC mathLib_interface  debugg_module userInterface_module)

target_link_libraries(platform_module INTERFACE renderCore_module )








