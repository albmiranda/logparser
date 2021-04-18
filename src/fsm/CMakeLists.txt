file(GLOB source "*.cc")

add_library(fsm STATIC ${source})

target_link_libraries(fsm PUBLIC modules)