#ifndef BIFROST_SDK_SRC_COMMON_H_
#define BIFROST_SDK_SRC_COMMON_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// 订阅成功、失败、退订、断线、被踢下线时回调。svcCmd/errCode 不为 0 表示订阅终止（失败、退订、断线、被踢等），端侧需要重新拉取 token，再次调用 TapSdkBifrostSubscribeService()。
// 仅当 svcCmd 和 errCode 同时为 0 时，表示订阅成功；其他情况表示订阅终止。
//   - svcCmd 服务自定义协议号，用于选择正确的结构体，反序列化 data。只有被踢下线时，svcCmd 才有值；订阅失败等出错的情况，其值为 0
//   - errCode 0 表示成功；非 0 表示失败，此时可用 pb.Error 反序列化 data，获取具体的错误信息
typedef void (*SubscribeCallback)(const char* svc, uint32_t svcCmd, uint32_t errCode, const void* data, uint32_t dataLen);

// 请求处理成功/失败时回调。
//   - reqID 为调用 AsyncRequest 时传递进来的参数，用于对应到原始请求
//   - svcCmd 服务自定义协议号，用于选择正确的结构体，反序列化 data
//   - errCode 0 表示成功，此时根据 svcCmd 反序列化 data；非 0 表示失败，此时使用 pb.Error 反序列化 data
typedef void (*RequestCallback)(uint64_t reqID, const char* svc, uint32_t svcCmd, uint32_t errCode, const void* data, uint32_t dataLen);

// 收到服务端下发消息时回调。
//   - svcCmd 服务自定义协议号，用于选择正确的结构体，反序列化 data
typedef void (*MessageCallback)(const char* svc, uint32_t svcCmd, const void* data, uint32_t dataLen);

#ifdef __cplusplus
}
#endif

#endif //BIFROST_SDK_SRC_COMMON_H_
