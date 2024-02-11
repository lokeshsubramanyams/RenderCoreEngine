
#add_subdirectory(3rd-party/nuklear)

file(GLOB_RECURSE nuklear_3rdParty_Lib  ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/nuklear/*.h ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/nuklear/*.c )

message(STATUS "nuklear-->${nuklear_3rdParty_Lib}")

file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_library(userInterface_module ${SOURCE_FILES} ${nuklear_3rdParty_Lib})

target_include_directories(userInterface_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/nuklear/")

target_include_directories(userInterface_module PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/" )

target_link_libraries(userInterface_module PUBLIC graphicEngine_module)



