//
// Created by Tseng Jianjun on 2021/6/16.
//
#include "../lib/common.h"

# define MESSAGE_SIZE 1024000

void send_data(int sockfd)
{
    char *query;
    query = malloc(MESSAGE_SIZE + 1);
    for (int i = 0; i < MESSAGE_SIZE; i++)
    {
        query[i] = 'a';
    }
    query[MESSAGE_SIZE] = '\0';
    const char *cp;
    cp = query;
    /* remaining 是还要发送的数据长度*/
    size_t remaining = strlen(query);
    while (remaining)
    {
        /* 向sockfd发送数据，cp是缓冲区 */
        int n_written = send(sockfd, cp, remaining, 0);
        fprintf(stdout, "send into buffer %d \n", n_written);
        if (n_written <= 0)
        {
            error(1, errno, "send failed");
            return;
        }
        remaining -= n_written;
        cp += n_written;
    }
    return;
}

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    if (argc != 2)
    {
        error(1, 0, "usage: tcpclient <IPaddress>");
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(12345);
    /* inet_pton转换由argv[1]指针所指的字符串，并通过&servaddr.sin_addr指针存放二进制结果*/
    /* 还有个参数是inet_nton，与此正好相反，从数值格式转换成表达式 */
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
    int connect_rt = connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (connect_rt < 0)
    {
        error(1, errno, "connect failed ");
    }
    send_data(sockfd);
    exit(0);

}

