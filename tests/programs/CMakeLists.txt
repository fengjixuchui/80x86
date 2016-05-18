macro(nasm_file filename output)
    add_custom_command(OUTPUT ${output}
                       COMMAND nasm -o ${output} -f bin ${CMAKE_CURRENT_SOURCE_DIR}/${filename}
                       DEPENDS ${filename})
    add_custom_target(tests ALL
                      DEPENDS ${output})
endmacro(nasm_file)

nasm_file(moves.asm moves.bin)