set(VULKAN_INCLUDE_DIR "C:/VulkanSDK/1.3.268.0/Include/vulkan")
set(VULKAN_STATIC_LIB "C:/VulkanSDK/1.3.268.0/Lib")

add_library(vulkansdk_interface INTERFACE)
target_include_directories(vulkansdk_interface INTERFACE ${VULKAN_INCLUDE_DIR})
target_include_directories(vulkansdk_interface INTERFACE ${VULKAN_STATIC_LIB})