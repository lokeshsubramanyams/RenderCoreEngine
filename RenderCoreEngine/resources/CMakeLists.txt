#resources/CMakeLists.txt

file(GLOB_RECURSE RESOURCE_FILES
     RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     ${CMAKE_CURRENT_SOURCE_DIR}/*)

foreach(FILE ${RESOURCE_FILES})
    if(NOT FILE MATCHES "CMakeLists.txt")
        configure_file(${CMAKE_CURRENT_SOURCE_DIR}/${FILE} ${CMAKE_BINARY_DIR}/resources/${FILE} COPYONLY)
    endif()
endforeach()



