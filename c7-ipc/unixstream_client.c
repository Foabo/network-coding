//
// Created by Tseng Jianjun on 2021/6/17.
//

#include "../lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: unixstreamclient <local_path>");
    }

    int sockfd;
    struct sockaddr_un servaddr;

    /* 创建本地连接套接字 */
    sockfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error(1, errno, "create socket failed");
    }

    /* 初始化服务端地址 */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, argv[1]);

    /* connect 与服务端连接，与TCP不同的是不会有三次握手*/
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    {
        error(1, errno, "connect failed");
    }

    char send_line[MAXLINE];
    bzero(send_line, MAXLINE);
    char recv_line[MAXLINE];
    /* 获取从标准输入中的字符数据到send_line中进行发送 */
    while (fgets(send_line, MAXLINE, stdin) != NULL)
    {
        int nbytes = sizeof(send_line);
        /* 向服务端发送数据 */
        if (write(sockfd, send_line, nbytes) != nbytes)
            error(1, errno, "write error");

        /* 接收来自服务端的数据 */
        if (read(sockfd, recv_line, MAXLINE) == 0)
            error(1, errno, "server terminated prematurely");

        /* 将接收到的数据输出到标准输出中，打印到控制台 */
        fputs(recv_line, stdout);
    }
    exit(0);
}