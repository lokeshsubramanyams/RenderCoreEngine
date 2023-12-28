
#RenderCoreEngine/CMakeLists.txt

#Total 5 build_types:
#Windows-x64-openGL
#Windows-x64-vulkan
#Windows-x64-webgpu
#Emscripten-OpenGL
#Emscripten-webgpu


cmake_minimum_required (VERSION 3.10)

project (RenderCoreEngine)

option(DEBUG "Enable or Disable debug"        ON)

option(WINX64 "Opengl windows 64 build"       OFF)
option(WEBASSEMBLY "Opengl wasassembly build" OFF)

option(OPENGL  "OpenGL4.x Graphics Pipeline"    OFF)#Tring to use OpenGL4.x try to close to 4.3
option(WEBGL   "WebGL2.0 Graphics Pipeline" OFF)#WEBGL2.0-->OpenGLES3.0-->OpenGL 4.3
option(VULKAN  "Vulkan Graphics Pipeline"    OFF)#this is only to Windows
option(WEBGPU  "WebGPU Graphics Pipeline"    OFF)#this is for platforms webassembly and windows

 
if(PRESET_NAME STREQUAL "windows-x64-openGL")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(OPENGL ON CACHE BOOL "opengl" FORCE)

     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(WEBGL OFF CACHE BOOL "webgl" FORCE) 
     
elseif(PRESET_NAME STREQUAL "windows-x64-vulkan")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(VULKAN ON CACHE BOOL "vulkan" FORCE)

     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(WEBGL OFF CACHE BOOL "webgl" FORCE)
     
elseif(PRESET_NAME STREQUAL "windows-x64-webgpu")

     set(WINX64 ON CACHE BOOL "windows" FORCE)
     set(WEBGPU ON CACHE BOOL "webgpu" FORCE)

     set(OPENGL OFF CACHE BOOL "opengl" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)
     set(WEBASSEMBLY OFF CACHE BOOL "webassembly" FORCE)
     set(WEBGL OFF CACHE BOOL "webgl" FORCE)
     
elseif(PRESET_NAME STREQUAL "emscripten-openGL")

     set(WEBASSEMBLY ON CACHE BOOL "webassembly" FORCE)
     set(OPENGL ON CACHE BOOL "opengl" FORCE)
     set(WEBGL ON CACHE BOOL "webgl" FORCE)
   
     set(WINX64 OFF CACHE BOOL "windows" FORCE)
     set(WEBGPU OFF CACHE BOOL "webgpu" FORCE)
     set(VULKAN OFF CACHE BOOL "vulkan" FORCE)

elseif(PRESET_NAME STREQUAL "emscripten-webgpu")

     set(WEBASSEMBLY ON CACHE BOOL "webassembly" FORCE)
     set(WEBGPU ON CACHE BOOL "webgpu" FORCE)
     set(WEBGL ON CACHE BOOL "webgl" FORCE)

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

remove_definitions(-DDEBUG)
remove_definitions(-DPLATFORM_WEBASSEMBLY)
remove_definitions(-DPLATFORM_WINDOWS)
remove_definitions(-DOPENGL)
remove_definitions(-DWEBGL)
remove_definitions(-DVULKAN)
remove_definitions(-DWEBGPU)

if(WINX64)
  add_definitions(-DPLATFORM_WINDOWS)
elseif(WEBASSEMBLY)
  add_definitions(-DPLATFORM_WEBASSEMBLY)
endif()

if(OPENGL)
  add_definitions(-DOPENGL)
endif()
if(WEBGL)
  add_definitions(-DWEBGL)
endif()
if(VULKAN)
  add_definitions(-DVULKAN)
endif()
if(WEBGPU)
  add_definitions(-DWEBGPU)
endif()

if(DEBUG)
  add_definitions(-DDEBUG)
endif()

add_subdirectory(libraries)
add_subdirectory(resources)
add_subdirectory(src)

if(WINX64)
  add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE} appicon.rc)
elseif(WEBASSEMBLY)
  add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE})
endif()

target_link_libraries(RenderCoreEngine PRIVATE LIBRARIES_LINK_LIB)

if (CMAKE_VERSION VERSION_GREATER 3.10)
  set_property(TARGET RenderCoreEngine PROPERTY CXX_STANDARD 20)
endif()


