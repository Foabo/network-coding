//
// Created by Tseng Jianjun on 2021/6/18.
//

#include "lib/common.h"
#include "message_object.h"

static int count;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        error(1, 0, "usage: tcpsever <sleepingtime>");
    }
    /* 从启动时候输入的数字初始化睡眠事件，作为服务端处理逻辑 */
    int sleepingTime = atoi(argv[1]);

    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(SERV_PORT);

    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0)
    {
        error(1, errno, "bind failed ");
    }

    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0)
    {
        error(1, errno, "listen failed ");
    }

    int connfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((connfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_len)) < 0)
    {
        error(1, errno, "bind failed ");
    }

    messageObject message;
    count = 0;

    for (;;)
    {
        int n = read(connfd, (char *) &message, sizeof(messageObject));
        if (n < 0)
        {
            error(1, errno, "error read");
        } else if (n == 0)
        {
            error(1, 0, "client closed \n");
        }
        printf("received %d bytes\n", n);
        count++;

        switch (ntohl(message.type))
        { /* ntohl将无符号长整形数从网络字节顺序转换为主机字节顺序 */
            case MSG_TYPE1 :
                printf("process  MSG_TYPE1 \n");
                break;

            case MSG_TYPE2 :
                printf("process  MSG_TYPE2 \n");
                break;

            case MSG_PING:
            {
                /* 收到客户端发来的ping，就回传一个pong */
                messageObject pong_message;
                pong_message.type = MSG_PONG;
                sleep(sleepingTime);
                ssize_t rc = send(connfd, (char *) &pong_message, sizeof(pong_message), 0);
                if (rc < 0)
                    error(1, errno, "send failure");
                break;
            }

            default :
                error(1, 0, "unknown message type (%d)\n", ntohl(message.type));
        }


    }

}


