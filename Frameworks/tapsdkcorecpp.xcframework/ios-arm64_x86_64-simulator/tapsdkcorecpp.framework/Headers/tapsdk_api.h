#ifndef TAP_SDK_CORE_SRC_TDS_SDK_API_H_
#define TAP_SDK_CORE_SRC_TDS_SDK_API_H_

#ifdef _MSC_VER
#define TDSSDK_EXPORT_API __declspec(dllexport)
#else
#define TDSSDK_EXPORT_API
#endif

///////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
extern "C" {
#endif

/**
 * 初始化接口，只需要调用一次。
 *
 *   cfg 初始化配置，JSON 格式：{"region":2,"log_to_console":1,"log_level":1,"data_dir":"/tmp","env":"local","tapsdk_artifact":"Unity","tapsdk_version":"4.2.0","platform":"PC","ua":"TapSDK-Android/3.28.0","client_id":"uZ8Yy6cSXVOR6AMRPj","client_token":"AVhR1Bu9qfLR1cGbZMAdZ5rzJSxfoEiQaFf1T2P7","common":{"pn":"TapSDK","app_version_code":"123","app_version":"1.2.3","app_package_name":"","install_uuid":"","device_id":"123456","android_id":"","caid":"","dv":"","md":"","hardware":"","cpu":"","cpu_abis":"","network_type":"","mobile_type":"","os":"android","sv":"","width":"","height":"","timezone":"","rom":"","ram":"","sdk_locale":"","open_id":"","tds_user_id":""}}
 *     - log_level 取值：1 Trace、2 Debug、3 Info、4 Warn、5 Error、6 完全不输出
 *     - region 取值：0 国内、1 海外、2 RND
 *
 * 成功返回 0，失败返回 -1
 */
TDSSDK_EXPORT_API int TdkOnAppStarted(const char* cfg);

/**
 * App 退出时调用，只需要调用一次。
 */
TDSSDK_EXPORT_API void TdkOnAppStopped();

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
 * 游戏切回前台时调用。
 */
TDSSDK_EXPORT_API void TdkOnForeground();

/**
 * 用户切到后台时调用。
 */
TDSSDK_EXPORT_API void TdkOnBackground();

/**
 * 更新 TdkOnAppStarted 传进来的配置
 *
 *   {
 *     "common": {
 *       "sdk_locale": "new_locale"
 *     }
 *   }
 */
TDSSDK_EXPORT_API void TdkUpdateConfig(const char* json);

/**
 * 设置额外的日志参数，JSON K/V 格式，如果 V 为 ""，表示删除某个日志参数
 *
 *   params 额外日志参数，JSON 格式：{"K1":"V1","K2":"V2","K3":"V3"}
 */
TDSSDK_EXPORT_API void TdkSetExtraParams(const char* params);

/**
 * 代码版本
 */
TDSSDK_EXPORT_API const char* TdkVersion();

/**
 * git commit版本
 */
TDSSDK_EXPORT_API const char* TdkGitCommit();

#ifdef __cplusplus
} // extern "C"
#endif

#endif // TAP_SDK_CORE_SRC_TDS_SDK_API_H_