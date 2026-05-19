//
//  TapTapGid.h
//  TapTapGid
//
//  Created by wzb on 2024/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^GidUpdateCallback)(NSString *gid);

@interface TapTapGid : NSObject

/// 初始化
/// - Parameters:
///   - clientId: clientId
///   - clientToken: clientToken
///   - region: 地区，0 为国内，1 为海外
+ (void)initWithClientId:(NSString *)clientId clientToken:(NSString *)clientToken region:(NSInteger)region;

/// 初始化
/// - Parameters:
///   - clientId: clientId
///   - clientToken: clientToken
///   - region: 地区，0 为国内，1 为海外
///   - caid: 仅国内 iOS 有，可为空
+ (void)initWithClientId:(NSString *)clientId clientToken:(NSString *)clientToken region:(NSInteger)region caid:(NSString * _Nullable)caid;

/// 注册 Gid 更新回调
/// - Parameters:
///   - callback: 回调函数
+ (void)registerGidUpdateCallback:(GidUpdateCallback)callback;

/// 取消注册 Gid 更新回调
/// - Parameters:
///   - callback: 回调函数
+ (void)unRegisterGidUpdateCallback:(GidUpdateCallback)callback;

/// 从远程获取Gid，获取成功后会调用注册的回调，获取成功一次之后再调用会直接返回缓存
+ (void)fetchRemoteGidIfNotFetched;

/// 同步获取 Gid（读取本地）
+ (NSString *)getGid;

@end

NS_ASSUME_NONNULL_END
