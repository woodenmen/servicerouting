#include <jni.h>
#include <string>
#include <dhcp_client.h>
#include <server_client.h>
#include <JniLog.h>





extern "C"
JNIEXPORT jint JNICALL
Java_com_example_httpclient_MainActivity_startServer(JNIEnv *env, jobject thiz) {
    int ret = -1;
    std::string resData;
    DhcpClient dhcpClient;
    ret = dhcpClient.getDataFromDhcpServer("req_dhcp_server", resData);
    if (ret < 0) {
        LOGE("从dhcp server获取数据失败");
        return -1;
    }
    // 解析resData 得到三宝
    std::string sr_prev = "temp1";
    std::string sr_hash = "temp2";
    std::string sr_ext_ip = "temp3";

    ServerClient serverClient(sr_prev, sr_hash, sr_ext_ip);
    serverClient.getHashListFromExt();
    return 0;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_httpclient_MainActivity_getHashRes(JNIEnv *env, jobject thiz, jstring url) {
    // TODO: implement getHashRes()
    return 0;
}