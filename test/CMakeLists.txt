include_directories("../src")

file(GLOB source
    "modules/*.cc"
    "fsm/*.cc"
    "main.cc")

add_executable (logparser_test ${source})

target_link_libraries(logparser_test PUBLIC gtest gmock pthread modules fsm)

add_test(NAME logparser_test COMMAND logparser_test)