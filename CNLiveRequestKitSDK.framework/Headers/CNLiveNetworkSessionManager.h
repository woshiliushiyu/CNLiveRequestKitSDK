//
//  CNLiveNetworkSessionManager.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/11/29.
//  Copyright © 2018年 group. All rights reserved.
//

#import <AFNetworking/AFNetworking.h>

/** 请求任务Block */
typedef void(^CNLiveNetworkTaskBlock)(NSURLSessionTask *requestTask,id responseObject,NSError *error);

/**
 遵守协议，让编译通过，调用AFN私有API
 */
@protocol CNLiveNetWorkSessionManagerProtocol <NSObject>

@optional

/**
 AFN底层网络请求方法
 
 @param method HTTP请求方法
 @param URLString 请求地址
 @param parameters 参数字典
 @param success 成功回调
 @param failure 失败回调
 @return NSURLSessionDataTask
 */
- (NSURLSessionDataTask *)dataTaskWithHTTPMethod:(NSString *)method
                                       URLString:(NSString *)URLString
                                      parameters:(id)parameters
                                  uploadProgress:(void (^)(NSProgress *uploadProgress))uploadProgress
                                downloadProgress:(void (^)(NSProgress *downloadProgress))downloadProgress
                                         success:(void (^)(NSURLSessionDataTask *, id))success
                                         failure:(void (^)(NSURLSessionDataTask *, NSError *))failure;

@end

/**
 对网络请求底层方法的封装
 */
@interface CNLiveNetworkSessionManager : AFHTTPSessionManager

/**
 AFN 网络请求底层依赖

 @param method HTTP请求方法
 @param URLString 请求地址
 @param parameters 请求参数
 @param completion 请求结果回调
 @return 请求任务对象
 */
- (NSURLSessionDataTask *)requestWithMethod:(NSString *)method
                                  URLString:(NSString *)URLString
                                 parameters:(id)parameters
                                 completion:(CNLiveNetworkTaskBlock)completion;

/**
 AFN文件上传底层方法
 
 @param URLString 请求地址
 @param parameters 请求参数
 @param block 表单数据回调
 @param uploadProgress 上传进度回调
 @param completion 请求回调
 @return 请求任务对象
 */
- (NSURLSessionDataTask *)uploadWithURLString:(NSString *)URLString
                                   parameters:(id)parameters
                    constructingBodyWithBlock:(void (^)(id <AFMultipartFormData> formData))block
                    progress:(void (^)(NSProgress *uploadProgress))uploadProgress
                    completion:(CNLiveNetworkTaskBlock)completion;

/**
 AFN文件下载底层方法
 
 @param URLString 请求地址
 @param parameters 参数字典
 @param fileDir 本机文件保存地址
 @param downloadProgressBlock 下载进度回调
 @param completion 请求回调
 @return 下载任务对象
 */
- (NSURLSessionDownloadTask *)downloadWithURLString:(NSString *)URLString
                                         parameters:(id)parameters
                                            fileDir:(NSString *)fileDir
                                           progress:(void (^)(NSProgress *downloadProgress))downloadProgressBlock
                                         completion:(void (^)(NSURL *filePath, NSError *error))completion;
@end

