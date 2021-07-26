//
// Created by Tseng Jianjun on 2021/6/16.
//


#include <sys/socket.h>
#include <stdio.h>
#include "../lib/common.h"


void read_data(int sockfd)
{
    ssize_t n;
    char buf[1024];/* 缓冲区大小为1024 */

    int time = 0;
    for (;;)
    {
        fprintf(stdout, "block in read\n");
        /* 实际每次读取 1K 数据。*/
        if ((n = readn(sockfd, buf, 1024)) == 0)
        {
            return;/* 表示读到文件的末尾了 */
        }
        time++;
        fprintf(stdout, "1K read for %d \n", time);
        /* 模拟服务端处理任务耗时 */
        usleep(2000);
    }
}

int main(int argc, char **argv)
{
    int listenfd, connfd;
    socklen_t clien;
    struct sockaddr_in cliaddr, servaddr;/* 使用时要先初始化 */
    /* AF_INET表示ipv4,SOCK_STREAM表示TCP数据流 */
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    /* 初始化servaddr,设置通配地址和端口 */
    bzero(&servaddr, sizeof(servaddr));/* 相当于memset(&serv_addr, 0, sizeof(serv_addr));  //每个字节都用0填充 */
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);/* htonl()表示将32位的主机字节顺序转化为32位的网络字节顺序; */
    servaddr.sin_port = htons(12345);

    /* bind到本地地址，端口为12345 */
    bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    /* listen的backlog为1024 */
    listen(listenfd, 1024);

    /* 循环处理用户请求 */
    for (;;)
    {
        clien = sizeof(cliaddr);
        /* 通过 accept 获取实际的连接，并开始读取数据。*/
        connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clien);
        read_data(connfd);/* 读取数据 ，每次读取1K*/
        close(connfd);/* 关闭连接套接字，注意不是监听套接字*/
    }


}