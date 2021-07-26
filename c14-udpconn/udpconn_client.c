//
// Created by Tseng Jianjun on 2021/6/23.
//
#include "lib/common.h"

static int count;

static void recvfrom_int(int signo)
{
    printf("\nreceived %d datagrams\n", count);
    exit(0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: udpclient1 <IPaddress>");
    }

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    socklen_t server_len = sizeof(server_addr);

    // 加上一个connect函数，告诉操作系统，绑定服务器地址和端口
    if (connect(socket_fd, (struct sockaddr *) &server_addr, server_len))
    {
        error(1, errno, "connect failed");
    }

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
        // 发送数据
        printf("now sending %s\n", send_line);
        // sendto对应server_addr,向一指定目的地发送数据。
        // 在mac上会有奇怪的结果。使用推荐的send
//        size_t rt = sendto(socket_fd, send_line, strlen(send_line), 0, (struct sockaddr *) &server_addr, server_len);
        size_t rt = send(socket_fd,send_line, strlen(send_line),0);

        if (rt < 0)
        {
            error(1, errno, "sendto failed");
        }
        printf("send bytes: %zu \n", rt);

        // 接收数据
        len = 0;
        recv_line[0] = 0;
        // recvfrom对应reply_addr，接收一个数据报并保存数据发送源地址。
        // n = recvfrom(socket_fd, recv_line, MAXLINE, 0, reply_addr, &len);
        n = recv(socket_fd, recv_line, MAXLINE, 0);
        if (n < 0)
            error(1, errno, "recvfrom failed");
        recv_line[n] = 0;
        fputs(recv_line, stdout);
        fputs("\n", stdout);


    }
}
