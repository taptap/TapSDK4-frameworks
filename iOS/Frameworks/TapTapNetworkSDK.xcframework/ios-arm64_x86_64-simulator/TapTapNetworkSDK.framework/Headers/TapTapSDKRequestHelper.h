//
//  TapTapRequestHelper.h
//  TapTapSDK
//
//  Created by wzb on 2024/3/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKRequestHelper : NSObject

/// 生成固定长度的随机数
+ (NSString *)nonce;

/// User-Agent，{sdk_name}/{sdk_version} 格式字符串，如TapAndroidSDK/3.2.5
+ (NSString *)ua;

/// 把字典转为 query
+ (NSString *)queryStringFromDictionary:(NSDictionary<NSString *, NSString *> *)dictionary;

+ (NSString *)getMD5Data:(NSData *)data;

+ (NSData *)lz4Compress:(NSData *)rawData;
@end

NS_ASSUME_NONNULL_END
