file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(userInterface_module ${SOURCE_FILES})


target_include_directories(userInterface_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

target_include_directories(userInterface_module PUBLIC  ${VCPKG_INSTALL_INCLUDE_DIR})

target_link_libraries(userInterface_module PRIVATE ${VCPKG_INSTALL_DIR}/lib/imgui.lib)