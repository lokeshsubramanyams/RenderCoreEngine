#libraries/RenderCore/CMakeLists.txt

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_library(renderCore_module ${SOURCE_FILES})
target_include_directories(renderCore_module PUBLIC 
"${CMAKE_CURRENT_SOURCE_DIR}/"
"${CMAKE_CURRENT_SOURCE_DIR}/graphics/"
"${CMAKE_CURRENT_SOURCE_DIR}/graphics/mesh/"
"${CMAKE_CURRENT_SOURCE_DIR}/graphics/camera/"
"${CMAKE_CURRENT_SOURCE_DIR}/graphics/light/")

target_link_libraries(renderCore_module PUBLIC mathLib_interface)

# Debugging: Print out all found source files
foreach(SOURCE_FILE IN LISTS SOURCE_FILES)
    message(STATUS "Found source file: ${SOURCE_FILE}")
endforeach()