//
//  TapOpenLogHelper.h
//  TapTapSDKCore
//
//  Created by ^-^ on 2024/4/24.
//

#import <Foundation/Foundation.h>
#import <TapTapBasicToolsSDK/TapTapSDKLogConfiguration.h>


NS_ASSUME_NONNULL_BEGIN


typedef NS_ENUM (NSInteger, OpenLogEventActionType){
    INIT,
    START,
    SUCCESS,
    FAIL,
    CANCEL
};
// 事件属性参数
extern NSString *const TAPSDKOPENLOG_EVENT_PARAM_FUNC ;
extern NSString *const TAPSDKOPENLOG_EVENT_PARAM_ERROR_CODE ;
extern NSString *const TAPSDKOPENLOG_EVENT_PARAM_ERROR_MSG ;

@interface TapTapSDKOpenLogHelper : NSObject

/// 业务埋点 （上报 tapsdk表）
/// - Parameters:
///   - projcet:模块名称
///   - properties:埋点参数
+ (void)reportBusinessLog:(TapTapSDKProjectType)project properties:(nullable NSDictionary *)properties;

/// 业务埋点 （上报 tapsdk表）
/// - Parameters:
///   - projcet:模块名称
///   - action: 埋点事件，上报时参数key 为 action
///   - properties: 埋点参数，上报时参数 key 为 args
+ (void)reportBusinessLog:(TapTapSDKProjectType)project  action:(NSString *)action properties:(nullable NSDictionary *)properties;

/// 技术埋点 （上报 tapsdk-apm 表）
/// - Parameters:
///   - projcet:模块名称
///   - action: 埋点事件
///   - properties: 埋点参数，上报时参数 key 为 args
+ (void)reportTechnicalLog:(TapTapSDKProjectType)project action:(NSString *)action properties:(nullable NSDictionary *)properties;

/// 业务埋点 （上报 tapsdk表）, session_id 根据 project 管理
/// - Parameters:
///   - projcet:模块名称
///   - actionType: 埋点事件类型
///   - properties: 埋点参数，上报时参数 key 为 args
/// - Returns: 该事件上报时携带的 session 值，当 actionType 为 init 时为 nil
+ (NSString *)reportBusinessLog:(TapTapSDKProjectType)project  actionType:(OpenLogEventActionType) actionType properties:(nullable NSDictionary *)properties;

/// 业务埋点 （上报 tapsdk表）
/// - Parameters:
///   - projcet:模块名称
///   - eventKey: 事件 KEY, , session_id 根据 event_key 管理 一次接口调用后可能内部会有多个事件并行执行，例如成就，所以使用该字段来区分不同事件
///   - actionType: 埋点事件类型
///   - properties: 埋点参数，上报时参数 key 为 args
/// - Returns: 该事件上报时携带的 session 值，当 actionType 为 init 时为 nil
+ (NSString *)reportBusinessLog:(TapTapSDKProjectType)project  eventKey:(nullable NSString *) eventKey actionType:(OpenLogEventActionType) actionType properties:(nullable NSDictionary *)properties;



@end

NS_ASSUME_NONNULL_END
