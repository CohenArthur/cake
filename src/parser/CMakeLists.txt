add_library(parser STATIC
    parser.cpp
    expand.cpp
    )

target_link_libraries(parser PRIVATE
    rules
    comment
    command
    variables
    expansion
    )
