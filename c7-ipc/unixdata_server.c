//
// Created by Tseng Jianjun on 2021/6/17.
//

#include "lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: unixdataserver <local_path>");
    }

    /* 创建数据报本地套接字 */
    int socket_fd;
    socket_fd = socket(AF_LOCAL, SOCK_DGRAM, 0);
    if (socket_fd < 0)
    {
        error(1, errno, "socket create failed");
    }

    /* 使用本地地址的绝对路径初始化服务器端的地址 */
    struct sockaddr_un servaddr;
    char *local_path = argv[1];
    unlink(local_path);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, local_path);

    /* 绑定服务器地址和端口 */
    if (bind(socket_fd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    {
        error(1, errno, "bind failed");
    }

    char buf[BUFFER_SIZE];
    struct sockaddr_un client_addr;
    socklen_t client_len = sizeof(client_addr);

    while (1)
    {
        /* 接收客户端发送的数据到buf中 */
        bzero(buf, sizeof(buf));
        if (recvfrom(socket_fd, buf, BUFFER_SIZE, 0, (struct sockadd *) &client_addr, &client_len) == 0)
        {
            printf("client quit");
            break;
        }
        printf("Receive: %s \n", buf);

        /* 初始化要发送的数据到send_line */
        char send_line[MAXLINE];
        bzero(send_line, MAXLINE);
        sprintf(send_line, "Hi, %s", buf);

        size_t nbytes = strlen(send_line);
        printf("now sending: %s \n", send_line);
        /* 向客户端发送数据 */
        if (sendto(socket_fd, send_line, nbytes, 0, (struct sockadd *) &client_addr, client_len) != nbytes)
            error(1, errno, "sendto error");
    }
    close(socket_fd);

    exit(0);
}