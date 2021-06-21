if(not ${INPUT_FILE})
    message(FATAL "No input file specified, incorrect script useage."
                "Correct useage requires -DINPUT_FILE be set.")
endif()

if(not ${OUTPUT_FILE})
    message(WARNING "No output file specified, defaulting to CMakeLists.txt")
    set(OUTPUT_FILE "CMakeLists.txt")
endif()

configure_file(${INPUT_FILE} ${OUTPUT_FILE} @ONLY)