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

+ (void)print:(NSString *)log;

+ (void)print:(NSString *)log level:(TapTapSDKLogLevel)level;

@end

NS_ASSUME_NONNULL_END
