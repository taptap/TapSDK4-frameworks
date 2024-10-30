﻿#ifndef TAP_SDK_CORE_SRC_TDS_SDK_API_H_
#define TAP_SDK_CORE_SRC_TDS_SDK_API_H_

#include "common.h"

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef EXPORT_TDK_CPP
#define TDSSDK_EXPORT_API __declspec(dllexport)
#else
#define TDSSDK_EXPORT_API __declspec(dllimport)
#endif
#else
#ifdef EXPORT_TDK_CPP
#define TDSSDK_EXPORT_API __attribute__((visibility("default")))
#else
#define TDSSDK_EXPORT_API
#endif
#endif

///////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 初始化接口，只需要调用一次。
 *
 *   cfg 初始化配置，JSON 格式：
 *
 *   {
 *       "region": 2,
 *       "log_to_console": 1,
 *       "log_level": 1,
 *       "data_dir": "/tmp",
 *       "env": "local",
 *       "tapsdk_artifact": "Unity",
 *       "tapsdk_version": "4.2.0",
 *       "platform": "PC",
 *       "ua": "TapSDK-Android/3.28.0",
 *       "client_id": "uZ8Yy6cSXVOR6AMRPj",
 *       "client_token": "AVhR1Bu9qfLR1cGbZMAdZ5rzJSxfoEiQaFf1T2P7",
 *       "modules": ["app_duration"],
 *       "common": {
 *           "pn": "TapSDK",
 *           "app_version_code": "123",
 *           "app_version": "1.2.3",
 *           "app_package_name": "",
 *           "install_uuid": "",
 *           "device_id": "123456",
 *           "android_id": "",
 *           "caid": "",
 *           "dv": "",
 *           "md": "",
 *           "hardware": "",
 *           "cpu": "",
 *           "cpu_abis": "",
 *           "network_type": "",
 *           "mobile_type": "",
 *           "os": "android",
 *           "sv": "",
 *           "width": "",
 *           "height": "",
 *           "timezone": "",
 *           "rom": "",
 *           "ram": "",
 *           "sdk_locale": "",
 *           "open_id": "",
 *           "tds_user_id": ""
 *       }
 *   }
 *
 *   - log_level 取值：1 Trace、2 Debug、3 Info、4 Warn、5 Error、6 完全不输出
 *   - region 取值：0 国内、1 海外、2 RND
 *   - modules 取值：app_duration（开启时长埋点）。如果 modules 不传，或者为空，
 *                  则仅开启 OpenLog 功能，不会上报游戏时长
 *
 *  commonVariablesGetter 用于获取运行时会发生变化的公参
 *
 * 成功返回 0，失败返回 -1
 */
TDSSDK_EXPORT_API int TdkOnAppStarted(const char* cfg, CommonVariablesGetter commonVariablesGetter, MemoryDeallocator deallocator);

/**
 * App 退出时调用，只需要调用一次。
 */
TDSSDK_EXPORT_API void TdkOnAppStopped();

/**
 * 启用功能模块，如：app_duration
 *
 *   modules JSON 数组，如：["app_duration"]
 *
 */
TDSSDK_EXPORT_API void TdkEnableModules(const char* modules);

/**
 * 禁用功能模块，如：app_duration
 *
 *   modules JSON 数组，如：["app_duration"]
 *
 */
TDSSDK_EXPORT_API void TdkDisableModules(const char* modules);

/**
 * 需要发送埋点日志时调用。
 * SDK 内部会整合初始化接口传入的公参、extraArgsFunc 返回的公参，以及 log 里的业务参数，
 * 然后再发送到 OpenLog 服务端
 *
 *   logStore 如：tapsdk、tapsdk-apm
 *   logContent 业务埋点日志，仅需传递业务参数，JSON 格式：{"action":"xxx","open_id":"yyy","tds_user_id":"zzz"}
 */
TDSSDK_EXPORT_API void TdkOpenLog(const char* logStore, const char* logContent);

/**
 * 用户登录成功时调用。
 *
 *   userInfo 用户信息，JSON 格式：{"open_id":"","tds_user_id":""}
 */
TDSSDK_EXPORT_API void TdkOnLogin(const char* userInfo);

/**
 * 用户登出时调用。
 */
TDSSDK_EXPORT_API void TdkOnLogout();

/**
 * 应用切回前台时调用。
 */
TDSSDK_EXPORT_API void TdkOnForeground();

/**
 * 应用切到后台时调用。
 */
TDSSDK_EXPORT_API void TdkOnBackground();

/**
 * 设置额外的时长模块日志参数，JSON K/V 格式。每次调用这个接口时，会用最新得到的参数，替换原有参数。
 *
 *   params 额外日志参数，JSON 格式：{"K1":"V1","K2":"V2","K3":"V3"}
 */
TDSSDK_EXPORT_API void TdkSetExtraAppDurationParams(const char* params);

/**
 * 设置日志等级
 */
TDSSDK_EXPORT_API void TdkSetLogLevel(int logLevel, int logToConsole);

/**
 * 代码版本，如：1.2.5
 */
TDSSDK_EXPORT_API const char* TdkVersion();

/**
 * git commit 版本，如：98f5d81a0fdcab9a755878b3e825c2cb510e5196
 */
TDSSDK_EXPORT_API const char* TdkGitCommit();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TAP_SDK_CORE_SRC_TDS_SDK_API_H_