add_executable(test_unit_math)
target_sources(test_unit_math
    PRIVATE 
        test_math.cpp
)
target_link_libraries(test_unit_math
    PRIVATE
        math
        #
        $<$<BOOL:${ENABLE_COVERAGE}>:coverage_link_flags>
)

add_test(
    NAME 
        test_unit_math 
    COMMAND 
        test_unit_math
)