//
//  TapTipHUD.h
//  TapCommonSDK
//
//  Created by 黄驿峰 on 2023/9/6.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapSDKTipHUD : UIView

+ (void)showTip:(NSString *)tip;

+ (void)showTip:(NSString *)tip bundleName:(NSString *)bundleName imageName:(NSString *) imageName;

+ (void)showTip:(NSString *)tip bundleName:(NSString *)bundleName imageName:(NSString *) imageName timeInterval:(NSTimeInterval)timeInterval;

@end

NS_ASSUME_NONNULL_END
