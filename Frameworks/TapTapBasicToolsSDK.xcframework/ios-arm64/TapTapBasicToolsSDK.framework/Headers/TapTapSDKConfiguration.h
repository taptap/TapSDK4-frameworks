//
//  TapSDKConfiguration.h
//  TapTapSDK
//
//  Created by ^-^ on 2024/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKConfiguration : NSObject
/// 唯一ID
@property (nonatomic, strong, nullable) NSString *gid;

/// IDFA
@property (nonatomic, strong, nullable) NSString *idfa;

/// 登陆ID
@property (nonatomic, strong, nullable) NSString *openID;

/// ID
@property (nonatomic, strong) NSString *clientID;

/// Token
@property (nonatomic, strong) NSString *clientToken;

/// 配置渠道
@property (nonatomic, strong) NSString *channel;

/// caid
@property (nonatomic, strong) NSString *caid;

/// 用户ID
@property (nonatomic, strong, nullable) NSString *userID;

/// 地区，0 为国内，1为海外, 默认为 0
@property (nonatomic, assign) NSInteger region;

/// 是否采集广告 ID 默认 false
@property (nonatomic, assign) BOOL isAdvertiserIDCollectionEnabled;

/// 是否启用自动记录 App Store/Google play 内购事件 默认 true
@property (nonatomic, assign) BOOL isIAPEventEnabled;

/*
 SDK 产物（开发平台或语言）
 Android,iOS,Unity,UE4,UE5,CPP
 */
@property (nonatomic, strong) NSString *artifact;

+ (instancetype)shareInstance;

@end

NS_ASSUME_NONNULL_END
