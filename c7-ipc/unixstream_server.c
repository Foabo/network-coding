//
// Created by Tseng Jianjun on 2021/6/17.
//

#include "../lib/common.h"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: unixstreamserver <local_path>");
    }
    int listenfd, connfd;
    socklen_t clilen;
    struct sockaddr_un cliaddr, servaddr;

    /* 创建本地套接字，格式是字节流SOCK_STREAM*/
    listenfd = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (listenfd < 0)
    {
        error(1, errno, "socket create failed");
    }
    /* 接下来初始化服务器地址结构，协议簇为AF_LOCAL */
    char *local_path = argv[1];
    unlink(local_path);/* unlink 操作，以便把存在的文件删除掉，这样可以保持幂等性。 */
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sun_family = AF_LOCAL;
    strcpy(servaddr.sun_path, local_path);

    /* 绑定地址和端口 */
    if (bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0)
    {
        error(1, errno, "bind failed");
    }

    /* 监听在一个本地文件路径标识的套接字上 */
    if (listen(listenfd, LISTENQ) < 0)
    {
        error(1, errno, "listen failed");
    }

    clilen = sizeof(cliaddr);
    /* accept在这里等待客户端连接 */
    if ((connfd = accept(listenfd, (struct sockaddr *) &cliaddr, &clilen)) < 0)
    {
        if (errno == EINTR)
            error(1, errno, "accept failed");        /* back to for() */
        else
            error(1, errno, "accept failed");
    }

    char buf[BUFFER_SIZE];
    while (1)
    {
        bzero(buf, sizeof(buf));
        /* 读取数据 */
        if (read(connfd, buf, BUFFER_SIZE) == 0)
        {
            printf("client quit");
            break;
        }
        printf("Receive: %s", buf);

        char send_line[MAXLINE];
        bzero(send_line, MAXLINE);
        sprintf(send_line, "Hi, %s", buf);

        int nbytes = sizeof(send_line);
        /* 发送数据 */
        if (write(connfd, send_line, nbytes) != nbytes)
            error(1, errno, "write error");

    }
    /* 关闭连接 */
    close(listenfd);
    close(connfd);

    exit(0);

}