 #emscriptien "C:/emsdk/upstream/emscripten/system/include"
 set(EMSCRIPTEN_INCLUDE_DIR "C:/emsdk/upstream/emscripten/cache/sysroot/include")

 add_library(emscripten_interface INTERFACE)
 target_include_directories(emscripten_interface INTERFACE ${EMSCRIPTEN_INCLUDE_DIR})