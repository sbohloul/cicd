find_program(_gcov_exe NAMES gcov REQUIRED)
find_program(_lcov_exe NAMES lcov REQUIRED)
find_program(_genhtml_exe NAMES genhtml REQUIRED)

# Interface target for adding coverage compile flags
add_library(coverage_compile_flags INTERFACE)
target_compile_options(coverage_compile_flags
   INTERFACE
      -fprofile-arcs
      -ftest-coverage
)

# Interface target for adding coverage link flags
add_library(coverage_link_flags INTERFACE)
target_link_options(coverage_link_flags
   INTERFACE
      -fprofile-arcs
)

# Target to trigger lcove and genhtml to generate coverage report
set(_lcov_output_info_file "coverage.info")
set(_genhtml_output_dir "coverage_html")
#
set(_lcov_preproccess_command
   COMMAND ${_lcov_exe} --directory ${CMAKE_BINARY_DIR} --zerocounters
   # COMMAND ${_lcov_exe} --list coverage.info
   COMMAND ${_lcov_exe} --gcov-tool ${_gcov_exe} --capture --initial --directory ${CMAKE_BINARY_DIR} --output-file "base_${_lcov_output_info_file}"

)
set(_lcov_generate_cov_command
   COMMAND ${_lcov_exe} --gcov-tool ${_gcov_exe} --capture --directory ${CMAKE_BINARY_DIR} --output-file "test_${_lcov_output_info_file}"
   COMMAND ${_lcov_exe} --add-tracefile "base_${_lcov_output_info_file}" --add-tracefile "test_${_lcov_output_info_file}" --output-file ${_lcov_output_info_file}
   COMMAND ${_lcov_exe} --remove ${_lcov_output_info_file} '/usr/*' --output-file ${_lcov_output_info_file}
)
set(_genhtml_command
    COMMAND ${_genhtml_exe} --legend --title="nanotools coverage report" --num-spaces=4 ${_lcov_output_info_file} --output-directory ${_genhtml_output_dir}
)
set(_ctest_command
	COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
)
#
add_custom_target(coverage
   COMMAND ${CMAKE_COMMAND} -E echo "Running lcov preprocess command"
   ${_lcov_preproccess_command}
   COMMAND ${CMAKE_COMMAND} -E echo "Running ctest"
   ${_ctest_command}
   COMMAND ${CMAKE_COMMAND} -E echo "Running lcov generate command"
   ${_lcov_generate_cov_command}
   COMMAND ${CMAKE_COMMAND} -E echo "Running genhtml command"
   ${_genhtml_command}
   COMMAND ${CMAKE_COMMAND} -E echo "To see coverage report open ${CMAKE_BINARY_DIR}/${_genhtml_output_dir}/index.html"
   WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
   COMMENT "Generating code coverage report"
   VERBATIM
)