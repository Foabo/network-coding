add_executable(udpclient udp_client.c)
target_link_libraries(udpclient network_coding)

add_executable(udpserver udp_server.c)
target_link_libraries(udpserver network_coding)