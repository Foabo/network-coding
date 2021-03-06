//
// Created by Tseng Jianjun on 2021/6/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>


int make_socket (uint16_t port)
{
    int sock;
    struct sockaddr_in serv_addr;


    /* 创建字节流类型的 IPV4 socket. */
    sock = socket (PF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror ("socket");
        exit (EXIT_FAILURE);
    }


    /* 绑定到 port 和 ip. */
    serv_addr.sin_family = AF_INET; /* IPV4 */
    serv_addr.sin_port = htons (port);  /* 指定端口 */
    serv_addr.sin_addr.s_addr = htonl (INADDR_ANY); /* 通配地址 */
    /* 把 IPV4 地址转换成通用地址格式，同时传递长度 */
    if (bind (sock, (struct sockaddr *) &serv_addr, sizeof (serv_addr)) < 0)
    {
        perror ("bind");
        exit (EXIT_FAILURE);
    }


    return sock;
}