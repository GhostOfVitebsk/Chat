#include "funcs.h"
#include <string>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
//#include "wx/wx.h"

#define MAX_USERS 2

using namespace std; 

struct client{
    struct sockaddr_in ClientInfo;
    char* Username;
    unsigned int ClientInfo_size = sizeof(ClientInfo);
};

void Server(int port);

int main(){
    string address;
    int port;
    cout << "Enter IPv4 or IPv6 address: ";
    cin >> address;
    cout << "Enter port: ";
    cin >> port;
    if (Check_Port(port)){
        if (Check_Addr(address) == 1){
            cout << "IPv4" << endl;
            Server(port);
        }
        else if (Check_Addr(address) == 2){
            cout << "IPv6" << endl;
        }
        else {
            cout << "Wrong IP_address! " << endl;
            exit(EXIT_FAILURE);
        }
    }
    else {
        cout << "Wrong port! " << endl;
        exit(EXIT_FAILURE);   
    }
}


void Server(int port){
    int listener;
    int sock[2];
    int count = 0;
    struct sockaddr_in addr;
    char buf1[1024];
    char buf2[1024];
    int br, br1;
    client clients[MAX_USERS];
    listener = Socket(AF_INET, SOCK_STREAM, 0);
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    Bind(listener, (struct sockaddr *)&addr, sizeof(addr));
    Listen(listener, 1);
    while(count < 2){
        sock[count] = Accept(listener, (sockaddr*)&clients[count].ClientInfo, &clients[count].ClientInfo_size);    
        cout << clients[count].ClientInfo.sin_port << endl;        
        count++;
    }
    while(1){
        br = recv(sock[0], buf1, 1024, 0);
        br1 = recv(sock[1], buf2, 1024, 0);
        send(sock[1], buf1, br, 0);  
        send(sock[0], buf2, br1, 0);
    }
        //close(listener);
}
