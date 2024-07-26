//
//  TapComplianceSDK
//
//  Created by 黄驿峰 on 2022/8/31.
//

#import <Foundation/Foundation.h>
#import <TapTapCoreSDK/TapTapSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapTapComplianceOptions : NSObject <TapTapSDKBaseOptions>

@property (nonatomic, assign) BOOL showSwitchAccount;
@property (nonatomic, assign) BOOL useAgeRange;

- (instancetype)init;
+ (instancetype)initWithJson:(NSDictionary *) json;



@end

NS_ASSUME_NONNULL_END
