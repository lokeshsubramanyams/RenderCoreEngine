#do below command in project terminal
#cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake


#RenderCoreEngine/CMakeLists.txt

#Total 5 build_types:
#Windows-x64-openGL
#Windows-x64-vulkan
#Windows-x64-webgpu
#Emscripten-OpenGL
#Emscripten-webgpu


cmake_minimum_required (VERSION 3.10)

project (RenderCoreEngine)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"  CACHE STRING "Vcpkg toolchain file") 

set(VCPKG_INSTALL_DIR "C:/vcpkg/installed/x64-windows-static")
set(VCPKG_INSTALL_INCLUDE_DIR "${VCPKG_INSTALL_DIR}/include")
set(EMSCRIPTEN_CACHE_INCLUDE_DIR "C:/emsdk/upstream/emscripten/cache/sysroot/include")
set(EMSCRIPTEN_INCLUDE_DIR "C:/emsdk/upstream/emscripten/system/include")

option(DEBUG "Enable or Disable debug"        ON)

option(WINX64 "Opengl windows 64 build"       OFF)
option(WEBASSEMBLY "Opengl wasassembly build" OFF)

option(OPENGL  "OpenGL4.x Graphics Pipeline"    OFF)#Tring to use OpenGL4.x try to close to 4.3
option(EMSCRIPTEN   "WebGL2.0 Graphics Pipeline" OFF)#WEBGL2.0-->OpenGLES3.0-->OpenGL 4.3
option(VULKAN  "Vulkan Graphics Pipeline"    OFF)#this is only to Windows
option(WEBGPU  "WebGPU Graphics Pipeline"    OFF)#this is for platforms webassembly and windows

 
if(PRESET_NAME STREQUAL "windows-x64-openGL")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(OPENGL ON CACHE BOOL "opengl" FORCE)

     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(EMSCRIPTEN OFF CACHE BOOL "webgl" FORCE) 
     
elseif(PRESET_NAME STREQUAL "windows-x64-vulkan")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(VULKAN ON CACHE BOOL "vulkan" FORCE)

     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(EMSCRIPTEN OFF CACHE BOOL "webgl" FORCE)
     
elseif(PRESET_NAME STREQUAL "windows-x64-webgpu")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(WEBGPU ON CACHE BOOL "webgpu" FORCE)

     set(EMSCRIPTEN OFF CACHE BOOL "webgl" FORCE)
     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)
     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
    
elseif(PRESET_NAME STREQUAL "emscripten-openGL")

     set(WEBASSEMBLY ON CACHE BOOL "webassembly" FORCE)
     set(OPENGL ON CACHE BOOL "opengl" FORCE)
     set(EMSCRIPTEN ON CACHE BOOL "webgl" FORCE)#required to include emscripten
   
     set(WINX64 OFF CACHE BOOL "windows" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)

elseif(PRESET_NAME STREQUAL "emscripten-webgpu")

     set(WEBASSEMBLY ON CACHE BOOL "webassembly" FORCE)
     set(WEBGPU ON CACHE BOOL "webgpu" FORCE)
     set(EMSCRIPTEN ON CACHE BOOL "webgl" FORCE)#required to include emscripten

     set(WINX64 OFF CACHE BOOL "windows" FORCE)
     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)

endif()

message(STATUS 
"Build Config:
WINX64=${WINX64},
WEBASSEMBLY=${WEBASSEMBLY},
OPENGL=${OPENGL},
VULKAN=${VULKAN}, 
WEBGL=${EMSCRIPTEN}, 
WEBGPU=${WEBGPU},
DEBUG=${DEBUG}")

remove_definitions(-DDEBUG)
remove_definitions(-DPLATFORM_WEBASSEMBLY)
remove_definitions(-DPLATFORM_WINDOWS)
remove_definitions(-DOPENGL)
remove_definitions(-DEMSCRIPTEN)
remove_definitions(-DVULKAN)
remove_definitions(-DWEBGPU)


add_library(module_interface INTERFACE)

add_subdirectory(libraries/debug)
add_subdirectory(libraries/mathLib)
add_subdirectory(libraries/platform)
add_subdirectory(libraries/renderCore)

add_subdirectory(resources)
add_subdirectory(src)

target_link_libraries(module_interface INTERFACE main_module)
target_link_libraries(module_interface INTERFACE mathLib_interface)#header only module so no need to add Private or public to the build

target_link_libraries(module_interface INTERFACE platform_module)
target_link_libraries(module_interface PRIVATE ${platform_module})
target_link_libraries(module_interface INTERFACE renderCore_module)
target_link_libraries(module_interface PRIVATE ${renderCore_module})
target_link_libraries(module_interface INTERFACE debugg_module)
target_link_libraries(module_interface PRIVATE ${debugg_module})

if(WINX64)
  add_definitions(-DPLATFORM_WINDOWS)
elseif(WEBASSEMBLY)
  add_definitions(-DPLATFORM_WEBASSEMBLY)

endif()

if(OPENGL)
  add_definitions(-DOPENGL)
  add_subdirectory(libraries/graphicsEngine/openGLEngine)
  target_link_libraries(module_interface INTERFACE openGLEngine_module)
  target_link_libraries(module_interface PRIVATE ${openGLEngine_module})
endif()
if(EMSCRIPTEN)
  add_definitions(-DEMSCRIPTEN)
  
endif()
if(VULKAN)
  add_definitions(-DVULKAN)
  set(VULKAN_INCLUDE_DIR "C:/VulkanSDK/1.3.268.0/Include/vulkan")
  set(VULKAN_STATIC_LIB "C:/VulkanSDK/1.3.268.0/Lib")
  target_include_directories(module_interface INTERFACE ${VULKAN_INCLUDE_DIR})
  target_link_libraries(module_interface INTERFACE ${VULKAN_STATIC_LIB})
  add_subdirectory(libraries/graphicsEngine/vulkanEngine)
  target_link_libraries(module_interface INTERFACE vulkanEngine_module)
  target_link_libraries(module_interface PRIVATE ${vulkanEngine_module})
endif()
if(WEBGPU)
  add_definitions(-DWEBGPU)
  add_subdirectory(libraries/graphicsEngine/webGpuEngine)
endif()

if(DEBUG)
  add_definitions(-DDEBUG)
endif()


if(WINX64)
  add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE} appicon.rc)
elseif(WEBASSEMBLY)
  add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE})
endif()

target_link_libraries(RenderCoreEngine PRIVATE module_interface)


if (CMAKE_VERSION VERSION_GREATER 3.10)
  set_property(TARGET RenderCoreEngine PROPERTY CXX_STANDARD 20)
endif()


