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

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project (RenderCoreEngine)

set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake"  CACHE STRING "Vcpkg toolchain file") 

set(CMAKE_TOOLCHAIN_FILE "C:/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake" CACHE STRING "emsdk toolchain file")

set(VCPKG_INSTALL_DIR "C:/vcpkg/installed/x64-windows-static")

set(VCPKG_INSTALL_INCLUDE_DIR "${VCPKG_INSTALL_DIR}/include")

set(EMSCRIPTEN_CACHE_INCLUDE_DIR "C:/emsdk/upstream/emscripten/cache/sysroot/include")

set(EMSCRIPTEN_CACHE_INCLUDE_EMSCRIPTEN_DIR "C:/emsdk/upstream/emscripten/cache/sysroot/include/emscripten")

set(EMSCRIPTEN_INCLUDE_DIR "C:/emsdk/upstream/emscripten/system/include")

option(OnDEVELOPMENT "Emscripten include change to cache dir while building"  OFF)

if(OnDEVELOPMENT)
  set(EMSCRIPTEN_INCLUDE_DIR "C:/emsdk/upstream/emscripten/system/include")
else()
  set(EMSCRIPTEN_INCLUDE_DIR "C:/emsdk/upstream/emscripten/cache/sysroot/include")
endif()


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
EMSCRIPTEN=${EMSCRIPTEN}, 
WEBGPU=${WEBGPU},
DEBUG=${DEBUG}")

remove_definitions(-DDEBUG)
remove_definitions(-DPLATFORM_WEBASSEMBLY)
remove_definitions(-DPLATFORM_WINDOWS)
remove_definitions(-DOPENGL)
remove_definitions(-DEMSCRIPTEN)
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
if(VULKAN)
add_definitions(-DVULKAN)
endif()
if(WEBGL)
add_definitions(-DWEBGPU)
endif()


if(DEBUG)
  add_definitions(-DDEBUG)
  message(STATUS "DEBUG is set")
else()
  message(STATUS "DEBUG is not set")
endif()


add_library(module_interface INTERFACE)

add_subdirectory(libraries/debug)
add_subdirectory(libraries/mathLib)
add_subdirectory(libraries/platform)
add_subdirectory(libraries/renderCoreEngine)
add_subdirectory(libraries/graphicsEngine)

add_subdirectory(resources)
add_subdirectory(src)

target_link_libraries(module_interface INTERFACE main_module)
target_link_libraries(module_interface INTERFACE mathLib_interface)#header only module so no need to add Private or public to the build
target_link_libraries(module_interface INTERFACE platform_module)
target_link_libraries(module_interface PRIVATE ${platform_module})
target_link_libraries(module_interface INTERFACE renderCore_module)
target_link_libraries(module_interface PRIVATE ${renderCore_module})
target_link_libraries(module_interface INTERFACE graphicEngine_module)
target_link_libraries(module_interface PRIVATE ${graphicEngine_module})
target_link_libraries(module_interface INTERFACE debugg_module)
target_link_libraries(module_interface PRIVATE ${debugg_module})




if(WINX64)
  add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE} appicon.rc)
elseif(WEBASSEMBLY)
  add_executable (RenderCoreEngine ${SRC_SOURCE_EXECUTABLE})
  add_custom_command(TARGET RenderCoreEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy 
            "${CMAKE_CURRENT_BINARY_DIR}/RenderCoreEngine.wasm"
            "${CMAKE_CURRENT_SOURCE_DIR}/JsProject/RenderCoreEngine.wasm"
    COMMAND ${CMAKE_COMMAND} -E copy 
            "${CMAKE_CURRENT_BINARY_DIR}/RenderCoreEngine.js"
            "${CMAKE_CURRENT_SOURCE_DIR}/JsProject/RenderCoreEngine.js"
    COMMENT "Copying .wasm and .js files to destination directory"
)

endif()

target_link_libraries(RenderCoreEngine PRIVATE module_interface)


if (CMAKE_VERSION VERSION_GREATER 3.10)
  set_property(TARGET RenderCoreEngine PROPERTY CXX_STANDARD 20)
endif()


