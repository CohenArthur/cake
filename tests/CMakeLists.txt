add_executable(test_rules test_rules.cpp)
add_executable(test_variables test_variables.cpp)
add_executable(test_parser test_parser.cpp)

target_link_libraries(test_rules PRIVATE
    rules
    comment
    ${CRITERION_LIBRARIES}
    )

target_link_libraries(test_variables PRIVATE
    variables
    ${CRITERION_LIBRARIES}
    )

target_link_libraries(test_parser PRIVATE
    parser
    ${CRITERION_LIBRARIES}
    )
