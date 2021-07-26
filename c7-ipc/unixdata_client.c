//
// Created by Tseng Jianjun on 2021/6/17.
//

#include "lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: unixdataclient <local_path>");
    }
    int sockfd;
    struct sockaddr_un client_addr, server_addr;

    /* 初始化本地数据报套接字 */
    sockfd = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        error(1, errno, "create socket failed");
    }

    /* 初始化客户端的地址 */
    bzero(&client_addr, sizeof(client_addr));        /* bind an address for us */
    client_addr.sun_family = AF_LOCAL;
    strcpy(client_addr.sun_path, tmpnam(NULL));
    /* 绑定到客户端地址到本地路径上 */
    if (bind(sockfd, (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0)
    {
        error(1, errno, "bind failed");
    }

    /* 初始化服务端的地址 */
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sun_family = AF_LOCAL;
    strcpy(server_addr.sun_path, argv[1]);

    /* 初始化send_line和recv_line ，一个用来保存发送的数据，一个用来保存接收的数据 */
    char send_line[MAXLINE];
    bzero(send_line, MAXLINE);
    char recv_line[MAXLINE];

    /* 从标准输入中的数据到send_line */
    while (fgets(send_line, MAXLINE, stdin) != NULL)
    {
        int i = strlen(send_line);
        if (send_line[i - 1] == '\n')
        {
            send_line[i - 1] = 0;
        }
        size_t nbytes = strlen(send_line);
        printf("now sending %s \n", send_line);

        /* 将send_line的数据发送到服务端 */
        if (sendto(sockfd, send_line, nbytes, 0, (struct sockaddr *) &server_addr, sizeof(server_addr)) != nbytes)
            error(1, errno, "sendto error");

        /* 接收服务端的数据到recv_line */
        int n = recvfrom(sockfd, recv_line, MAXLINE, 0, NULL, NULL);
        recv_line[n] = 0;

        /* 将recv_line的内容打印到控制台 */
        fputs(recv_line, stdout);
        fputs("\n", stdout);

    }
}