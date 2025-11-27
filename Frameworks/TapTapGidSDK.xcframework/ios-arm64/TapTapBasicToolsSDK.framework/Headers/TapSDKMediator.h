//
//  TapSDKMediator.h
//  TapTapSDK
//
//  Created by wzb on 2024/3/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef id _Nullable (^TapSDKMediatorHandler)(NSDictionary *params);

@interface TapSDKMediator : NSObject


/// 注册路由
/// - Parameters:
///   - eventName: 事件名称
///   - handler: 事件自定义参数
+ (void)registerHandlerForEvent:(NSString *)eventName
                        handler:(TapSDKMediatorHandler)handler;


/// 发送路由
/// - Parameters:
///   - eventName: 事件名称
///   - params: 事件自定义参数
///   - return: 调用的结果，返回一个数组，包含这个 eventName 所有 handler 的返回值
+ (nonnull NSArray *)triggerEvent:(NSString *)eventName
        withParams:(NSDictionary * _Nullable)params;

@end

NS_ASSUME_NONNULL_END
