
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)


file(GLOB_RECURSE SOURCE_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.h ${CMAKE_CURRENT_SOURCE_DIR}/*.c)

add_library(nuklear_3rdParty_Lib  ${SOURCE_FILES})

target_include_directories(nuklear_3rdParty_Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/  )

target_link_libraries(nuklear_3rdParty_Lib PUBLIC graphicEngine_module)