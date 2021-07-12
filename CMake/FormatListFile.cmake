if(NOT DEFINED ${INPUT_FILE})
    message(FATAL "No input file specified, incorrect script useage."
                "Correct useage requires -DINPUT_FILE be set.")
endif()

if(DEFINED ${OUTPUT_FILE})
    message(FATAL "No output file specified, incorrect script useage."
                  "Correct useage requires -DOUTPUT_FILE be set.")
endif()

configure_file(${INPUT_FILE} ${OUTPUT_FILE} @ONLY)