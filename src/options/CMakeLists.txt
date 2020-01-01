add_library(options STATIC
    options.cpp
    )

target_link_libraries(options INTERFACE
    ${Boost_LIBRARIES}
    )
