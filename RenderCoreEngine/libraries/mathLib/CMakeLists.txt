#libraries/mathLib/CMakeLists.txt


#file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
#add_library(mathLib_module ${SOURCE_FILES})
#set_target_properties(mathLib_module PROPERTIES LINKER_LANGUAGE CXX)
#target_include_directories(mathLib_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

add_library(mathLib_interface INTERFACE)
target_include_directories(mathLib_interface INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/")
target_include_directories(mathLib_interface INTERFACE  "${VCPKG_INSTALL_INCLUDE_DIR}/glm")