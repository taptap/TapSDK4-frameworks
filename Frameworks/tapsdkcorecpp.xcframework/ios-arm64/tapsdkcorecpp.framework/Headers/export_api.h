#pragma once

#include <stdint.h>

#if defined(_WIN32) || defined(__CYGWIN__)
#ifdef EXPORT_TDK_CPP
#define TAPSDK_EXPORT_API __declspec(dllexport)
#elif defined(TAPSDK_SHARED_LIB)
#define TAPSDK_EXPORT_API __declspec(dllimport)
#else
#define TAPSDK_EXPORT_API
#endif
#else
#ifdef EXPORT_TDK_CPP
#define TAPSDK_EXPORT_API __attribute__((visibility("default")))
#else
#define TAPSDK_EXPORT_API
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*TapSdkCppLogWriter)(int32_t logLevel, const char* codeLocation, const char* logTag, const char* logMessage);

/**
 * 设置日志等级
 *   - logLevel 日志等级：1 trace、2 debug、3 info、4 warn、5 error、> 5 不打日志。建议调试时设为1，正式版设为3。
 */
TAPSDK_EXPORT_API void TapSdkCppInitLogger(int32_t logLevel, TapSdkCppLogWriter logWriter);

/**
 * 设置日志等级
 *   - logLevel 日志等级：1 trace、2 debug、3 info、4 warn、5 error、> 5 不打日志。建议调试时设为1，正式版设为3。
 */
TAPSDK_EXPORT_API void TapSdkCppSetLogLevel(int32_t logLevel);

#ifdef __cplusplus
}
#endif