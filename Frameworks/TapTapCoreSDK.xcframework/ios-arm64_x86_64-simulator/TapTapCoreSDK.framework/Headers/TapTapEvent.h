//
//  TapTapEvent.h
//  TapTapSDK
//
//  Created by ^-^ on 2024/3/26.
//

#import <Foundation/Foundation.h>
#import <TapTapBasicToolsSDK/TapTapSDKVerifyProtocol.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapEvent : NSObject <TapTapSDKVerifyProtocol>

/// 绑定游戏（接入方）的用户 ID
/// - Parameter userID: 接入方的用户 ID
+ (void)setUserID:(NSString *)userID;

/// 绑定游戏的用户 ID 和自定义属性
/// - Parameters:
///   - userID: 接入方的用户 ID
///   - properties: 此用户下对应的属性
+ (void)setUserID:(NSString *)userID 
       properties:(nullable NSDictionary *)properties;

/// 解除绑定用户 ID
+ (void)clearUser;

/// 获取当前的设备标识
+ (NSString *)getDeviceId;

/// 上报自定义事件(单事件总大小不超过 100K)
/// - Parameters:
///   - name: 事件名
///   - properties: 参数(单个 String 属性最大长度 256、Number 取值区间为 [-9E15, 9E15]
+ (void)logEvent:(NSString *)name 
      properties:(NSDictionary *)properties;

/// 上报充值成功事件
/// - Parameters:
///   - orderID: 订单 ID，可为空
///   - productName: 产品名称，可为空
///   - amount: 充值金额（单位分，即无论什么币种，都需要乘以100）
///   - currencyType: 货币类型，可为空，参考：人民币 CNY，美元 USD；欧元 EUR
///   - paymentMethod: 支付方式，可为空，如：支付宝
///   - properties: 事件属性，需要在控制后台预先进行配置,值为长度大于0并小于等于256的字符串或绝对值小于1E11的浮点数
+ (void)logPurchasedEvent:(nullable NSString *)orderID
           productName:(nullable NSString *)productName
                amount:(NSInteger)amount
          currencyType:(nullable NSString *)currencyType
         paymentMethod:(nullable NSString *)paymentMethod
            properties:(nullable NSDictionary *)properties;

/// 初始化设备属性操作
/// @param properties 属性字典
+ (void)deviceInitialize:(NSDictionary *)properties;

/// 更新设备属性操作
/// @param properties 属性字典
+ (void)deviceUpdate:(NSDictionary *)properties;

/// 设备属性增加操作
/// @param properties 属性字典 暂时只支持数字属性
+ (void)deviceAdd:(NSDictionary *)properties;

/// 初始化用户属性操作
/// @param properties 属性字典
+ (void)userInitialize:(NSDictionary *)properties;

/// 更新用户属性操作
/// @param properties 属性字典
+ (void)userUpdate:(NSDictionary *)properties;

/// 用户属性增加操作
/// @param properties 属性字典 暂时只支持数字属性
+ (void)userAdd:(NSDictionary *)properties;

/// 增加单个通用参数，每个事件都会上报
/// - Parameters:
///   - key: 属性 key
///   - value: 属性 value
+ (void)addCommonProperty:(NSString *)key 
                    value:(id)value;

/// 增加多个通用参数
/// - Parameter properties: 属性列表
+ (void)addCommon:(NSDictionary *)properties;

/// 清除单个通用参数
/// @param key 属性Key
+ (void)clearCommonProperty:(NSString *)key;

/// 清除多个通用参数
/// @param keys 数组属性Key
+ (void)clearCommonProperties:(NSArray *)keys;

/// 清除全部通用参数
+ (void)clearAllCommonProperties;

/// 添加动态事件属性，每次发送事件会调用dynamicPropertiesCaculator
/// @param dynamicPropertiesCaculator 动态属性回调，需返回希望上传的属性字典
+ (void)registerDynamicProperties:(NSDictionary* (^)(void))dynamicPropertiesCaculator;
@end

NS_ASSUME_NONNULL_END
