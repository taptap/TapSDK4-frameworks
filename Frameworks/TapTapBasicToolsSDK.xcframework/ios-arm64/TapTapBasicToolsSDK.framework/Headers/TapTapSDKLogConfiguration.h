//
//  TapSDKLogConfiguration.h
//  TapTapSDKBasicTools
//
//  Created by ^-^ on 2024/4/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, TapTapSDKProjectType) {
    TapTapUpdateProject,
    TapTapAppDurationProject,
    TapTapCoreProject,
    TapTapLoginProject,
    TapTapMomentProject,
    TapTapAchievementProject,
    TapTapComplianceProject,
    TapTapShareProject
};

@interface TapTapSDKLogConfiguration : NSObject



/// 获取公共基础埋点参数
+ (NSDictionary *)getCommonBaseParameters;

+ (NSString *)getProjectType:(TapTapSDKProjectType)type;
@end

NS_ASSUME_NONNULL_END
