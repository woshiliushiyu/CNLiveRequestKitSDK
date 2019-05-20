//
//  CNLiveNetworkEnum.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/6.
//  Copyright © 2018年 group. All rights reserved.
//

#ifndef CNLiveNetworkEnum_h
#define CNLiveNetworkEnum_h

typedef NS_ENUM(NSUInteger, CNLiveRequestMethod) {
    /** GET请求 */
    CNLiveRequestMethodGET,
    /** POST请求 */
    CNLiveRequestMethodPOST,
};

typedef NS_ENUM(NSUInteger, CNLiveNetworkCacheType) {
    /** 只加载网络数据 */
    CNLiveNetworkCacheTypeNetworkOnly,
    /** 先加载缓存,然后加载网络 */
    CNLiveNetworkCacheTypeCacheNetwork
};

typedef NS_ENUM(NSUInteger, CNLiveRequestPriority) {
    /** 低优先级 */
    CNLiveRequestPriorityLow,
    /** 默认优先级 */
    CNLiveRequestPriorityDefault,
    /** 高优先级 */
    CNLiveRequestPriorityHigh,
};

typedef NS_ENUM(NSInteger, CNLiveNetworkStatusType) {
    /** 网络状态未知 */
    CNLiveNetworkStatusUnknown,
    /** 无网络 */
    CNLiveNetworkStatusNotReachable,
    /** 手机网络（蜂窝） */
    CNLiveNetworkStatusReachableViaWWAN,
    /** WIFI网络 */
    CNLiveNetworkStatusReachableViaWiFi
};

typedef NS_ENUM(NSUInteger, CNLiveRequestSerializer) {
    /** 请求数据为二进制格式 */
    CNLiveRequestSerializerHTTP,
    /** 请求数据为JSON格式 */
    CNLiveRequestSerializerJSON
};

typedef NS_ENUM(NSUInteger, CNLiveResponseSerializer) {
    /** 响应数据为JSON格式*/
    CNLiveResponseSerializerJSON,
    /** 响应数据为二进制格式*/
    CNLiveResponseSerializerHTTP
};

NS_ENUM(NSUInteger) {
    /** 缓存无效*/
    CNLiveRequestCacheErrorExpired = 1,
    /** 缓存版本不匹配*/
    CNLiveRequestCacheErrorVersionMismatch = 2,
    /** 缓存信息不匹配*/
    CNLiveRequestCacheErrorSensitiveDataMismatch = 3,
    /** App版本不匹配*/
    CNLiveRequestCacheErrorAppVersionMismatch = 4,
    /** 无效缓存时间*/
    CNLiveRequestCacheErrorInvalidCacheTime = 5,
    /** 无效数据,缓存不存在*/
    CNLiveRequestCacheErrorInvalidMetadata = 6,
    /** 无效缓存*/
    CNLiveRequestCacheErrorInvalidCacheData = 7
};
    
NS_ENUM(NSUInteger) {
    /** 返回状态码无效*/
    CNLiveRequestValidationErrorInvalidStatusCode = 8,
    /** 无效JSON 数据*/
    CNLiveRequestValidationErrorInvalidJSONFormat = 9,
};
#endif /* CNLiveNetworkEnum_h */
