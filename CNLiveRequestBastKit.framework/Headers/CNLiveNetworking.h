//
//  CNLiveNetworking.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/6.
//  Copyright © 2018年 group. All rights reserved.
//

#import "CNLiveNetworkRequest.h"
#import "CNLiveNetworkEnum.h"
@class CNLiveNetworkRequest;

/** 宏定义 */
#define CNLiveNetworkManager [CNLiveNetworking networkManager]

/** 网络状态的Block */
typedef void(^CNLiveNetworkStatusBlock)(CNLiveNetworkStatusType status);

/** 请求返回 Block */
typedef void(^CNLiveNetworkCompletionBlock)(NSURLSessionTask *requestTask,id responseObject,NSError *error);

/** 批请求返回 Block */
typedef void(^CNLiveNetworkFeaturCompletionBlock)(NSArray * resultArray);

typedef NSTimeInterval CNLiveRequestTimeoutInterval;

@interface NSObject (CNLiveNetworking)

/**
 对网络状态进行监听获取

 @param networkStatusBlock 监听回调
 */
+ (void)networkStatusWithBlock:(CNLiveNetworkStatusBlock)networkStatusBlock;

/**
 移除网络监听回调
 */
+ (void)removeNetworkStatue;

@end

@interface CNLiveNetworking : CNLiveNetworkRequest
/**
 单例对象
 */
+ (instancetype)networkManager;

/**
 获取当前请求版本 1.3.1
 */
+ (NSString *)networkingVersion;

/**
 获取本地缓存地址
 */
+ (NSString *)networkingCachePath;

#pragma mark = Request Network

/**
 发起请求
 
 @param method 请求方法
 @param urlString 请求地址
 @param param 请求参数
 @param cacheType 缓存方式
 @param completionBlock 结果返回
 */
+ (NSURLSessionTask *)requestNetworkWithMethod:(CNLiveRequestMethod)method
                                     URLString:(NSString *)urlString
                                         Param:(NSDictionary *)param
                                     CacheType:(CNLiveNetworkCacheType)cacheType
                               CompletionBlock:(CNLiveNetworkCompletionBlock)completionBlock;

/**
 发起上传请求

 @param urlString 上传地址
 @param param 上传参数
 @param formDataBlock 上传体
 @param progressBlock 上传进度
 @param completionBlock 上传完成回调
 @return 结果返回
 */
+ (NSURLSessionTask *)uploadNetworkWithURLString:(NSString *)urlString
                                           Param:(NSDictionary *)param
                                   FormDataBlock:(CNLiveConstructingBlock)formDataBlock
                                   ProgressBlock:(CNLiveSessionProgressBlock)progressBlock
                                 CompletionBlock:(CNLiveNetworkCompletionBlock)completionBlock;


/**
 发起下载请求

 @param urlString 下载地址
 @param param 下载参数
 @param fileDir 资源存放文件夹名称 (不传则资源默认存放 /Library/Caches/CNLiveNetworkDownload/)
 @param progressBlock 下载进度
 @param completionBlock 下载完成回调 (NSURL* responseObject file)
 @return 结果返回 (NSURLSessionDownloadTask *)
 */
+ (NSURLSessionTask *)downloadNetworkWithURLString:(NSString *)urlString
                                             Param:(NSDictionary *)param
                                             FileDir:(NSString *)fileDir
                                             ProgressBlock:(CNLiveSessionProgressBlock)progressBlock
                                           CompletionBlock:(CNLiveNetworkCompletionBlock)completionBlock;

/**
 取消当前请求, 断网重连connectedRequestRetry属性为YES 时.未完成请求返回页面之前,在dealloc 方法中调用此方法.
 */
+ (void)cancelTask;

/**
 取消所有网络请求
 */
+ (void)cancelAll;


/**
 批&链 请求构造 (链&批请求暂不支持缓存)
 
 @param method 请求方法
 @param urlString 请求地址
 @param param 请求参数
 @return 结果返回
 */
+ (CNLiveNetworking *)createBatchOrChainNetworkWithMethod:(CNLiveRequestMethod)method
                                                URLString:(NSString *)urlString
                                                    Param:(NSDictionary *)param;

/**
 批请求
 
 @param requestArray 请求参数数组
 */
-(void)requestBatchWithArray:(NSArray <CNLiveNetworking *>*)requestArray
             CompletionBlock:(CNLiveNetworkFeaturCompletionBlock)completionBlock;

/**
 链请求

 @param requestArray 请求参数数组
 */
- (void)requestChainWithArray:(NSArray <CNLiveNetworking *>*)requestArray
              CompletionBlock:(CNLiveNetworkFeaturCompletionBlock)completionBlock;

#pragma mark = Network Status

/**
 有网络:YES, 无网络:NO
 */
+ (BOOL)isNetworking;

/**
 手机网络:YES, 非手机网络:NO
 */
+ (BOOL)isWWANNetwork;

/**
 WiFi网络:YES, 非WiFi网络:NO
 */
+ (BOOL)isWiFiNetwork;

/**
 实时获取网络状态,此方法整个生命周期内只走一次,使用只需监听即可,多次调用没事.
 
 @param networkStatusBlock 网络状态
 */
//+ (void)networkStatusWithBlock:(CNLiveNetworkStatusBlock)networkStatusBlock;

#pragma mark = 更改相关参数 这些仅仅局限于当前请求,于后续请求参数无关

/**
 设置主请求的域名地址,这个地址在调用changeBaseURL的时候会改变,但是只改边调用changeBaseURL方法的一次请求,后续请求还是会使用该方法的域名. (全局设置)

 @param baseURL 根路径
 */
+ (void)setupBaseURL:(NSString *)baseURL;

/**
 添加默认请求参数 (全局设置)
 
 已实现(plat.)

 @param defaultParam 默认请求参数
 */
+ (void)setupDefaultParam:(NSDictionary<NSString *, NSString *> *)defaultParam;

/**
 更改接口根路径,设置后当前的网络访问使用相对路径,之后的请求还是会使用默认 baseURL
 @param baseURL 根路径
 */
+ (void)changeBaseURL:(NSString *)baseURL;


/**
 设置网络请求的优先级
 
 @param sequestPriority 优先级
 */
+ (void)setupSequestPriority:(CNLiveRequestPriority)sequestPriority;

/**
 设置请求时间 (全局设置)
 
 @param requestTimeoutInterval 请求时间
 */
+ (void)setRequestTimeoutInterval:(CNLiveRequestTimeoutInterval)requestTimeoutInterval;

/**
 是否允许带默认参数 (全局设置)
 
 @param allowRequestDefaultArgument YES & NO
 */
+ (void)setAllowRequestDefaultArgument:(BOOL)allowRequestDefaultArgument;

/**
 是否联网重试
 
 @param connectedRequestRetry YES & NO
 */
+ (void)setConnectedRequestRetry:(BOOL)connectedRequestRetry;

/**
 设置自定义请求体
 
 @param buildCustomUrlRequest 自定义请求体
 */
+ (void)setBuildCustomUrlRequest:(NSURLRequest *)buildCustomUrlRequest
                 CompletionBlock:(CNLiveNetworkCompletionBlock)completionBlock;

/**
 设置网络请求结构
 
 @param requestSerializerType  HTTP & JSON
 */
+ (void)setRequestSerializerType:(CNLiveRequestSerializer)requestSerializerType;

/**
 网络返回结构
 
 @param responseSerializerType HTTP & JSON
 */
+ (void)setResponseSerializerType:(CNLiveResponseSerializer)responseSerializerType;

/**
 设置网络请求间隔,在网络间隔之内,不发起网络请求.只读取本地数据
 
 @param cacheTimeInSeconds second
 */
+ (void)setCacheTimeInSeconds:(NSInteger)cacheTimeInSeconds;

/**
 是否返回结果在异步为异步返回,如果为(YES)则返回的Block为异步,刷新UI时需自己重回主线程

 @param resultResponseAsynchronously Defult NO
 */
+ (void)setResultResponseAsynchronously:(BOOL)resultResponseAsynchronously;

/**
 本地缓存版本设置,此方法主要运用于刷新类型的网络请求.一旦设置版本号之后,在相同url的之后请求都不会缓存数据,建议将刷新的 pageNum 设置为此参数的值.
 
 请求时缓存本地时需要添加的版本号,如果刷新类型的请求接口,则该版本号传请求页数,如果两次传递的版本号不匹配,则只存储第一次请求的数据.(刷新类型的此参数必传)
 
 @param cacheVersion 版本号
 */
+ (void)setCacheVersion:(long)cacheVersion;

/**
 缓存敏感词设置,和之前连接的敏感词不同,则不会走缓存
 
 @param cacheSensitiveData 敏感词
 */
+ (void)setCacheSensitiveData:(id)cacheSensitiveData;

/**
 是否异步缓存网络返回数据
 
 @param writeCacheAsynchronously YES & NO
 */
+ (void)setWriteCacheAsynchronously:(BOOL)writeCacheAsynchronously;

/**
 进行返回数据的 json验证

 @param jsonValidator json
 */
+ (void)setupJsonValidator:(id)jsonValidator;

/**
 参数加密key 不传则代表不进行参数加密 (全局设置)

 @param signKey  加密参数 key
 */
+ (void)setupSignKey:(NSString *)signKey;

/**
 是否对服务器返回结果进行打印 (默认在 release 状态下关闭.debug打开)
 对返回结果进行打印,可返回请求参数体,成功数据,失败数据,并弹框提示服务器错误.

 默认开启全局,可针对某个请求进行关闭.也可通过此方法全局关闭
 
 @param isShow 是否显示
 */
+ (void)setupShowResult:(BOOL)isShow;

/**
 这个只针对返回的数据结构中包含 data 主键.(默认为 NO)
 此方法只针对如此数据
 {
     "data":"xxx",
     "errorCode":"0",
     "errorMessage":"成功"
 }
 
 @param isShowData 是否只显示 data 数据源里面的数据
 */
+ (void)setupShowDataResult:(BOOL)isShowData;

/**
 是dome? 导入到正式工程中一定要换为 NO
 如果不设置 NO 请求参数会改变

 @param isDome YES & NO
 */
+ (void)setupDome:(BOOL)isDome;

@end
