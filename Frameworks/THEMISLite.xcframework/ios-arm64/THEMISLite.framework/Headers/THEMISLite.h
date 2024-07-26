//
//  THEMIS.hpp
//  XDGameSafety
//
//  Created by sxf on 2024/3/14.
//

#ifndef THEMIS_hpp
#define THEMIS_hpp

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
void init_themis(const char* host);
void set_adid(const char* id,int32_t id_length);
const char* get_oneid_data();
void set_previous_oneid(const char* oneid,int32_t length);
}
#endif

#ifdef __OBJC__

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface THEMIS : NSObject

+(void)initTHEMIS:(NSString*)host;
+(void)setADID:(NSString*)id length:(int)length;
+(NSString*)getOneIdData;
+(void)setPreviousOneId:(NSString*)oneid length:(int)length;

@end

NS_ASSUME_NONNULL_END
#endif

#endif /* THEMIS_hpp */
