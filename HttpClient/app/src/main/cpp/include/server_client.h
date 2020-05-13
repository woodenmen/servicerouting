//
// Created by MSI1 on 2020/5/13.
//

#ifndef HTTPCLIENT_SERVER_CLIENT_H
#define HTTPCLIENT_SERVER_CLIENT_H

#include <iostream>

class ServerClient {
public:
    ServerClient();
    ServerClient(std::string sr_prev, std::string sr_hash, std::string sr_ext_ip);
    ~ServerClient();
    void getHashListFromExt();
    std::string getHashRes(std::string url);
private:
    std::string sr_prev;
    std::string sr_hash;
    std::string sr_ext_ip;
};


#endif //HTTPCLIENT_SERVER_CLIENT_H
