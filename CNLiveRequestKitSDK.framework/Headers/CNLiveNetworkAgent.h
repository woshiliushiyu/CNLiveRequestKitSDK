//
//  CNLiveNetworkAgent.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/17.
//  Copyright © 2018年 group. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CNLiveNetworkBaseRequest;

@interface CNLiveNetworkAgent : NSObject

+ (CNLiveNetworkAgent *)shareAgent;

//添加网络请求
-(void)addRequest:(CNLiveNetworkBaseRequest *)request;

//取消网络请求
-(void)cancelRequest:(CNLiveNetworkBaseRequest *)request;

//取消所有网络请求
-(void)cancelAllRequests;


@end
