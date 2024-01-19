find_program(XXD xxd)
if(NOT XXD)
    message(FATAL_ERROR "xxd not found")
else()
    message(STATUS "xxd found")
endif()

file(GLOB SHADER_FILES  ${CMAKE_CURRENT_SOURCE_DIR}/*.vert ${CMAKE_CURRENT_SOURCE_DIR}/*.frag)

foreach(SHADER_FILE IN LISTS SHADER_FILES)
 
    get_filename_component(SHADER_NAME_WE ${SHADER_FILE} NAME_WE) # Name without extension
    get_filename_component(SHADER_EXT ${SHADER_FILE} EXT) # Extension
    string(REPLACE "." "_" SHADER_EXT_CLEAN ${SHADER_EXT}) # Replace '.' with '_' for valid C identifiers
    set(GENERATED_HEADER "${CMAKE_CURRENT_BINARY_DIR}/${SHADER_NAME_WE}${SHADER_EXT_CLEAN}.h")
           
     
    execute_process(
        COMMAND ${XXD} -i  ${SHADER_FILE} ${GENERATED_HEADER} 
        RESULT_VARIABLE XXD_RESULT
        OUTPUT_VARIABLE XXD_OUTPUT
        ERROR_VARIABLE XXD_ERROR
    )

    if(NOT XXD_RESULT EQUAL 0)
        message(FATAL_ERROR "xxd failed: ${XXD_ERROR}")
    endif()

    # Optionally print xxd output for debugging purposes
    message(STATUS "xxd output: ${XXD_OUTPUT}")

endforeach()
