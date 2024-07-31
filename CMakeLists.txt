cmake_minimum_required(VERSION 3.20 FATAL_ERROR)

project(cicd LANGUAGES CXX)


# set(ENABLE_TESTING ON CACHE BOOL "Enable testing")
# set(ENABLE_COVERAGE ON CACHE BOOL "Enable coverage")

if(ENABLE_COVERAGE)
    include(cmake/coverage.cmake)
    add_dependencies(coverage unittests)
endif()

add_subdirectory(src)

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)

    add_custom_target(unittests)
    add_dependencies(unittests test_unit_math)
endif()