#libraries/platform/CMakeLists.txt



set(SOURCE_FILES "")
if(EMSCRIPTEN)
  file(GLOB_RECURSE PLATFORM_SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/browser/*.h ${CMAKE_CURRENT_SOURCE_DIR}/browser/*.cpp)
    set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.h 
                      ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.cpp
                        ${PLATFORM_SOURCE_FILES}  )
else()
  file(GLOB_RECURSE PLATFORM_SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.h ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp)
  set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.h 
                      ${CMAKE_CURRENT_SOURCE_DIR}/IRenderSurface.cpp
                        ${PLATFORM_SOURCE_FILES}  )
                     
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

target_link_libraries(platform_module PUBLIC mathLib_interface debugg_module)

target_link_libraries(platform_module INTERFACE renderCore_module)






