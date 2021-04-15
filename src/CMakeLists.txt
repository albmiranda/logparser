add_executable (logreader
                modules/killdata.cc main.cc)
install(TARGETS logreader DESTINATION ${PROJECT_SOURCE_DIR}/bin)
