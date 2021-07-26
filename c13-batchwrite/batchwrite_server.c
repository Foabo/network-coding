#include "../lib/common.h"

static int count;

// 获取杀死信号调用这个方法
static void sig_int(int signo)
{
    printf("\nreceived %d datagrams\n", count);
    exit(0);
}

int main(int argc, char **argv)
{
    /* 创建监听套接字 */
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    /* 初始化服务器的地址，设置端口和协议 */
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    /* bind函数绑定地址和端口 */
    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0)
    {
        error(1, errno, "bind failed ");
    }

    /* listen监听套接字 */
    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0)
    {
        error(1, errno, "listen failed ");
    }

    /* 设置信号传输 */
    signal(SIGINT, sig_int);
    signal(SIGPIPE, SIG_IGN);

    /* accpet等待客户端连接 */
    int connfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    /* 调用accept得到连接套接字 connfd*/
    if ((connfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_len)) < 0)
    {
        error(1, errno, "bind failed ");
    }

    // 接收缓冲
    char message[MAXLINE];
    count = 0;

    for (;;)
    {
        // 读取connd连接套接字的发送过来的数据
        int n = read(connfd, message, MAXLINE);
        if (n < 0)
        {
            error(1, errno, "error read");
        } else if (n == 0)
        {
            error(1, 0, "client closed \n");
        }
        message[n] = 0;// 将换行给去除
        printf("received %d bytes: %s\n", n, message);
        count++;

        /* 发送缓冲 */
        char send_line[MAXLINE];
        sprintf(send_line, "Hi, %s", message);

        sleep(5);

        int write_nc = send(connfd, send_line, strlen(send_line), 0);
        printf("send bytes: %zu \n", write_nc);
        if (write_nc < 0)
        {
            error(1, errno, "error write");
        }

    }

}