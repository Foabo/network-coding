//
// Created by Tseng Jianjun on 2021/6/17.
//

#include "../lib/common.h"

static int count;

static void recvfrom_init(int signo)
{
    printf("\nreceived %d datagrams\n", count);
    exit(0);
}

int main(int argc, char **argv)
{
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htons(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    bind(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));

    socklen_t client_len; // uint32
    char message[MAXLINE];// 4096
    count = 0; // 记录连接的次数

    // 创建了一个信号处理函数，以便在响应“Ctrl+C”退出时，打印出收到的报文总数。
    signal(SIGTERM, recvfrom_init);

    struct sockaddr_in client_addr;
    client_len = sizeof(client_addr);
    for (;;)
    {
        int n = recvfrom(socket_fd, message, MAXLINE, 0, (struct sockaddr *) &client_addr, &client_len);
        message[n] = 0;
        printf("received %d bytes: %s\n", n, message);

        char send_line[MAXLINE];
        sprintf(send_line, "Hi, %s", message);

        sendto(socket_fd, send_line, strlen(send_line), 0, (struct sockaddr *) &client_addr, client_len);

        count++;
    }
}