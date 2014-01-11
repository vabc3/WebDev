#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#ifdef WIN32
#else
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#endif

int main()
{
    printf("Starting\n");

    int sd;
    unsigned int addrlen;
    struct sockaddr_in sin;
    struct sockaddr_in pin;

    if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        perror("socket error");
        exit(1);
    }
    int optval=1;
    setsockopt(sd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    memset(&sin, 0, sizeof(sin));
    sin.sin_family  = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(9000);

    if (bind(sd, (struct sockaddr *)&sin, sizeof(sin))==-1) {
        perror("bind failed");
        exit(2);
    }

    if (listen(sd,5)==-1){
        perror("listen");
        exit(4);
    }

    addrlen = sizeof(pin);
    int cur;
    if((cur = accept(sd, (struct sockaddr *)&pin,&addrlen))==-1){
        perror("accept");
        exit(1);
    }

    printf("Incoming %s:%d\n",inet_ntoa(pin.sin_addr),ntohs(pin.sin_port));

    char data[8192];

    if (recv(cur, data, sizeof(data), 0) == -1){
        perror("recv");
        exit(5);
    }

    printf("%s\n",data);

    strcpy(data,"fdsjl\n");
    if(send(cur,data,strlen(data),0)==-1){
        perror("send");
        exit(6);
    }

    close(cur);
    close(sd);

    return 0;
}
