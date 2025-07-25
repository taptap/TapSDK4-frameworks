//
//  TapTapForum.h
//  TapTapSDK
//
//  Created by JiangJiahao on 2019/11/21.
//  Copyright © 2019 taptap. All rights reserved.
//

#import <TapTapMomentSDK/TapTapMomentDelegate.h>
#import <TapTapMomentSDK/TapTapMomentPostData.h>
#import <TapTapMomentSDK/TapTapMomentResultCode.h>
#import <Foundation/Foundation.h>
#import <TapTapBasicToolsSDK/TapTapBasicToolsSDK.h>
#import <TapTapCoreSDK/TapTapBaseVerifyObject.h>


NS_ASSUME_NONNULL_BEGIN

/**
 v1.2.0
 */

FOUNDATION_EXPORT NSString *const TapMomentPageShortcut;
FOUNDATION_EXPORT NSString *const TapMomentPageShortcutKey;

FOUNDATION_EXPORT NSString *const TapMomentPageUser;
FOUNDATION_EXPORT NSString *const TapMomentPageUserKey;
# pragma mark SDK 公开方法
@interface TapTapMoment : TapTapBaseVerifyObject

+ (instancetype)new NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

/// 设置代理
/// @param delegate 代理
+ (void)setDelegate:(id <TapTapMomentDelegate>)delegate;

/// 打开动态
+ (void)open;

+ (void)openScene:(NSString *)sceneId;

/// 发布动态
/// @param content 发布的动态内容
/// @warning `moment`参数：动态内容为视频请选择`TapTapMomentVideoData`, 动态内容为图片时请选择 `TapTapMomentImageData`。
+ (void)publish:(TapTapMomentPostData *_Nonnull)content;

/// 关闭所有内嵌窗口
/// @param title 弹窗标题
/// @param content 弹窗内容
/// @param showConfirm 是否显示确认弹窗
/// @warning 传空或者空串不弹框
+ (void)closeWithTitle:(NSString *)title
               content:(NSString *)content
           showConfirm:(BOOL)showConfirm;

/// 直接关闭所有内嵌窗口
/// @warning 该方法不弹二次确认窗口
+ (void)close;

/// 获取新动态数量
/// @warning 结果在 `Delegate` 下的 `onMomentCallbackWithCode:msg:`, code == TM_RESULT_CODE_NEW_MSG_SUCCEED时，`msg` 即为消息数量
+ (void)fetchNotification;

/// 获取SDK版本名
+ (NSString *)getSdkVersion;

/// 获取SDK版本号
+ (NSString *)getSdkVersionCode;

/// 项目自己的Controller 需要设置 DeferSystemGestures配置
+ (void)needDeferSystemGestures;
@end

NS_ASSUME_NONNULL_END
