//
//  TapTapSDK.h
//  TapTapSDK
//
//  Created by ^-^ on 2024/3/25.
//

#import <Foundation/Foundation.h>
#import <TapTapBasicToolsSDK/TapTapSDKLocalize.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TapTapRegionType) {
    TapTapRegionTypeCN = 0, // 国内
    TapTapRegionTypeOverseas = 1  // 海外
};

@protocol TapTapSDKBaseOptions <NSObject>

@property (nonatomic, copy, readonly, nonnull) NSString *moduleName;

@end

@interface TapTapSDKCoreOptions: NSObject <TapTapSDKBaseOptions>

@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, copy) NSString *clientToken;

@property (nonatomic, assign) TapTapRegionType region;
/// 设置当前app 语言
@property (nonatomic, assign) TapLanguageType preferredLanguage;

/// 分包渠道名称
@property (nonatomic, strong, nullable) NSString *channel;
/// 游戏版本（默认会读取主包 info.plist 中的版本号）
@property (nonatomic, strong, nullable) NSString *gameVersion;
/// 自定义属性，启动首个预置事件（device_login）会带上这些属性
@property (nonatomic, strong, nullable) NSDictionary *properties;

@property (nonatomic, strong, nullable) NSString *caid;

/// 自定义字段是否能覆盖内置字段
@property (nonatomic, assign) BOOL overrideBuiltInParameters;

/// 是否可以获取 IDFA，默认值为 false
@property(nonatomic, assign) BOOL enableAdvertiserIDCollection;

/// 是否自动上报苹果内购支付成功事件
@property(nonatomic, assign) BOOL enableAutoIAPEvent;

/// 是否开启 log，建议 Debug 开启，Release 关闭，默认关闭 log
@property (nonatomic, assign) BOOL enableLog;
@end


@interface TapTapSDK : NSObject

/// 当前 SDK 版本号
+ (NSString *)version;

/// 初始化
/// - Parameter coreOption: 核心库配置
/// - Parameter otherOptions: 其他库配置
+ (void)initWithOptions:(TapTapSDKCoreOptions *)coreOption otherOptions:(NSArray<id<TapTapSDKBaseOptions>> * _Nullable)otherOptions;

/// 初始化
/// - Parameter coreOption: 核心库配置
+ (void)initWithOptions:(TapTapSDKCoreOptions *)coreOption;


/// 切换语言
/// - Parameter language: 要切换的语言
+ (void)updateLanguage:(TapLanguageType)language;

@end

NS_ASSUME_NONNULL_END