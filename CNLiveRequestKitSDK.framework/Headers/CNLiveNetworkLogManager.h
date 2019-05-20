//
//  CNLiveNetworkLogManager.h
//  CNLiveRequestBastKit_Example
//
//  Created by 流诗语 on 2019/1/10.
//  Copyright © 2019年 woshiliushiyu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CNLiveNetworkLogManager : NSObject
/**
 单例对象
 */
+ (instancetype)defaultManager;

/**
 返回日志打印的日期时间
 */
- (NSString *)logDateTime;

/**
 设置日期格式
 
 @param formatStr 日期格式，默认为@"yyyy-MM-dd hh:mm:ss.SSS"
 */
- (void)setupDateFormat:(NSString *)formatStr;

/**
 弹窗展示错误日志
 
 @param error HTTP响应错误
 */
- (void)showErrorLogWithResponse:(NSError *)error;
@end
