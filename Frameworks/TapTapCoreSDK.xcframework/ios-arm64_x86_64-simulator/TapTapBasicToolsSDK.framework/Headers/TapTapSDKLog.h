//
//  TapSDKLog.h
//  TapTapSDK
//
//  Created by ^-^ on 2024/4/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TapTapSDKLogLevel) {
    TapTapSDKLogLevelDebug,
    TapTapSDKLogLevelInfo,
    TapTapSDKLogLevelWarn,
    TapTapSDKLogLevelError
};

@interface TapTapSDKLog : NSObject

+ (void)enableLog:(BOOL)enable;

/**
 输出 Debug 日志，该日志只在 xcode 调试时输出，在 Console 中不显示
 */
+ (void)print:(NSString *)log;

/**
 输出 Info 日志，在 Xcode 调试和 Console 中均显示
 */
+ (void)printInfo:(NSString *)log;

+ (void)print:(NSString *)log level:(TapTapSDKLogLevel)level;

@end

NS_ASSUME_NONNULL_END
