//
// Created by MSI1 on 2020/5/13.
//

#include <dhcp_client.h>
#include <iostream>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <JniLog.h>

#define SERVER_PORT 6666

static int i4_client_fd;
static struct sockaddr_in client_addr;
static struct sockaddr_in server_addr;

DhcpClient::DhcpClient() {
    LOGD("DhcpClient::DhcpClient()");
}

DhcpClient::~DhcpClient() {
    LOGD("DhcpClient::~DhcpClient()");
}

int DhcpClient::getDataFromDhcpServer(std::string reqData, std::string& resData) {
    int ret = -1;
    i4_client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (i4_client_fd < 0) {
        LOGE("create client socket failed");
        return -1;
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr("192.168.17.137");
    ret = connect(i4_client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        LOGE("connect to server failed");
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