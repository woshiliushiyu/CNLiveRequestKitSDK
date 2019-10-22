//
//  CNLiveNetworkRequest.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/6.
//  Copyright © 2018年 group. All rights reserved.
//

#import "CNLiveNetworkBaseRequest.h"

@interface CNLiveNetworkRequest : CNLiveNetworkBaseRequest
//是否忽略本地数据
@property (nonatomic) BOOL ignoreCache;
///同 CNLiveNetworking setCacheTimeInSeconds:
@property (assign, nonatomic) NSInteger cacheTimeInSeconds;
///同 CNLiveNetworking setCacheVersion:
@property (assign, nonatomic) long cacheVersion;
///同 CNLiveNetworking setCacheSensitiveData:
@property (copy, nonatomic)id cacheSensitiveData;
///同 CNLiveNetworking setWriteCacheAsynchronously:
@property (assign, nonatomic) BOOL writeCacheAsynchronously;

//缓存地址
@property (copy, nonatomic) NSString * cachePath;
@end

