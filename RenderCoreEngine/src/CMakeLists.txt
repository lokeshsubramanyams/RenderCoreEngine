#RenderCoreEngine/src/CMakeLists.txt

file(GLOB_RECURSE CppSource "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE HppSource "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

set(SRC_SOURCE_EXECUTABLE ${CppSource} ${HppSource} PARENT_SCOPE)