//
//  TapTapTimeUtil.h
//  TapTapSDK
//
//  Created by wzb on 2024/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapSDKTimeUtil : NSObject


/// 获取秒级时间戳（考虑时间偏移）
+ (NSInteger)getCurrentTime;


/// 时间纠偏
/// - Parameter time: 秒级时间戳
+ (void)fixTime:(NSInteger)time;

@end

NS_ASSUME_NONNULL_END
