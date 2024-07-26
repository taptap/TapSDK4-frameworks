//
//  TapDBIdTool.h
//  TapDB_iOS
//
//  Created by JiangJiahao on 2019/10/13.
//  Copyright © 2019 JiangJiahao. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKIDTool : NSObject

+ (NSString *)getIDFA;

+ (NSString *)getUniqueDeviceId;

+ (NSString *)getTapDBId;
/// 卸载会变
+ (NSString *)getInstallUUID;
+ (NSString *)getPersistUUID;

+ (NSString *)generateUUID;

+ (NSString *)getSessionUUID;

+ (long)getBootTimestamp;

+ (NSString *)getWebViewUA;

/// 获取device_id  （卸载不变）
+ (NSString *)getDeviceId;

+ (long long)getEventIndex;

/// 获取IDFA 授权状态 iOS 14 以下会直接返回通过授权
+ (void)requestTrackingAuthorizationWithCompletionHandler:(void(^)(NSUInteger status))completion;
@end

NS_ASSUME_NONNULL_END
