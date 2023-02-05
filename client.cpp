#include <thread>
#include "funcs.h"
#include <string>
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
//#include "wx/wx.h"

using namespace std; 


void Client(int port);


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
            Client(port);
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

void Client(int port){
    char mes[10] = "semen";
    char buf[1024];
    char buff[1024];
    int sock;
    struct sockaddr_in addr;
    sock = Socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    while(1){
        recv(sock, buff, 100, 0);
        cin.getline(buf, 255);
        send(sock, buf, sizeof(buf), 0);
        cout << buff[0] << endl;
    }
    close(sock);
}
