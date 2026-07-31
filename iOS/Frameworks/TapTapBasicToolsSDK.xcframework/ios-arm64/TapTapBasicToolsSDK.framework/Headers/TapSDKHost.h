//
//  TapSDKHost.h
//  TapTapSDKBasicTools
//
//  Created by ^-^ on 2024/5/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapSDKHost : NSObject
+ (void)switchToRnd;
+ (NSString *)getGidHost;
+ (NSString *)getApiHost;
+ (NSString *)getThemisHost;
+ (NSString *)getEventHost;
/// 埋点 业务路径
+ (NSString *)getBizEventHost;
/// 埋点 技术路径
+ (NSString *)getApmEventHost;
@end

NS_ASSUME_NONNULL_END
