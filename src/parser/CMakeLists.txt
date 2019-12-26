add_library(parser STATIC
    parser.cpp
    )

target_link_libraries(parser PRIVATE
    rules
    comment
    variables
    )
