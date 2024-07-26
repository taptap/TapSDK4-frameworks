//
//  TapTapSDKUtils.h
//  TapTapSDKBasicTools
//
//  Created by ^-^ on 2024/5/22.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKUtils : NSObject

/// 获取总磁盘容量
+ (long long)getTotalDiskSize;
/// 获取可用磁盘容量
+ (long long)getAvailableDiskSize;

+ (NSString *)getDeviceIdentifier;

+ (NSString *)getCpuArchitecture;

+ (int64_t)memoryUsage;

+ (NSString *)getAppBuildNumber;

+ (NSString *)getAppVersion;

//获取网络状态
+ (NSString *)getNetWorkStatus:(NSString *)hostName;

+ (NSString *)getNetworkType;

+ (int)getNetWorkType:(NSString *)hostName;


@end

NS_ASSUME_NONNULL_END
