file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)


file(GLOB_RECURSE imgui_source  
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/imgui/*.h 
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/imgui/*.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/imgui/imgui_glfw/*.h 
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/imgui/imgui_glfw/*.cpp 
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/*.h 
  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/*.cpp )

message(STATUS "imgui-->${imgui_source}")

add_library(userInterface_module ${SOURCE_FILES} ${imgui_source})

target_include_directories(userInterface_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/")

target_include_directories(userInterface_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/imgui/"
                                                              "${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/")

target_link_libraries(userInterface_module PUBLIC graphicEngine_module)

