add_executable (logreader
                modules/killdata.cc
                modules/matchdata.cc
                modules/state.cc
                modules/parser.cc
                main.cc)
install(TARGETS logreader DESTINATION ${PROJECT_SOURCE_DIR}/bin)
