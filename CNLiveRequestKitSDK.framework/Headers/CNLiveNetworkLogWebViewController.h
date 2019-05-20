//
//  CNLiveNetworkLogWebViewController.h
//  CNLiveRequestBastKit_Example
//
//  Created by 流诗语 on 2019/1/10.
//  Copyright © 2019年 woshiliushiyu. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface CNLiveNetworkLogWebViewController : UIViewController

@property (nonatomic, copy) NSString *logFilePath;

@property (nonatomic, strong, readonly) UIWebView *webView;
@end

