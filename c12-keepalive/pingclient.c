//
// Created by Tseng Jianjun on 2021/6/18.
//


/**
 * 客户端完全模拟 TCP Keep-Alive 的机制，在保活时间达到后，探活次数增加 1，
 * 同时向服务器端发送 PING 格式的消息，
 * 此后以预设的保活时间间隔，不断地向服务器端发送 PING 格式的消息。
 * 如果能收到服务器端的应答，则结束保活，将保活时间置为 0。
 *
 * 使用 select I/O 复用函数自带的定时器
 *
 * */

#include "lib/common.h"
#include "message_object.h"


#define    MAXLINE     4096
#define    KEEP_ALIVE_TIME  10          /* 保活时间 */
#define    KEEP_ALIVE_INTERVAL  3       /* 保活时间间隔 */
#define    KEEP_ALIVE_PROBETIMES  3     /* 保活探测次数 */


int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: tcpclient <IPaddress>");
    }

    /* 创建字节流格式socket*/
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    /* 初始化服务器地址 */
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    /* 连接服务器，发起三次握手 */
    socklen_t server_len = sizeof(server_addr);
    int connect_rt = connect(socket_fd, (struct sockaddr *) &server_addr, server_len);
    if (connect_rt < 0)
    {
        error(1, errno, "connect failed ");
    }

    /* 接受缓冲 */
    char recv_line[MAXLINE + 1];
    int n;

    /* select数据结构初始化 */
    fd_set readmask;
    fd_set allreads; /* long数组，理解为一组文件描述符 */
    /* 初始化 select 函数的套接字。 */
    FD_ZERO(&allreads);
    FD_SET(socket_fd, &allreads);

    /* 为 select 定时器准备： */
    struct timeval tv;
    int heartbeats = 0;

    tv.tv_sec = KEEP_ALIVE_TIME;    /* 秒 */
    tv.tv_usec = 0;                 /* 微秒 */

    messageObject messageObject;

    for (;;)
    {
        readmask = allreads;
        /* 第一个参数nfds在Linux指的是所有文件描述符的最大值加1，类型为int */
        /* 返回：做好准备的文件描述符的个数，超时为0，错误为 -1. */
        /* 最后一个参数timeout是可选的，若不为null，则用来设置超时时间，则为等待的超时时间；若为null，则将select设置为阻塞状态，直到文件描述符集合中某个文件描述符发生变化时才会返回结果。。 */
        int rc = select(socket_fd + 1, &readmask, NULL, NULL, &tv);
        if (rc < 0)
        {
            error(1, errno, "select failed");
        }
        /* rc == 0 select函数超时*/
        if (rc == 0)
        {
            // 检测发送心跳次数
            if (++heartbeats > KEEP_ALIVE_PROBETIMES)
            {
                error(1, 0, "connection dead\n");
            }
            printf("sending heartbeat #%d\n", heartbeats);
            messageObject.type = htonl(MSG_PING);
            rc = send(socket_fd, (char *) &messageObject, sizeof(messageObject), 0);
            if (rc < 0)
            {
                error(1, errno, "send failure");
            }
            tv.tv_sec = KEEP_ALIVE_INTERVAL;
            continue;
        }
        /* 如果socket_fd在select返回的集合里，说明有读事件*/
        if (FD_ISSET(socket_fd, &readmask))
        {
            n = read(socket_fd, recv_line, MAXLINE);
            if (n < 0)
            {
                error(1, errno, "read error");
            } else if (n == 0)
            {
                error(1, 0, "server terminated \n");
            }
            printf("received heartbeat, make heartbeats to 0 \n");
            heartbeats = 0;
            tv.tv_sec = KEEP_ALIVE_TIME;

        }


    }
}

