#libraries/platform/CMakeLists.txt


set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/IContext.hpp ${CMAKE_CURRENT_SOURCE_DIR}/IContext.cpp)
if(EMSCRIPTEN)
  file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/browser/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/browser/*.cpp)
else()
  file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/windows/*.cpp)
endif()

add_library(platform_module ${SOURCE_FILES})

target_include_directories(platform_module PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/"
"${CMAKE_CURRENT_SOURCE_DIR}/windows"
"${CMAKE_CURRENT_SOURCE_DIR}/browser"
 )

target_link_libraries(platform_module PUBLIC mathLib_interface)

if(EMSCRIPTEN)
    target_include_directories(platform_module PUBLIC  "${EMSCRIPTEN_INCLUDE_DIR}")
endif()