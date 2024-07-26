//
//  TapTapNetworkRequest.h
//  TapTapSDK
//
//  Created by wzb on 2024/3/27.
//

#import <Foundation/Foundation.h>
#import <TapTapNetworkSDK/TapTapSDKNetworkTarget.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKNetworkRequest : NSObject
+ (void)requestWithTarget:(TapTapSDKNetworkTarget *)target;

+ (NSMutableDictionary *)commonQueryParams;
+ (void)addCommonQueryParam:(NSString *)key value:(NSString *)value;
+ (void)removeCommonQueryParam:(NSString *)key;

@end

NS_ASSUME_NONNULL_END
