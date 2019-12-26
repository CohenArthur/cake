add_executable(test_rules test_rules.cpp)

target_link_libraries(test_rules PRIVATE
    rules
    ${CRITERION_LIBRARIES}
    )
