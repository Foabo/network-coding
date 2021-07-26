add_executable(cmdclient cmdclient.c)
target_link_libraries(cmdclient network_coding)

add_executable(cmdserver cmdserver.c)
target_link_libraries(cmdserver network_coding)