 
#set(SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/IGraphicsEngine.h ${CMAKE_CURRENT_SOURCE_DIR}/IGraphicsEngine.cpp)

add_library(graphicEngine_module INTERFACE)#${SOURCE_FILES})

target_include_directories(graphicEngine_module INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/interface/" )
target_link_libraries(graphicEngine_module INTERFACE  platform_module mathLib_interface renderCore_module )

if(OPENGL)
  add_subdirectory(openGLEngine)
  target_include_directories(graphicEngine_module INTERFACE ${openGLEngine_module} )
  target_link_libraries(graphicEngine_module INTERFACE openGLEngine_module)
  target_link_libraries(graphicEngine_module PRIVATE ${openGLEngine_module})
  
endif()

if(VULKAN)
  add_subdirectory(vulkanEngine)
  set(VULKAN_INCLUDE_DIR "C:/VulkanSDK/1.3.268.0/Include/vulkan")
  set(VULKAN_STATIC_LIB "C:/VulkanSDK/1.3.268.0/Lib")
  target_include_directories(graphicEngine_module INTERFACE ${VULKAN_INCLUDE_DIR})
  target_link_libraries(graphicEngine_module INTERFACE ${VULKAN_STATIC_LIB})
  target_link_libraries(graphicEngine_module INTERFACE vulkanEngine_module)
  target_link_libraries(graphicEngine_module PRIVATE ${vulkanEngine_module})
endif()

if(WEBGPU)
add_subdirectory(webGpuEngine)

endif()