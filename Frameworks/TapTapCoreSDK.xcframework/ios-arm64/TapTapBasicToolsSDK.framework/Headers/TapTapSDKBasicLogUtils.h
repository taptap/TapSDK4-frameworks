//
//  TapTapOpenlogUtils.h
//  TapTapCoreSDK
//
//  Created by SeraphLi on 2024/10/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NSString* _Nullable (^DynamicPropertiesDelegate)(void);

@interface TapTapSDKBasicLogUtils : NSObject

/// 应用启动
+ (BOOL) onAppStarted:(NSString *) appConfig dynamicPropertiesDelegate :(DynamicPropertiesDelegate) dynamicPropertiesDelegate;

/// 启用功能模块，如：app_duration
+ (void) enableModules:(NSArray<NSString*> *) modulesArray;

/// 禁用功能模块，如：app_duration
+ (void) disableModules:(NSArray<NSString*> *) modulesArray;

/// 发送业务日志，例如
// {
//  "action": "gid__http_successful",
//  "args": {}",
//  "tapsdk_project": "TapSDKCore",
//  "tapsdk_version": "4.3.8"
// }
///
/// - Parameter params: 埋点参数
///
+ (void) sendBusinessLog:(NSDictionary *) params;

/// 发送技术日志，只对海外生效
+ (void) sendTechnologyLog:(NSDictionary *) params;

/// 用户登录
/// - Parameter userInfo : JSON 格式：{"open_id":"","tds_user_id":""}
+ (void) onLogin:(NSString *) userInfo;

+ (void) onLogout;

+ (void) onBackground;

+ (void) onForeground;

/// 设置额外的时长模块日志参数，每次调用这个接口时，会用最新得到的参数，替换原有参数
+ (void) setExtraAppDurationParams:(NSDictionary *) params;

+ (void) setLogLevel: (int) logLevel logToConsole:(int) logToConsole;

/// 获取 openlog so 库版本号
+ (NSString *) getVersion;

/// 应用退出
+ (void) onAppStoped;



@end

NS_ASSUME_NONNULL_END
