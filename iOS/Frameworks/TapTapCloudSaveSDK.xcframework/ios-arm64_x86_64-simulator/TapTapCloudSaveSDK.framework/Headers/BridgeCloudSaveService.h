//
//  BridgeCloudSaveService.h
//  TapTapCloudSave
//
//  Created by TapTap SDK Team on 2024/12/24.
//

#import <Foundation/Foundation.h>
#import <TapTapCloudSaveSDK/TapTapCloudSaveSDK-Swift.h>

NS_ASSUME_NONNULL_BEGIN

@interface BridgeCloudSaveService : NSObject <TapTapCloudSaveCallback>

/// 注册CloudSave状态回调
+ (void)registerCloudSaveCallback:(void (^)(NSString *result))callback;

/// 创建存档
+ (void)archiveMetadata:(NSString *)archiveMetadata
       archiveFilePath:(NSString *)archiveFilePath
       archiveCoverPath:(NSString * _Nullable)archiveCoverPath
       bridgeCallback:(void (^)(NSString *result))callback;

/// 更新存档
+ (void)archiveUUIDForUpdate:(NSString *)archiveUUID
        archiveMetadataForUpdate:(NSString *)archiveMetadata
        archiveFilePathForUpdate:(NSString *)archiveFilePath
        archiveCoverPathForUpdate:(NSString * _Nullable)archiveCoverPath
        bridgeCallback:(void (^)(NSString *result))callback;

/// 删除存档
+ (void)archiveUUID:(NSString *)archiveUUID
        bridgeCallback:(void (^)(NSString *result))callback;

/// 获取存档列表
+ (void) getArchiveList: (void (^)(NSString *result))callback;

/// 获取存档数据
+ (void) archiveUUID:(NSString *)archiveUUID
         archiveFileID:(NSString *)archiveFileID
         bridgeCallback:(void (^)(NSString *result))callback;

/// 获取存档封面
+ (void) archiveUUIDForCover:(NSString *)archiveUUIDForCover
         archiveFileIDForCover:(NSString *)archiveFileID
         bridgeCallback:(void (^)(NSString *result))callback;

@end

NS_ASSUME_NONNULL_END 
