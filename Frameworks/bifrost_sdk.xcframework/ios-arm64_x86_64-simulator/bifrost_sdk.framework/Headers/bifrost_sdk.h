#ifndef BIFROST_SDK_SRC_BIFROST_SDK_H_
#define BIFROST_SDK_SRC_BIFROST_SDK_H_

#include "bifrost_common.h"

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef EXPORT_TDK_CPP
#define BIFROST_SDK_EXPORT_API __declspec(dllexport)
#else
#define BIFROST_SDK_EXPORT_API __declspec(dllimport)
#endif
#else
#ifdef EXPORT_TDK_CPP
#define BIFROST_SDK_EXPORT_API __attribute__((visibility("default")))
#else
#define BIFROST_SDK_EXPORT_API
#endif
#endif

///////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 初始化接口，只需要调用一次，且必须调用一次。非线程安全，并发调用可能导致崩溃。
 *
 * - jsonCfg JSON 格式的初始化参数
 *   {
 *     "log_dir": "/path/for/sdk/logging",
 *     "log_level": 3,
 *     "log_to_console": 1
 *   }
 *   - log_dir 保存日志文件的目录。
 *   - log_level 日志等级：1 trace、2 debug、3 info、4 warn、5 error、> 5 不打日志。建议调试时设为1，正式版设为3。
 *   - log_to_console 是否输出到控制台：0 不输出、1 输出。
 *
 * 成功返回 0，失败返回 -1
 */
BIFROST_SDK_EXPORT_API int TapSdkBifrostInitialize(const char* jsonCfg);

/**
 * 程序退出前调用一次，关闭连接、释放资源。非线程安全，并发调用可能导致崩溃。
 */
BIFROST_SDK_EXPORT_API void TapSdkBifrostFinalize();

/**
 * 设置日志等级
 *   - logLevel 日志等级：1 trace、2 debug、3 info、4 warn、5 error、> 5 不打日志。建议调试时设为1，正式版设为3。
 *   - logToConsole 是否输出到控制台：0 不输出、1 输出。
 */
BIFROST_SDK_EXPORT_API void TapSdkBifrostSetLogLevel(int logLevel, int logToConsole);

/**
 * 代码版本，如：1.2.5
 */
BIFROST_SDK_EXPORT_API const char* TapSdkBifrostVersion();

/**
 * git commit 版本，如：98f5d81a0fdcab9a755878b3e825c2cb510e5196
 */
BIFROST_SDK_EXPORT_API const char* TapSdkBifrostGitCommit();

/**
 * 异步执行订阅请求，完成后通过回调函数 subCB 通知调用方。订阅成功后，收到服务端下发消息时，会回调 msgCB。
 *
 * - jsonCfg 里面的字段通过 TapTap Gateway 短连接获取
 *   {
 *     "svc": "taptap.im",                       // 想要订阅的服务
 *     "url": "wss://bifrost.xdrnd.cn/taptap", // 长连接网关地址
 *     "jwt": "token"                            // 定义服务所需的 token
 *   }
 *
 * 返回：
 *   - 0  仅表示参数正确，不代表订阅成功，订阅状态通过回调函数 subCB 通知
 *   - -1 参数错误
 *   - -2 未初始化。尚未调用 TapSdkBifrostInitialize()，或者初始化失败，或者已经调用了 TapSdkBifrostFinalize()
 */
BIFROST_SDK_EXPORT_API int TapSdkBifrostSubscribeService(const char* jsonCfg, SubscribeCallback subCB, MessageCallback msgCB, RequestCallback reqCB);

/**
 * 异步执行退订请求，完成后通过 TapSdkBifrostSubscribeService() 注册的回调函数 subCB 通知调用方，且传递给 subCB 的 errCode 为 ERROR_UNSUBBED(6)。
 *
 * @param svc 想要退订的服务
 */
BIFROST_SDK_EXPORT_API void TapSdkBifrostUnsubscribeService(const char* svc);

/**
 * 异步发请求到指定的服务，请求结果通过 TapSdkBifrostSubscribeService() 注册的回调函数 reqCB 通知调用方。
 * 必须先调用 TapSdkBifrostSubscribeService() 订阅了相关的服务后，才能调用这个接口。
 *
 * @param reqID 请求方生成的唯一请求 ID，请求完成后，调用回调函数时会回传该 ID，用于对应到原始请求
 * @param svc 请求的服务
 * @param svcCmd 服务自定义协议号
 * @param data 服务自定义协议的序列化结果
 * @param dataLen data 的长度（字节）
 *
 * 返回：
 *   - 0  仅表示参数正确，不代表请求成功，请求结果通过回调函数 reqCB 返回
 *   - -1 参数错误
 *   - -2 未初始化。尚未调用 TapSdkBifrostInitialize()，或者初始化失败，或者已经调用了 TapSdkBifrostFinalize()
 */
BIFROST_SDK_EXPORT_API int TapSdkBifrostSendRequest(uint64_t reqID, const char* svc, uint32_t svcCmd, const void* data, uint32_t dataLen);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // BIFROST_SDK_SRC_BIFROST_SDK_H_