//
//  TapTapSDKVerifyProtocol.h
//  TapTapBasicToolsSDK
//
//  Created by SeraphLi on 2024/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*
    业务接口前置校验协议，对外类实现该协议后，除了白名单中的方法(通过 getWhiteListMethodArray 设置）外，所有静态方法都会在执行前调用 verifyCurrentState ，并根据返回值判断是真正执行该接口还是返回默认值
 */
@protocol TapTapSDKVerifyProtocol <NSObject>

/// 实现该协议的类中，需要进行校验的内容，返回值表示是否通过校验
/// 建议添加初始化的校验和其他需要过滤的场景，例如区域是否支持
+ (BOOL) verifyCurrentState;

/// 白名单列表，白名单中的方法会直接执行，不通过 verifyCurrentState 校验，建议把内部方法加入进来
/// 默认会添加 load 方法
+ (nullable NSArray *) getWhiteListMethodArray;

@end

NS_ASSUME_NONNULL_END
