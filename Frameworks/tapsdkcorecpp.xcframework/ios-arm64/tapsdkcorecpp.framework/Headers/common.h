#ifndef TAPSDKCORE_SRC_COMMON_H_
#define TAPSDKCORE_SRC_COMMON_H_

typedef const char* (*CommonVariablesGetter)();
typedef void (*MemoryDeallocator)(const char*);

#endif //TAPSDKCORE_SRC_COMMON_H_
