//
//  CNLiveNetworkPrivate.h
//  CNLiveRequestBastKit
//
//  Created by 流诗语 on 2018/12/15.
//  Copyright © 2018年 group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CNLiveNetworkBaseRequest.h"
#import "CNLiveNetworkConfig.h"

@interface CNLiveNetworkPrivate : NSObject

+ (BOOL)validateJSON:(id)json withValidator:(id)jsonValidator;

+ (void)addDoNotBackupAttribute:(NSString *)path;

+ (NSString *)md5StringFromString:(NSString *)string;

+ (NSString *)appVersionString;

+ (NSStringEncoding)stringEncodingWithRequest:(CNLiveNetworkBaseRequest *)request;

+ (BOOL)validateResumeData:(NSData *)data;

+ (NSDictionary<NSString *, NSString *> *)requestDefultHeaderFieldValueDictionary:(CNLiveNetworkBaseRequest *)request;

+ (NSDictionary <NSString *, NSString *>*)requestAgrumentHeavyParam:(NSDictionary *)param CurrentAgumentDict:(NSDictionary *)currentDict;

+ (NSInteger)getNowTimestamp;

+ (NSString *)signvalue:(NSDictionary*)parameter URLString:(NSString *)urlString;

+ (NSString*)sha1:(NSString *)string;
@end


@interface CNLiveNetworkBaseRequest (Setter)

@property (nonatomic, strong, readwrite) NSURLSessionTask *requestTask;
@property (nonatomic, strong, readwrite, nullable) NSData *responseData;
@property (nonatomic, strong, readwrite, nullable) id responseJSONObject;
@property (nonatomic, strong, readwrite, nullable) id responseObject;
@property (nonatomic, strong, readwrite, nullable) NSString *responseString;
@property (nonatomic, strong, readwrite, nullable) NSError *error;

@end

@interface CNLiveNetworkBaseRequest (RequestAccessory)

- (void)toggleAccessoriesWillStartCallBack;
- (void)toggleAccessoriesWillStopCallBack;
- (void)toggleAccessoriesDidStopCallBack;

@end
