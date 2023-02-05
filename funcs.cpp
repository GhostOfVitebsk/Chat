#include "funcs.h"
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>

using std::string;

int Check_Addr(string addr){
    int temp = 0;
    for (unsigned int i = 0; i < addr.size(); i++){
        if (addr[i] == ':'){
            temp = 2;
            break;
        }
        else if (addr[i] == '.') {
            temp = 1;
            break;
        }
    }
    if (temp == 1 && addr.size() >= 7 && addr.size() <= 15){
        return 1;
    }
    else if (temp == 2 && addr.size() == 39){
        return 2;
    } 
    return 0;
}

int Check_Port(int port){
    if (port > 0 && port <= 65000){
        return port;
    }
    return 0;
}

int Socket(int domain, int type, int protocol){
    int res = socket(domain, type, protocol);
    if (res == -1){
        perror("socket error");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int res = bind(sockfd, addr, addrlen);
    if (res == -1){
        perror("bind error");
        exit(EXIT_FAILURE);
    }
}

void Listen(int sockfd, int backlog){
    int res = listen(sockfd, backlog);
    if
 (res == -1){
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
}

int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen){
    int res = accept(sockfd, addr, addrlen);
    if (res == -1){
        perror("accept failed");
        exit(EXIT_FAILURE);
    }
    return res;
}

void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen){
    int res = connect(sockfd, addr, addrlen);
    if (res == -1){
        perror("connecting failed");
        exit(EXIT_FAILURE);
    }
}

void Inet_pton(int af, const char *src, void *dst){
    int res = inet_pton(af, src, dst);
    if (res == 0) {
        printf("src not valid\n");
        exit(EXIT_FAILURE);
    }
    if (res == -1) {
        perror("inet_pton failed");
        exit(EXIT_FAILURE);
    }
    
}

