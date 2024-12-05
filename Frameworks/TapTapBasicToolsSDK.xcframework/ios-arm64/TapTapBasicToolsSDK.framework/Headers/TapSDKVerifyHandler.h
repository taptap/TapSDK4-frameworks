//
//  NSObject+TapSDKVerifyHandler.h
//  TapTapBasicToolsSDK
//
//  Created by SeraphLi on 2024/10/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/**
    给实现 TapTapSDKVerifyProtocol 类的所有静态方法添加前置校验
 */
@interface TapSDKVerifyHandler : NSObject

/// 在对外接口中添加前置校验
+(void)aspectTapSDKApi;

@end

NS_ASSUME_NONNULL_END
