//
// Created by Tseng Jianjun on 2021/6/24.
//

#include "lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: tcpclient <IPaddress>");
    }

    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    socklen_t server_len = sizeof(server_addr);
    int connect_rt = connect(socket_fd, (struct sockaddr *) &server_addr, server_len);
    if (connect_rt < 0)
    {
        error(1, errno, "connect failed ");
    }
    /* 构造 message 结构体，定义报文格式 */
    struct
    {
        u_int32_t message_length;   /* 消息长度 4字节 */
        u_int32_t message_type;     /* 消息类型 4字节 */
        char data[128];             /* 真正的数据 */
    } message;


    int n;

    while (fgets(message.data, sizeof(message.data), stdin) != NULL)
    {
        n = strlen(message.data);
        /* 字节大小转化为了网络字节顺序 */
        message.message_length = htonl(n);
        message.message_type = 1;
        /* 结构体的数据都是连续存放的 */
        if (send(socket_fd, (char *) &message, sizeof(message.message_length) + sizeof(message.message_type) + n, 0) <
            0)
            error(1, errno, "send failure");

    }
    exit(0);
}
