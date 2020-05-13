#include <dhcp_server_ext.h>
#include <iostream>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>

#define SERVER_PORT 7777

int i4_server_fd;
int i4_client_fd;
struct sockaddr_in server_addr;
struct sockaddr_in client_addr;

DhcpServerExt::DhcpServerExt() {
    std::cout << "DhcpServerExt::DhcpServerExt()" << std::endl;
}

DhcpServerExt::~DhcpServerExt() {
    std::cout << "DhcpServerExt::~DhcpServerExt()" << std::endl;
}

void DhcpServerExt::handleReq(int connfd) {
    char buf[1024] = {0};
    recv(connfd, buf, 1024, 0);
    std::cout << "get data = " << buf << std::endl;
    std::string res = "send you dhcp server ext data";
    std::cout << "send data = " << res << std::endl;
    send(connfd, res.c_str(), res.length(), 0);
}

int DhcpServerExt::createIpv6Socket() {
    int ret;
    i4_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (i4_server_fd < 0) {
        perror("create server socket failed");
        return -1;
    }
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    ret = bind(i4_server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        perror("bind failed");
        return -1;
    }
    ret = listen(i4_server_fd, 10);
    if (ret < 0) {
        perror("listen failed");
        return -1;
    }
    std::cout << "start to listen: port(" << SERVER_PORT << ")" << std::endl;
    while(1) {
        int addr_len = sizeof(client_addr);
        i4_client_fd = accept(i4_server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len);
        if (i4_client_fd < 0) {
            perror("accept failed");
            continue;
        }
        std::cout << "IP is " << inet_ntoa(client_addr.sin_addr) << std::endl;
        std::cout << "PORT is " << htons(client_addr.sin_port) << std::endl;

        //accrding to the type to handle different req
        std::thread t(handleReq, i4_client_fd);
        t.detach();
    }
    return 0;
}

int DhcpServerExt::closeIpv6Socket() {
    return 0;
}

int main(int argc, char* argv[]) {
    DhcpServerExt dse;
    dse.createIpv6Socket();
    dse.closeIpv6Socket();
    return 0;
}


