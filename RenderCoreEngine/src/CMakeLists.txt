#RenderCoreEngine/src/CMakeLists.txt

set(cppSource "")
if(WINX64)
set(CppSource "${CMAKE_CURRENT_SOURCE_DIR}/AppMainWin64.cpp")
else()
set(CppSource "${CMAKE_CURRENT_SOURCE_DIR}/AppMainBrowser.cpp")
endif()
#file(GLOB_RECURSE HppSource "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

#set(SRC_SOURCE_EXECUTABLE ${CppSource} ${HppSource} PARENT_SCOPE)
set(SRC_SOURCE_EXECUTABLE ${CppSource} PARENT_SCOPE)

add_library(main_module INTERFACE)

target_include_directories(main_module INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")

