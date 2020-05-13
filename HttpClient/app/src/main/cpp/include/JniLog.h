//
// Created by MSI1 on 2020/5/13.
//

#ifndef HTTPCLIENT_JNILOG_H
#define HTTPCLIENT_JNILOG_H

#include <android/log.h>

#define TAG "MyJniLog"

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG , __VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG , __VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG , __VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG , __VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL, TAG , __VA_ARGS__) // 定义LOGF类型

#endif //HTTPCLIENT_JNILOG_H
