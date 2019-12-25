cmake_minimum_required(VERSION 3.8)
project(cake LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_COMPILER clang++)

add_compile_definitions(
    _GNU_SOURCE
)

option (ENABLE_TESTS OFF)

if (ENABLE_TESTS)
    add_compile_options(
        "-g3"
        "-fsanitize=address"
        )

    add_link_options(
        "-lasan"
        )
endif()

add_compile_options(
    "-Wall"
    "-Wextra"
    "-Werror"
    "-pedantic"
    )

include_directories(src/)

add_subdirectory(src)

add_executable(cake src/cake.cpp)

target_link_libraries(cake PRIVATE
    rules
    )

if (ENABLE_TESTS)
    list (APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tests")
    find_package(Criterion REQUIRED)

    enable_testing()

    #add_subdirectory(tests EXCLUDE_FROM_ALL)

    add_custom_target(check
        make; COMMAND ${CMAKE_CTEST_COMMAND} --verbose
        DEPENDS
        )
endif()
