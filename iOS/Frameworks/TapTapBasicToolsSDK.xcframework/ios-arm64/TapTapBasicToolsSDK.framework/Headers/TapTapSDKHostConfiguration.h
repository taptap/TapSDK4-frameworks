//
//  TapTapSDKHostConfiguration.h
//  TapTapSDKBasicTools
//
//  Created by ^-^ on 2024/5/22.
//

#import <TapTapBasicToolsSDK/TapSDKHost.h>

NS_ASSUME_NONNULL_BEGIN

/// @deprecated 请直接使用 TapSDKHost。这个类只是为了兼容历史上直接引用
/// TapTapSDKHostConfiguration 的调用方（源码 + 运行时 selector 兼容）保留的
/// 转发层，新代码不要使用；除 getGatekeeperHost 外的方法都是从 TapSDKHost
/// 继承来的 Objective-C class method，不需要在这里重复声明也能正常调用。
__attribute__((deprecated("请使用 TapSDKHost，本类将在未来版本移除")))
@interface TapTapSDKHostConfiguration : TapSDKHost

/// @deprecated 已重命名为 TapSDKHost 的 +getApiHost
+ (NSString *)getGatekeeperHost __attribute__((deprecated("请使用 TapSDKHost 的 +getApiHost")));

@end

NS_ASSUME_NONNULL_END
