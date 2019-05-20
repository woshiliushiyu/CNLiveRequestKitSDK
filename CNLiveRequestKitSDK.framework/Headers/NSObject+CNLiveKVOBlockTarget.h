//
//  NSObject+CNLiveKVOBlockTarget.h
//  CNLiveRequestBastKit_Example
//
//  Created by 流诗语 on 2019/2/28.
//  Copyright © 2019年 woshiliushiyu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (CNLiveKVOBlockTarget)

- (void)addObserverBlockForKeyPath:(NSString*)keyPath block:(void (^)(id _Nonnull obj, _Nullable id oldVal, _Nullable id newVal))block;

- (void)removeObserverBlocksForKeyPath:(NSString*)keyPath;

- (void)removeObserverBlocks;
@end
