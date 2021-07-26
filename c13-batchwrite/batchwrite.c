//
// Created by Tseng Jianjun on 2021/6/21.
//
#include "lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: graceclient <IPaddress>");

    }
    // 初始化TCP套接字
    int socket_fd;
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 初始化服务器的地址
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    /* 客户端连接服务器 */
    socklen_t server_len = sizeof(server_addr);
    int connect_rt = connect(socket_fd, (struct sockaddr *) &server_addr, server_len);
    if (connect_rt < 0)
    {
        error(1, errno, "connect failed ");
    }

    char buf[128];
    struct iovec iov[2];

    char *send_one = "hello,";
    iov[0].iov_base = send_one;
    iov[0].iov_len = strlen(send_one);
    iov[1].iov_base = buf;
    while(fgets(buf,sizeof (buf),stdin)){
        iov[1].iov_len = strlen(buf);

        if(writev(socket_fd,iov,2)<0){
            error(1, errno, "writev failure");
        }
    }



}
