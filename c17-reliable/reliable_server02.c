//
// Created by Tseng Jianjun on 2021/6/24.
//

#include "lib/common.h"


int main(int argc, char **argv) {
    int connfd;
    char buf[1024];
    int time = 0;
    // 也就是 创建连接套接字，bind,accept，accept成功返回连接套接字connfd
    connfd = tcp_server(SERV_PORT);

    while (1) {
        // 每次读1k字符
        int n = read(connfd, buf, 1024);
        if (n < 0) {
            error(1, errno, "error read");
        } else if (n == 0) {
            error(1, 0, "client closed \n");
        }

        time++;
        fprintf(stdout, "1K read for %d \n", time);
        usleep(10000);
    }

    exit(0);

}