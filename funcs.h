#ifndef FUNCS_H
#define FUNCS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <string>

using std::string;

int Check_Addr(string addr);
int Check_Port(int port);
void Listen(int sockfd, int backlog);
int Socket(int domain, int type, int protocol);
void Inet_pton(int af, const char *src, void *dst);
int Accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
void Bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
void Connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

#endif
