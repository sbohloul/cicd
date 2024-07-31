add_subdirectory(math)

add_executable(prog)
target_sources(prog 
    PRIVATE 
        main.cpp
)
target_link_libraries(prog
    PRIVATE
        math
        # 
        $<$<BOOL:${ENABLE_COVERAGE}>:coverage_compile_flags>
        $<$<BOOL:${ENABLE_COVERAGE}>:coverage_link_flags>
)

set_target_properties(prog
    PROPERTIES
        VERSION
            ${PROJECT_VERSION}
        SOVERSION
            ${PROJECT_VERSION_MINOR}
)