#libraries/openglEngine/CMakeLists.txt

if(EMSCRIPTEN)
    add_subdirectory(openGL3x)     
else()
    add_subdirectory(openGL4x)
endif()