//
//  TapTapSDKImageUploader.h
//  TapTapSDK
//  上传图片工具类
//  Created by SeraphLi on 2025/3/24.
//

#import <Foundation/Foundation.h>
#import <ImageIO/ImageIO.h>
#import <UIKit/UIKit.h>
#import <MobileCoreServices/MobileCoreServices.h>
#import <Photos/Photos.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^DownloadProgressBlock)(double progress);
typedef void(^DownloadCompletionBlock)(BOOL success,  NSData *_Nullable imageData, NSString * _Nullable   errorMessage);

@interface TapTapSDKImageNetwork : NSObject <NSURLSessionDownloadDelegate>

@property (nonatomic, copy) DownloadProgressBlock  progressBlock;
@property (nonatomic, copy) DownloadCompletionBlock  completionBlock;

- (void)uploadImage:(NSData *)data
           mimeType:(NSString *) mimeType
               url:(NSString *)urlString
         headers:(NSDictionary *)parameters
         method:(NSString *) method
completion:(void (^)(NSURLResponse * response, NSDictionary *json, NSError   * _Nullable error))completion;

- (void)downloadImageFromURL:(NSString *)urlString progress:(DownloadProgressBlock)progressBlock
completion:(DownloadCompletionBlock)completionBlock;

@end

NS_ASSUME_NONNULL_END
