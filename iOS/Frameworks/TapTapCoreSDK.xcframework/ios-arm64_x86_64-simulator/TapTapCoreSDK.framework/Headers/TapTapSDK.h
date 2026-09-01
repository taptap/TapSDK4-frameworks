//
//  TapTapSDK.h
//  TapTapSDK
//
//  Created by ^-^ on 2024/3/25.
//

#import <Foundation/Foundation.h>
#import <TapTapBasicToolsSDK/TapTapSDKLocalize.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TapTapSDKInitState){
    INIT_STATE_SUCCESS = 0,
    INIT_STATE_EMPTY = -1,
    INIT_STATE_INVALID = -2
};

/// SDK 初始化失败的跨平台对齐错误码
typedef NS_ENUM(NSInteger, TapInitErrorCode) {
    /// initWithOptions: 调用时参数本身非法（如 clientId/clientToken 为空、URLSchemes 冲突）
    TapInitErrorCodeParamError = 1000,
    /// gatekeeper 返回 invalid_client：应用 bundleId 与 clientId/clientToken 不匹配
    TapInitErrorCodeConfigError = 1001,
    /// 保留的网络错误码。当前 gatekeeper 超时/DNS/TLS/5xx 等会降级为 Success
    ///（沿用磁盘缓存或默认配置），不会通过 onInitFail 抛出此码。
    TapInitErrorCodeNetworkError = 1002,
    /// initWithOptions: 参数校验通过之后的同步初始化步骤（mediator 事件、appStart、
    /// completeInit、otherOptions 分发到其它模块等）自身抛出异常，不是参数校验失败。
    /// 之前这些步骤没有异常兜底，任一模块抛出异常会让方法提前退出、状态机永久停留在
    /// InProgress，也不会触发任何回调；改成对齐 Android/Unity 已有的 INTERNAL_ERROR
    /// 语义（Codex 审查发现：跨平台契约要求所有初始化路径最终都要产生一个终态）。
    TapInitErrorCodeInternalError = 1003
};

/// SDK 初始化结果回调。可以在 initWithOptions: 之前或之后的任意时机注册；
/// 若注册时状态机已经到达终态，会尽快在主线程异步回调一次（并非同步，调用返回后结果不一定已经可用）。对同一个 callback 重复调用
/// addInitCallback: 不会重复加入注册表，但只要当前仍是终态，每次调用仍会重新补发一次
/// 终态回调；如果不希望重复收到通知，请只在真正需要注册时调用一次。
///
/// 注意：内部注册表对已注册的 callback 持有强引用，不会自动释放；不再需要时请务必调用
/// removeInitCallback: 手动注销，否则会造成该回调持有的对象无法释放（内存泄漏）。
@protocol TapInitCallback <NSObject>

/// 本次会话初始化到达成功终态（含 gatekeeper 网络失败后的缓存降级）
- (void)onInitSuccess;

/// 初始化失败，errorCode 取值见 TapInitErrorCode
- (void)onInitFail:(NSInteger)errorCode errorMsg:(NSString *)errorMsg;

@end

typedef NS_ENUM(NSInteger, TapTapRegionType) {
    TapTapRegionTypeCN = 0, // 国内
    TapTapRegionTypeOverseas = 1  // 海外
};

typedef NS_ENUM(NSInteger, TapTapScreenOrientation) {
    TapTapScreenOrientationPortrait = 0, // 竖屏
    TapTapScreenOrientationLandscape = 1  // 横屏
};

typedef NS_ENUM(NSInteger, TapTapUITheme) {
    TapTapUIThemeLight = 0, // 正常主题
    TapTapUIThemeDark = 1  // 深色主题
};

@protocol TapTapSdkBaseOptions <NSObject>

@property (nonatomic, copy, readonly, nonnull) NSString *moduleName;

@end

@interface TapTapSdkOptions: NSObject <TapTapSdkBaseOptions>

@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, copy) NSString *clientToken;

@property (nonatomic, assign) TapTapRegionType region;
/// 设置当前app 语言
@property (nonatomic, assign) TapLanguageType preferredLanguage;

/// 游戏版本（默认会读取主包 info.plist 中的版本号）
@property (nonatomic, strong, nullable) NSString *gameVersion;

/// 是否开启 log，建议 Debug 开启，Release 关闭，默认关闭 log
@property (nonatomic, assign) BOOL enableLog;

@property (nonatomic, assign) TapTapScreenOrientation screenOrientation;

@property (nonatomic, assign) TapTapUITheme uiTheme;
@end

@interface TapTapEventOptions: NSObject <TapTapSdkBaseOptions>

@property (nonatomic, assign) BOOL enableTapTapEvent;

/// 分包渠道名称
@property (nonatomic, strong, nullable) NSString *channel;

/// 自定义属性，启动首个预置事件（device_login）会带上这些属性
@property (nonatomic, strong, nullable) NSDictionary *properties;

/// 自定义字段是否能覆盖内置字段
@property (nonatomic, assign) BOOL overrideBuiltInParameters;

/// 是否自动上报苹果内购支付成功事件
@property(nonatomic, assign) BOOL enableAutoIAPEvent;

@property (nonatomic, strong, nullable) NSString *caid;

/// 是否可以获取 IDFA，默认值为 false
@property(nonatomic, assign) BOOL enableAdvertiserIDCollection;

@end


@interface TapTapSDK : NSObject

/// 当前 SDK 版本号
+ (NSString *)version;

/// 注册初始化结果回调
+ (void)addInitCallback:(id<TapInitCallback>)callback NS_SWIFT_NAME(addInitCallback(_:));

/// 注销初始化结果回调。注意：内部会在真正派发前再检查一次该 callback 是否仍在注册表中，
/// 因此注销通常能取消掉已经排队但尚未真正执行的通知；但如果注销恰好发生在"检查通过之后、
/// 真正调用之前"的极窄区间内，仍可能收到一次通知，这一点无法完全杜绝。
+ (void)removeInitCallback:(id<TapInitCallback>)callback NS_SWIFT_NAME(removeInitCallback(_:));

/// 初始化。必须在主线程调用，且不支持从多个线程并发调用——对 isInit 的检查与后续状态
/// 更新不在同一个原子操作内，并发调用可能同时通过检查，发起多次 gatekeeper 请求。
///
/// 重复调用（无论上一次是终态还是仍处于 InProgress）都会用这次传入的
/// coreOption/otherOptions 重新校验参数、重新写入配置，并推进到新的一次会话重新
/// 发起真正的 gatekeeper 网络请求——不会因为上一次是 Success、ConfigError 甚至
/// InProgress 就直接照搬旧结果或整体忽略本次调用，这样重复调用才能感知这次传入的
/// 修正后的配置（或反过来，感知这次传入的错误配置）。只有 appStart/completeInit 等
/// 只该发生一次的副作用不会重复执行。上一次调用如果仍在进行中，其网络结果到达时会
/// 因为会话号已过期被丢弃，已注册的回调只会收到本次调用最终产生的结果。
/// - Parameter coreOption: 核心库配置
/// - Parameter otherOptions: 其他库配置
+ (void)initWithOptions:(TapTapSdkOptions *)coreOption otherOptions:(NSArray<id<TapTapSdkBaseOptions>> * _Nullable)otherOptions;

/// 初始化。必须在主线程调用，且不支持从多个线程并发调用，理由同上。
/// - Parameter coreOption: 核心库配置
+ (void)initWithOptions:(TapTapSdkOptions *)coreOption;


/// 切换语言
/// - Parameter language: 要切换的语言
+ (void)updateLanguage:(TapLanguageType)language;

/// 检查初始化状态
/// - Return    0：初始化信息正常 （TAPSDK_INIT_STATE_SUCCESS）
///         -1： 未初始化 （TAPSDK_INIT_STATE_EMPTY）
///         -2： 应用 bundleId 与 clientID 或 clientToken 不匹配 （TAPSDK_INIT_STATE_INVALID）
+ (int)checkInitState;

/// SDK 内部使用：本地同步初始化是否已开始（含异步 gatekeeper 仍在进行中）。
/// 用于内部读取本地登录缓存，不弹窗。接入方请使用 checkInitState。
+ (BOOL)isLocalInitStarted NS_SWIFT_NAME(isLocalInitStarted());

@end

NS_ASSUME_NONNULL_END
