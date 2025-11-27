//
//  NSBundle+Tools.h
//  TDSAchievement
//
//  Created by TapTap-David on 2020/8/26.
//  Copyright © 2020 taptap. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface NSBundle (TapSDKCore)

+ (instancetype)tap_bundleName:(NSString *)bundleName aClass:(Class)aClass;

- (UIImage *)tap_imageName:(NSString *)imageName;

- (NSString *)tap_localizedStringForKey:(NSString *)key value:(NSString *)value;

- (NSString *)tap_localizedStringForKey:(NSString *)key;
@end
