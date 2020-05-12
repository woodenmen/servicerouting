#ifndef __DHCP_SERVER_EXT_H_
#define __DHCP_SERVER_EXT_H_

class DhcpServerExt {
public:
    DhcpServerExt();
    ~DhcpServerExt();
    int createIpv6Socket();
    int closeIpv6Socket();
private:
    static void handleReq(int connfd);
};

#endif