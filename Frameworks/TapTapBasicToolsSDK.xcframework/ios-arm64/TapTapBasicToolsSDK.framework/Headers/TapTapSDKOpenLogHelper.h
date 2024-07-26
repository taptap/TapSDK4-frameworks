//
//  TapOpenLogHelper.h
//  TapTapSDKCore
//
//  Created by ^-^ on 2024/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKOpenLogHelper : NSObject
/// 业务埋点 （上报 tapsdk表）
/// - Parameters:
///   - action: 埋点事件
///   - properties: 埋点参数
+ (void)reportBusinessLog:(NSString *)action properties:(nullable NSDictionary *)properties;

/// 技术埋点 （上报 tapsdk-apm 表）
/// - Parameters:
///   - action: 埋点事件
///   - properties: 埋点参数
+ (void)reportTechnicalLog:(NSString *)action properties:(nullable NSDictionary *)properties;
@end

NS_ASSUME_NONNULL_END
