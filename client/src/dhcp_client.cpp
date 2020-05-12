#include <dhcp_client.h>
#include <iostream>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <string.h>

#define SERVER_PORT 6666

int i4_client_fd;
struct sockaddr_in client_addr;
struct sockaddr_in server_addr;

DhcpClient::DhcpClient() {
    std::cout << "DhcpClient::DhcpClient()" << std::endl;
}

DhcpClient::~DhcpClient() {
    std::cout << "DhcpClient::~DhcpClient()" << std::endl;
}

int main(int argc, char* argv[]) {
    int ret;
    i4_client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (i4_client_fd < 0) {
        perror("create client socket failed");
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    ret = connect(i4_client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("connect to server failed");
        return -1;
    }
    char sendbuf[1024] = {0};
    strcpy(sendbuf, "hehehehehe");
    send(i4_client_fd, sendbuf, strlen(sendbuf), 0);
    char recvbuf[1024] = {0};
    recv(i4_client_fd, recvbuf, sizeof(recvbuf), 0);
    std::cout << "res = " << std::string(recvbuf) << std::endl;
    return 0;
}


