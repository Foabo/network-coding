//
// Created by Tseng Jianjun on 2021/6/17.
//

#include "../lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: udpclient <IPaddress>");
    }

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0); /* 创建UDP套接字 */

    /* 初始化目标服务器的地址和端口。*/
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    socklen_t server_len = sizeof(server_addr);

    struct sockaddr *reply_addr;
    reply_addr = malloc(server_len);

    char send_line[MAXLINE], recv_line[MAXLINE + 1];
    socklen_t len;
    int n;

    while (fgets(send_line, MAXLINE, stdin) != NULL)
    {
        int i = strlen(send_line);
        if (send_line[i - 1] == '\n')
        {
            send_line[i - 1] = 0;
        }
        printf("now sending %s\n", send_line);
        /* 向服务端发送数据 */
        size_t rt = sendto(socket_fd, send_line, i, 0, (struct sockaddr *) &server_addr, server_len);
        if (rt < 0)
        {
            error(1, errno, "send failed ");
        }
        printf("send bytes: %zu \n", rt);

        len = 0;
        /* 阻塞在这里，接收从服务端到来的数据 放到recv_line中*/
        n = recvfrom(socket_fd, recv_line, MAXLINE, 0, reply_addr, &len);
        if (n < 0)
        {
            error(1, errno, "recvfrom failed");
        }
        recv_line[n] = 0;
        /* 将接收到的recv_line输出到控制台*/
        fputs(recv_line, stdout);
        fputs("\n", stdout);

    }
    exit(0);


}