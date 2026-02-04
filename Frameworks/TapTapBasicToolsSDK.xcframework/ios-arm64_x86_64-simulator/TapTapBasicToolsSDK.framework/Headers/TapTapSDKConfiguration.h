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

/// caid
@property (nonatomic, strong) NSString *caid;

/// 用户ID
@property (nonatomic, strong, nullable) NSString *userID;

/// 地区，0 为国内，1为海外, 默认为 0
@property (nonatomic, assign) NSInteger region;

/// 是否采集广告 ID 默认 false
@property (nonatomic, assign) BOOL isAdvertiserIDCollectionEnabled;

/// 日志开关
@property (nonatomic, assign) BOOL enableLog;

/*
 SDK 产物（开发平台或语言）
 Android,iOS,Unity,UE4,UE5,CPP
 */
@property (nonatomic, strong) NSString *artifact;

/// 屏幕方向  0 竖屏 1 横屏
@property (nonatomic, assign) NSInteger screenOrientation;

/// 主题， 0 浅色 1 深色
@property (nonatomic, assign) NSInteger uiTheme;

+ (instancetype)shareInstance;

- (void)startFetchDeviceId;

/// 判断当前是否为深色主题
/// @return YES 为深色主题，NO 为浅色主题
- (BOOL)isDarkTheme;

@end

NS_ASSUME_NONNULL_END
