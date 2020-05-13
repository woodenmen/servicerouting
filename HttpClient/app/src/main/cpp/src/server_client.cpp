//
// Created by MSI1 on 2020/5/13.
//

#include <server_client.h>
#include <server_client.h>
#include <iostream>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <JniLog.h>

#define SERVER_PORT 7777

static int i4_client_fd;
static struct sockaddr_in client_addr;
static struct sockaddr_in server_addr;

ServerClient::ServerClient() {
    LOGD("ServerClient::ServerClient()");
}

ServerClient::ServerClient(std::string sr_prev, std::string sr_hash, std::string sr_ext_ip) {
    LOGD("ServerClient::ServerClient(str, str, str)");
    this->sr_prev = sr_prev;
    this->sr_hash = sr_hash;
    this->sr_ext_ip = sr_ext_ip;
}

ServerClient::~ServerClient() {
    LOGD("ServerClient::~ServerClient()");
}

void ServerClient::getHashListFromExt() {
    while(1) {
        int ret = -1;
        i4_client_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (i4_client_fd < 0) {
            LOGE("create client socket failed");
            sleep(2);
            continue;
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(SERVER_PORT);
        server_addr.sin_addr.s_addr = inet_addr("192.168.17.137");
        ret = connect(i4_client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (ret < 0) {
            LOGE("connect to server failed");
            close(i4_client_fd);
            sleep(2);
            continue;
        }
        std::string reqData = "req_dhcp_server_ext";
        send(i4_client_fd, reqData.c_str(), reqData.length(), 0);
        char recvbuf[1024] = {0};
        recv(i4_client_fd, recvbuf, sizeof(recvbuf), 0);
        std::string resData(recvbuf);
        // 更新本地hash冲突表数据库
        // todo
        close(i4_client_fd);
        sleep(10); // 每隔10s检测一次
    }
}

std::string ServerClient::getHashRes(std::string url) {
    return "";
}