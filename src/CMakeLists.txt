include_directories(${CMAKE_CURRENT_SOURCE_DIR})

file(GLOB source
    "modules/*.cc"
    "fsm/*.cc"
    "main.cc")

add_executable (logparser ${source})
install(TARGETS logparser DESTINATION ${PROJECT_SOURCE_DIR}/bin)
