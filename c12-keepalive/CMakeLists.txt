add_executable(pingclient pingclient.c)
target_link_libraries(pingclient network_coding)

add_executable(pingserver pingserver.c)
target_link_libraries(pingserver network_coding)