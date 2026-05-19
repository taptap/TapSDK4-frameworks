//
//  AntiAddiction.h
//  TapCompliance
//
//  Created by jessy on 2021/9/22.
//

#import <Foundation/Foundation.h>
#import <TapTapComplianceSDK/TapTapComplianceOptions.h>
#import <TapTapCoreSDK/TapTapBaseVerifyObject.h>


NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, TapComplianceResultHandlerCode) {
    TapComplianceResultHandlerLoginSuccess          = 500,   //登录成功
    TapComplianceResultHandlerExited                = 1000,   //登出成功
    TapComplianceResultHandlerSwitchAccount         = 1001,  // 切换账号
    TapComplianceResultHandlerPeriodRestrict        = 1030,  // 不可玩时间段游戏
    TapComplianceResultHandlerAgeLimit              = 1100,  // 适龄限制
    TapComplianceResultHandlerInvalidClientOrNetworkError        = 1200,  // 无效应用 ID 或网络异常

    TapComplianceResultHandlerRealNameStop          = 9002,  // 实名过程中点击了关闭实名窗
    
    TapComplianceResultHandlerOpenAlert __attribute__((deprecated("Not supported"))) = 1095,//未成年允许游戏弹窗

};

typedef NS_ENUM(NSInteger, TapComplianceAgeLimit) {
    TapComplianceAgeLimitUnknown            = -1,
    TapComplianceAgeLimitChild              = 0,
    TapComplianceAgeLimitTeen               = 8,
    TapComplianceAgeLimitYoung              = 16,
    TapComplianceAgeLimitAdult              = 18,
};

@protocol TapTapComplianceDelegate <NSObject>

-(void)complianceCallbackWithCode:(TapComplianceResultHandlerCode)code extra:(NSString * _Nullable)extra;

@end


@interface TapTapCompliance : TapTapBaseVerifyObject


/// 设置回调代理
/// @param delegate 防沉迷代理
+ (void)registerComplianceDelegate:(id<TapTapComplianceDelegate>)delegate;

/// 设置测试环境，需要在 startup 接口调用前设置
/// @param enable 测试环境是否可用
+ (void)setTestEnvironment:(BOOL)enable;


/// 如果使用的TapTap登录，可以快速启动防沉迷&实名系统
/// @param userID 游戏维度的用户唯一标识
+ (void)startup:(NSString *)userID;

/// 退出防沉迷&实名系统
+ (void)exit;

/// 获取用户剩余时长（单位：秒）
+ (NSInteger)getRemainingTime;


/// 获取用户年龄段
+ (TapComplianceAgeLimit)getAgeRange;


/// 查询能否支付
/// @param amount 支付金额，单位分
/// @param callBack 能否成功
/// @param failureHandler 查询能否支付失败（一般网络错误）
+ (void)checkPaymentLimit:(NSInteger)amount callBack:(void (^ _Nullable)(BOOL status, NSString * _Nonnull title, NSString *  _Nonnull description))callBack failureHandler:(void (^ _Nullable)(NSString * _Nonnull))failureHandler;

/// 上报消费结果
/// @param amount 支付金额，单位分
/// @param callBack 上报是否成功
/// @param failureHandler 上报消费结果失败（一般网络错误）
+ (void)submitPayment:(NSInteger)amount callBack:(void(^ _Nullable)(BOOL success))callBack failureHandler:(void (^ _Nullable)(NSString * _Nonnull error))failureHandler;

///获取当前防沉迷Token
+ (NSString *)getCurrentAccessToken;


@end

NS_ASSUME_NONNULL_END
