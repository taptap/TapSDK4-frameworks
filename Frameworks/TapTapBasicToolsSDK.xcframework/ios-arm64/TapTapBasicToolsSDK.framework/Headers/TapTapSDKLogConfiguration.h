//
//  TapSDKLogConfiguration.h
//  TapTapSDKBasicTools
//
//  Created by ^-^ on 2024/4/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TapTapSDKProjectType) {
    TapTapSDKUpdate,
    TapTapSDKAppDuration,
    TapTapSDKSDKCore,
    TapTapSDKLogin,
};

@interface TapTapSDKLogConfiguration : NSObject

/// 获取 log 埋点参数
/// - Parameter type: ProjectType
+ (NSMutableDictionary *)getParamsType:(TapTapSDKProjectType)type;


/// 获取公共基础埋点参数
+ (NSDictionary *)getCommonBaseParameters;
@end

NS_ASSUME_NONNULL_END
