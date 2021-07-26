//
// Created by Tseng Jianjun on 2021/7/2.
//
#include "lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        error(1, 0, "usage: reliable_client01 <IPaddress> <Port>");
    }
    /* 创建套接字 */
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    /* 绑定客户端和地址 */
    struct sockaddr_in server_addr;
    /* 初始化server_addr */
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr);
    int port = atoi(argv[2]);
    server_addr.sin_port = htons(port);
    /* 以上，等价于 int socket_fd = tcp_client(argv[1], port); */


    /* connect */
    int conn_rt = connect(socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (conn_rt < 0)
    {
        error(1, errno, "connect failed ");
    }

    /* 初始化应用程序buffer */
    char recv_buf[MAXLINE], send_buf[MAXLINE];
    ssize_t n;// 读取和发送字节数

    fd_set readmask;
    fd_set allreads;
    FD_ZERO(&allreads);
    FD_SET(0, &allreads);
    FD_SET(socket_fd, &allreads);

    for (;;)
    {
        readmask = allreads;
        int rc = select(socket_fd + 1, &readmask, NULL, NULL, NULL);// 没有添加超时处理

        if (rc <= 0)
        {
            error(1, errno, "select fail");
        }

        // 如果当前套接字收到服务端发来信息
        if (FD_ISSET(socket_fd, &readmask))
        {
            n = read(socket_fd, recv_buf, MAXLINE);
            if (n < 0)
            {
                error(1, errno, "read error");
            } else if (n == 0)// 收到fin
            {
                printf("server closed \n");
                break;
            } else
            {
                recv_buf[n] = 0;//尾部截断
                fputs(recv_buf, stdout);
                fputs("\n", stdout);
            }
        }
        // 第一个参数是0，标准输入stdin的描述符
        if (FD_ISSET(STDIN_FILENO, &readmask))
        {
            // 获取控制台输入
            if (fgets(send_buf, MAXLINE, stdin) != NULL)
            {
                int i = strlen(send_buf);
                if (send_buf[i - 1] == '\n')
                {
                    send_buf[i - 1] = 0;
                }

                if (strncmp(send_buf, "quit", strlen(send_buf)) == 0)
                {
                    if (shutdown(socket_fd, SHUT_WR))// 关闭写段端
                    {
                        error(1, errno, "shutdown failed");
                    }
                }
                /* 向服务端发送数据 */
                size_t rt = write(socket_fd, send_buf, strlen(send_buf));
                if (rt < 0)
                {
                    error(1, errno, "write failed ");
                }
            }
        }


    }
    exit(0);


}