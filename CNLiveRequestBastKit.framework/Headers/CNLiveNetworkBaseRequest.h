//
//  CNLiveNetworkBaseRequest.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/15.
//  Copyright © 2018年 group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveNetworkEnum.h"
@protocol AFMultipartFormData;

typedef void (^CNLiveConstructingBlock)(id<AFMultipartFormData> formData);
typedef void (^CNLiveSessionProgressBlock)(NSProgress * progress);

@class CNLiveNetworkBaseRequest;
/**
 请求结果返回
 */
typedef void(^CNLiveRequestCompletionBlock)(CNLiveNetworkBaseRequest * request);

/**
 批请求结果回调
 */
typedef void(^CNLiveBatchRequestCompletionBlock)(NSArray * requestArray);

/**
 链请求结果回调
 */
typedef void(^CNLiveChainRequestCompletionBlock)(NSArray * requestArray);

@protocol CNLiveRequestDelegate <NSObject>

@optional

- (void)requestFinished:(__kindof CNLiveNetworkBaseRequest *)request;

- (void)requestFailed:(__kindof CNLiveNetworkBaseRequest *)request;

@end

@protocol CNLiveRequestAccessory <NSObject>

@optional

- (void)requestWillStart:(id)request;

- (void)requestWillStop:(id)request;

- (void)requestDidStop:(id)request;

@end

@interface CNLiveNetworkBaseRequest : NSObject

@property (nonatomic, strong, readonly) NSURLSessionTask *requestTask;

@property (nonatomic, strong, readonly) NSURLRequest *currentRequest;

@property (nonatomic, strong, readonly) NSURLRequest *originalRequest;

@property (nonatomic, strong, readonly) NSHTTPURLResponse *response;
//返回的状态码
@property (nonatomic, readonly) NSInteger responseStatusCode;
//响应头
@property (nonatomic, strong, readonly) NSDictionary *responseHeaders;
//请求结果
@property (nonatomic, strong, readonly) NSData *responseData;

@property (nonatomic, strong, readonly) NSString *responseString;

/////////////////////////////////////////////////
//返回 data类型数据
@property (nonatomic, strong, readonly) id responseObject;
//返回 JSON 类型数据
@property (nonatomic, strong, readonly) id responseJSONObject;
//返回 error信息
@property (nonatomic, strong, readonly) NSError *error;

/////////////////////////////////////////////////
///  取消当前请求
@property (nonatomic, readonly, getter=isCancelled) BOOL cancelled;
///  执行当前请求
@property (nonatomic, readonly, getter=isExecuting) BOOL executing;
/// 
@property (assign, nonatomic) BOOL resultResponseAsynchronously;
///待请求数组
@property (nonatomic, strong) NSArray * requestArray;
///流式上传block
@property (nonatomic, copy) CNLiveConstructingBlock constructingBodyBlock;
///上传下载进度回调
@property (nonatomic, copy) CNLiveSessionProgressBlock progressBlock;
///请求表示
@property (nonatomic) NSInteger tag;
//请求失败回调
@property (nonatomic, copy, nullable) CNLiveRequestCompletionBlock successCompletionBlock;
//请求成功回调
@property (nonatomic, copy, nullable) CNLiveRequestCompletionBlock failureCompletionBlock;
//批请求回调
@property (nonatomic, copy, nullable) CNLiveBatchRequestCompletionBlock resultBatchCompletionBlock;
//链请求回调
@property (nonatomic, copy, nullable) CNLiveChainRequestCompletionBlock  resultChainCompletionBlock;
//请求状态
@property (nonatomic, strong, nullable) NSMutableArray<id<CNLiveRequestAccessory>> *requestAccessories;
//请求结果代理
@property (nonatomic, weak, nullable) id<CNLiveRequestDelegate> delegate;
//请求优先级
@property (nonatomic) CNLiveRequestPriority requestPriority;
//网络状态
@property (nonatomic, assign) CNLiveNetworkStatusType networkStatus;
//下载文件存储文件夹名称
@property (nonatomic, strong, nullable) NSString *fileDir;
//是否是输入下载任务
@property (nonatomic, assign) BOOL isDownload;
//是否显示服务器错误信息显示
@property (nonatomic) BOOL isShowResult;
//是否显示网加加应用返回只显示 data
@property (nonatomic) BOOL isShowDataResult;

#pragma mark - completion Action
///============================================================
/// @name set completion Action
///============================================================

//清空请求
- (void)clearCompletionBlock;

//清空批请求
- (void)clearBatchCompletionBlock;

//清空链请求
- (void)clearChainCompletionBlock;

//
- (void)addAccessory:(id<CNLiveRequestAccessory>)accessory;

//
- (void)resetNetworkManager;

#pragma mark - request Action
///============================================================
/// @name set request Action
///============================================================
///  停止请求
- (void)stop;

///  取消所有请求
- (void)cancelAllRequestTask;

///  开始请求,结果 block返回
- (void)startWithCompletionBlockWithSuccess:(nullable CNLiveRequestCompletionBlock)success
                                    failure:(nullable CNLiveRequestCompletionBlock)failure;

//开始批请求,结果 block返回
- (void)startBatchWithCompletionBlockWithResult:(nullable CNLiveBatchRequestCompletionBlock)resultBatchCompletionBlock;

//开始链请求,结果 block返回
- (void)startChainWithCompletionBlockWithResult:(nullable CNLiveChainRequestCompletionBlock)resultChainCompletionBlock;

#pragma mark - Subclass Override
///==================================================================
/// @name set Subclass Override
///==================================================================

/** 请求完成之后 (在子线程返回主线程之前)*/
- (void)requestCompletePreprocessor;

/** 请求完成之后 (返回主线程之后)*/
- (void)requestCompleteFilter;

//请求失败之后 (在子线程返回主线程之前)
- (void)requestFailedPreprocessor;

//请求失败之后 (返回主线程之后)
- (void)requestFailedFilter;

//设置请求超时时间
@property (assign, nonatomic) NSTimeInterval requestTimeoutInterval;

//请求参数
@property (copy, nonatomic) NSDictionary * requestArgument;

//请求地址
@property (copy, nonatomic) NSString * requestUrl;

//根域名
@property (copy, nonatomic) NSString * baseUrl;

//是否添加默认请求参数
@property (assign, nonatomic) BOOL allowRequestDefaultArgument;

//是否联网重试
@property (assign, nonatomic) BOOL connectedRequestRetry;

//设置缓存时需去除的参数(一般为请求时变动的参数)
@property (strong, nonatomic) NSArray * filterArgument;

//构建自定义请求体
@property (strong, nonatomic) NSURLRequest * buildCustomUrlRequest;

//返回数据结构验证
@property (copy, nonatomic) id jsonValidator;

//请求方法
@property (assign, nonatomic) CNLiveRequestMethod requestMethod;

//请求数据类型
@property (assign, nonatomic) CNLiveRequestSerializer requestSerializerType;

//返回数据类型
@property (assign, nonatomic) CNLiveResponseSerializer responseSerializerType;

//是否允许使用移动流量请求
@property (assign, nonatomic) BOOL allowsCellularAccess;

//参数加密的 key
@property (copy, nonatomic) NSString * signKey;

//状态码验证
- (BOOL)statusCodeValidator;
@end

