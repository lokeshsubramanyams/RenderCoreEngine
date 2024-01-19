
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

    add_custom_command(
        OUTPUT ${GENERATED_HEADER}
        COMMAND ${XXD} -i ${SHADER_FILE} ${GENERATED_HEADER}
        DEPENDS ${SHADER_FILE}
        COMMENT "Generating shader header ${GENERATED_HEADER}"
    )

    # Collect the generated headers (if you want to create a custom target)
    list(APPEND GENERATED_HEADERS ${GENERATED_HEADER})
    message(STATUS ${GENERATED_HEADER})
endforeach()

# Optional: Create a custom target for the generated headers
add_custom_target(GenerateShaderHeaders ALL
    DEPENDS ${GENERATED_HEADERS}
    COMMENT "Generating shader headers..."
)

