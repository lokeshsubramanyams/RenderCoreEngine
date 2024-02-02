#libraries/openglEngine/CMakeLists.txt

file(GLOB OpenGL_Common_source  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
${CMAKE_CURRENT_SOURCE_DIR}/source/*.h ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp  )


if(EMSCRIPTEN)
    add_subdirectory(openGL3x)     
else()
    add_subdirectory(openGL4x)
endif()