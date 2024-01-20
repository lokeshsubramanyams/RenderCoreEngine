#RenderCoreEngine/src/CMakeLists.txt

file(GLOB_RECURSE CppSource "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HppSource "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

set(SRC_SOURCE_EXECUTABLE ${CppSource} ${HppSource} PARENT_SCOPE)

add_library(main_module INTERFACE)

target_include_directories(main_module INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

