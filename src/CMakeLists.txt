include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(fsm)
add_subdirectory(modules)

add_executable (logparser "main.cc")

target_link_libraries(logparser PUBLIC modules fsm)

install(TARGETS logparser DESTINATION ${PROJECT_SOURCE_DIR}/bin)
