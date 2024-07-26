//
//  TapSDKLogEvent.h
//  TapTapSDKCore
//
//  Created by ^-^ on 2024/4/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TapSDKLogContentType) {
    TapSDKContentJson,
    TapSDKContentProtobuf,
};

@interface TapTapSDKLogEvent : NSObject
- (instancetype)initIdentifier:(NSString *)identifier withUrl:(NSString *)url type:(TapSDKLogContentType)type;

/// 发送事件
/// - Parameter event: 事件参数
- (void)logEventSend:(NSDictionary *)event;

/// 初始化完成发送存量数据
- (void)sentStockDatas;

- (void)setUrl:(NSString *)url;
@end

NS_ASSUME_NONNULL_END
