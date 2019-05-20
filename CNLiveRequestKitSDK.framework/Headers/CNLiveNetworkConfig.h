//
//  CNLiveNetworkConfig.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/17.
//  Copyright © 2018年 group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveNetworkRequest.h"
@class AFSecurityPolicy;

static NSString *const CNLiveResponseNetworkDataKey = @"data";
static NSString *const CNLiveResponseNetworkErrorCodeKey = @"errorCode";
static NSString *const CNLiveResponseNetworkErrorMessageKey = @"errorMessage";

@interface CNLiveNetworkConfig : NSObject

/**
 单例构建初始化
 */
+(CNLiveNetworkConfig *)shareConfig;
//根地址
@property (nonatomic, strong) NSString *baseUrl;
///默认请求参数
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> * defaultParam;
///请求证书许可
@property (nonatomic, strong) AFSecurityPolicy *securityPolicy;
///开发环境 log
@property (nonatomic) BOOL debugLogEnabled;
///是不是在 Dome中
@property (nonatomic) BOOL isDome;
///是否显示服务器错误信息显示
@property (nonatomic) BOOL isShowResult;
///是否通过 app 版本判断缓存是否过期
@property (nonatomic) BOOL appVersionCache;
///是否是批请求
@property (nonatomic) BOOL isBatchRequest;
///是否是链请求
@property (nonatomic) BOOL isChainRequest;
#pragma mark - 批&链 请求相关参数 -
///批请求完成数
@property (nonatomic) NSInteger finishedCount;
///批请求总数
@property (nonatomic) NSInteger totalCount;
///批请求时请求体
@property (readonly, strong, nonatomic) NSMutableArray<CNLiveNetworkRequest *>* requestArray;
//添加批请求
- (void)addBatchRequest:(CNLiveNetworkBaseRequest *)request;
//添加链请求
- (void)addChainRequest:(NSArray<CNLiveNetworkRequest *>*)requestArray;
//移除所有批&链请求
- (void)removeAllRequestArray;
//清除所有参数
- (void)clearCompletionBlock;
///批请求返回
@property (copy, nonatomic) void(^resultBatchCompletionBlock)(NSArray * requestArray);
///链请求返回
@property (copy, nonatomic) void(^resultChainCompletionBlock)(NSArray * requestArray);
///主请求配置
@property (strong, nonatomic) NSURLSessionConfiguration * sessionConfiguration;
@end
