//
// Created by Tseng Jianjun on 2021/6/18.
//

#ifndef NETWORK_CODING_MESSAGE_OBJECT_H
#define NETWORK_CODING_MESSAGE_OBJECT_H

typedef struct
{
    u_int32_t type;
    char data[1024];
} messageObject;

#define MSG_PING    1
#define MSG_PONG    2
#define MSG_TYPE1   11
#define MSG_TYPE2   21

#endif //NETWORK_CODING_MESSAGE_OBJECT_H

