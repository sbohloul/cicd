add_library(math SHARED)
target_sources(math
    PRIVATE
        math.cpp
        math.hpp
)
target_link_libraries(math
    PRIVATE
        $<$<BOOL:${ENABLE_COVERAGE}>:coverage_compile_flags>
        $<$<BOOL:${ENABLE_COVERAGE}>:coverage_link_flags>
)
target_include_directories(math
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
)