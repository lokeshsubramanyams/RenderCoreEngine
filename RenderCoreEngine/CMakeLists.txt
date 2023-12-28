# CMakeList.txt : CMake project for RenderCoreEngine, include source and define
# project specific logic here.

#RenderCoreEngine/CMakeLists.txt

#Total 5 build_types:
#Windows-x64-openGL
#Windows-x64-vulkan
#Windows-x64-webgpu

#Emscripten-OpenGL
#Emscripten-webgpu


cmake_minimum_required (VERSION 3.10)

project (RenderCoreEngine)

option(DEBUG "Enable or Disable debug"        OFF)

option(WINX64 "Opengl windows 64 build"       OFF)
option(WEBASSEMBLY "Opengl wasassembly build" OFF)

option(OPENGL  "OpenGL Graphics Pipeline"    OFF)#Tring to use OpenGL4.x try to close to 4.3
option(WEBGL   "WebGL-2.0 Graphics Pipeline" OFF)#WEBGL2.0->OpenGLES3.0->OpenGL 4.3
option(VULKAN  "Vulkan Graphics Pipeline"    OFF)#this is only to Windows
option(WEBGPU  "WebGPU Graphics Pipeline"    OFF)#this is for platforms webassembly and windows

 
if(PRESET_NAME STREQUAL "windows-x64-release-openGL")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(OPENGL ON CACHE BOOL "opengl" FORCE)
     add_definitions(-DPLATFORM_WINDOWS)

     remove_definitions(-DPLATFORM_WEBASSEMBLY)
     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(WEBGL OFF CACHE BOOL "webgl" FORCE)
     
elseif(PRESET_NAME STREQUAL "windows-x64-release-vulkan")

     set(WINX64 ON CACHE BOOL "windows with vulkan" FORCE)
     set(VULKAN ON CACHE BOOL "windows with vulkan" FORCE)
     add_definitions(-DPLATFORM_WINDOWS)

     remove_definitions(-DPLATFORM_WEBASSEMBLY)
     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(WEBGL OFF CACHE BOOL "webgl" FORCE)
     
elseif(PRESET_NAME STREQUAL "windows-x64-release-webgpu")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(WEBGPU ON CACHE BOOL "webgpu" FORCE)
     add_definitions(-DPLATFORM_WINDOWS)

     remove_definitions(-DPLATFORM_WEBASSEMBLY)
     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)
     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(WEBGL OFF CACHE BOOL "webgl" FORCE)
     
elseif(PRESET_NAME STREQUAL "emscripten-release-openGL")

     set(WEBASSEMBLY ON CACHE BOOL "webassembly" FORCE)
     set(OPENGL ON CACHE BOOL "opengl" FORCE)
     set(WEBGL ON CACHE BOOL "webgl" FORCE)
     add_definitions(-DPLATFORM_WEBASSEMBLY)

     remove_definitions(-DPLATFORM_WINDOWS)
     set(WINX64 OFF CACHE BOOL "windows" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)

elseif(PRESET_NAME STREQUAL "emscripten-release-webgpu")

     set(WEBASSEMBLY ON CACHE BOOL "webassembly" FORCE)
     set(WEBGPU ON CACHE BOOL "webgpu" FORCE)
     set(WEBGL ON CACHE BOOL "webgl" FORCE)
     add_definitions(-DPLATFORM_WEBASSEMBLY)

     remove_definitions(-DPLATFORM_WINDOWS)
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
WEBGL=${WEBGL}, 
WEBGPU=${WEBGPU},
DEBUG=${DEBUG}")

add_subdirectory(libraries)
add_subdirectory(resources)
add_subdirectory(src)

add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE} appicon.rc)

target_link_libraries(RenderCoreEngine PRIVATE LIBRARIES_LINK_LIB)

if (CMAKE_VERSION VERSION_GREATER 3.10)
  set_property(TARGET RenderCoreEngine PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
