//
//  TapSDKLocalize.h
//  TapTapSDK
//
//  Created by ^-^ on 2024/3/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSInteger, TapLanguageType) {
    TapLanguageType_Auto = 0,// 自动
    TapLanguageType_zh_Hans,// 简体中文
    TapLanguageType_en,// 英文
    TapLanguageType_zh_Hant,// 繁体中文
    TapLanguageType_ja,// 日文
    TapLanguageType_ko,// 韩文
    TapLanguageType_th,// 泰文
    TapLanguageType_id,// 印度尼西亚语
    TapLanguageType_de,// 德语
    TapLanguageType_es,// 西班牙语
    TapLanguageType_fr,// 法语
    TapLanguageType_pt,// 葡萄牙语
    TapLanguageType_ru,// 俄罗斯语
    TapLanguageType_tr,// 土耳其语
    TapLanguageType_vi,// 越南语
};

@interface TapTapSDKLocalize : NSObject

+ (instancetype)shareInstance;

/// 设定当前语言类型
/// @param langType 语言类型
+ (void)setCurrentLanguage:(TapLanguageType)langType;

/// 获取当前语言类型
+ (TapLanguageType)currentLanguage;

/// 获取系统语言
+ (NSString *)getSystemLangString;

/// 获取当前语言的 String
+ (NSString *)getCurrentLangString;

///  获取当前多语言（目前用在 login 多语言提示）
+ (NSString *)getCurrentLangLocaleString;
@end

NS_ASSUME_NONNULL_END
