if (EPOLL_EXISTS)
    set(network_coding_lib
            log.c
            sock_ntop.c
            read.c
            tcp_server.c
            tcp_client.c
            event_loop.c
            channel.c
            acceptor.c
            channel_map.c
            poll_dispatcher.c
            thread_pool.c
            event_loop_thread.c
            utils.c
            epoll_dispatcher.c
            buffer.c
            tcp_connection.c
            http_server.c
            http_request.c
            http_response.c
            ../c7-ipc/unixstream_server.c ../c7-ipc/unixstream_client.c)
else ()
    set(network_coding_lib
            log.c
            sock_ntop.c
            read.c
            tcp_server.c
            tcp_client.c
            event_loop.c
            channel.c
            acceptor.c
            channel_map.c
            poll_dispatcher.c
            thread_pool.c
            event_loop_thread.c
            utils.c
            buffer.c
            tcp_connection.c
            http_server.c
            http_request.c
            http_response.c
            ../c6-udp/udp_server.c ../c6-udp/udp_client.c ../c7-ipc/unixstream_server.c ../c7-ipc/unixstream_client.c)
endif ()


add_library(network_coding ${network_coding_lib})
target_link_libraries(network_coding pthread)

install(TARGETS network_coding DESTINATION lib)

#file(GLOB HEADERS "*.h")
#install(FILES ${HEADERS} DESTINATION include/)

