//
// Created by Tseng Jianjun on 2021/6/18.
//

#include "../lib/common.h"

/* 客户端程序 ，进行 close 和 shutdown 的实验。 */
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

    /* 应用程序的发送和接收缓冲区 */
    char send_line[MAXLINE], recv_line[MAXLINE + 1];
    int n;

    // select()机制中提供一fd_set的数据结构，实际上是一long类型的数组
    fd_set readmask;
    fd_set allreads;

    FD_ZERO(&allreads); /*将allreads清零使集合中不含任何fd*/
    FD_SET(0, &allreads);  /*将allreads的第0位置1，如allreads原来是00000000，则现在变为100000000，这样fd==1的文件描述字就被加进allreads中了*/
    FD_SET(socket_fd, &allreads);
    for (;;)
    {
        readmask = allreads;
        int rc = select(socket_fd + 1, &readmask, NULL, NULL, NULL);
        if (rc <= 0)
            error(1, errno, "select failed");
        /* 测试fd是否在set集合中 */
        /* 测试readmask的第socket_fd位是否为1，如果原来readmask是10000100，则返回非零，表明fd==socket_fd的文件描述符在readmask中，否则返回0*/
        if (FD_ISSET(socket_fd, &readmask))
        {
            n = read(socket_fd, recv_line, MAXLINE);
            if (n < 0)
            {
                error(1, errno, "read error");
            } else if (n == 0)/* 读到文件末尾EOF */
            {
                error(1, 0, "server terminated \n");
            }
            recv_line[n] = 0;
            fputs(recv_line, stdout);
            fputs("\n", stdout);
        }
        /*  获取键盘输入，采取对应的处理逻辑  */
        if (FD_ISSET(0, &readmask))
        {
            if (fgets(send_line, MAXLINE, stdin) != NULL)
            {   /* 发送shutdown，执行shutdown函数 */
                if (strncmp(send_line, "shutdown", 8) == 0)
                {
                    /* 关闭标准输入的 I/O 事件感知，并调用 shutdown 函数关闭写方向*/
                    FD_CLR(0, &allreads);/*将fd从allreads集合中清除*/
                    if (shutdown(socket_fd, 1))
                    {
                        error(1, errno, "shutdown failed");
                    }
                }
                    /* 发送close，执行close函数 */
                else if (strncmp(send_line, "close", 5) == 0)
                {
                    FD_CLR(0, &allreads);
                    if (close(socket_fd))
                    {
                        error(1, errno, "close failed");
                    }
                    sleep(6);
                    exit(0);
                }
                /* 处理正常的输入，将回车符截掉，调用 write 函数，通过套接字将数据发送给服务器端。  */
                else
                {
                    int i = strlen(send_line);
                    if (send_line[i - 1] == '\n')
                    {
                        send_line[i - 1] = 0;
                    }

                    printf("now sending %s\n", send_line);
                    size_t rt = write(socket_fd, send_line, strlen(send_line));
                    if (rt < 0)
                    {
                        error(1, errno, "write failed ");
                    }
                    printf("send bytes: %zu \n", rt);
                }

            }
        }

    }


}