//
//  TapMomentOptions.h
//  TapTapSDK
//
//  Created by 赵阳 on 2024/6/16.
//

#import <Foundation/Foundation.h>
#import <TapTapCoreSDK/TapTapSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapMomentOptions : NSObject <TapTapSDKBaseOptions>

- (instancetype)init;
+ (instancetype)initWithJson:(NSDictionary *) json;


@end

NS_ASSUME_NONNULL_END

