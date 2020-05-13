//
// Created by MSI1 on 2020/5/13.
//

#ifndef HTTPCLIENT_DHCP_CLIENT_H
#define HTTPCLIENT_DHCP_CLIENT_H

#include <iostream>

class DhcpClient {
public:
    DhcpClient();
    ~DhcpClient();
    int getDataFromDhcpServer(std::string reqData, std::string& resData);
};


#endif //HTTPCLIENT_DHCP_CLIENT_H
