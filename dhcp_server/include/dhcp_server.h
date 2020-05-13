#ifndef __DHCP_SERVER_H_
#define __DHCP_SERVER_H_

class DhcpServer {
public:
    DhcpServer();
    ~DhcpServer();
    int createIpv6Socket();
    int closeIpv6Socket();
private:
    static void handleReq(int connfd);
};

#endif