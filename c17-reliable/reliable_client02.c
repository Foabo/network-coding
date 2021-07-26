//
// Created by Tseng Jianjun on 2021/6/24.
//

#include "lib/common.h"

# define MESSAGE_SIZE 102400

int main(int argc, char **argv) {
    if (argc != 2) {
        error(1, 0, "usage: reliable_client02 <IPaddress>");
    }
    // 返回客户端connect之后的套接字
    int socket_fd = tcp_client(argv[1], SERV_PORT);

    // 信号处理函数
    signal(SIGPIPE, SIG_IGN);

    char *msg = "network programming";
    ssize_t n_written;

    int count = 10000000;
    // 循环发送数据
    while (count > 0) {
        n_written = send(socket_fd, msg, strlen(msg), 0);
        fprintf(stdout, "send into buffer %ld \n", n_written);
        if (n_written <= 0) {
            error(1, errno, "send error");
            return -1;
        }
        count--;
    }
    return 0;
}