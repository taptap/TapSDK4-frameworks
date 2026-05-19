//
//  NSString+Tools.h
//  TapSDK
//
//  Created by JiangJiahao on 2018/4/24.
//  Copyright © 2018年 dyy. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (TapSDKCore)
- (NSString *)tds_URLEncodedString;
- (NSString *)tds_URLDecodedString;
///反转字符串
- (NSString *)tds_reverse;

// MD5 hash of the file on the filesystem specified by path
+ (NSString *)tds_stringWithMD5OfFile:(NSString *)path;
// The string's MD5 hash
- (NSString *)tds_MD5Hash;

// base64
- (NSString *)tds_base64Encode;
- (NSString *)tds_base64Decode;

// aes256
- (NSString *)tds_aes256Encrypt:(NSString *)key;
- (NSString *)tds_aes256Decrypt:(NSString *)key;

/// 是否是空字符串
+ (BOOL)tds_isEmpty:(NSString *)string;

- (NSDictionary *)tds_toDictionary;
/**
 *  去除空格后的字符串
 *
 *  @return
 */
- (NSString *)trim;

/**
 *  去除首位空格之后的length
 *
 *  @return length
 */
- (NSUInteger)trimLength;

/**
 *  判断是否包含某个字符串
 *  @return 是否包含
 */
- (BOOL)contains:(NSString *)string;

+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;

@end
