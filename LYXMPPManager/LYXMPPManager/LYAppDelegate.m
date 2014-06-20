//
//  LYAppDelegate.m
//  LYXMPPManager
//
//  Created by 老岳 on 14-6-5.
//  Copyright (c) 2014年 老岳. All rights reserved.
//

#import "LYAppDelegate.h"
#import "LYXMPPManager.h"

@implementation LYAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    self.window.backgroundColor = [UIColor whiteColor];
    [self.window makeKeyAndVisible];
    
    self.window.rootViewController = [UIViewController new];
    
    LYXMPPManager *xmppManager = [LYXMPPManager sharedInstance];
    xmppManager.delegete = self;
    [xmppManager connectWithUSerName:@"2115751"
                            passWord:@"1111"
                          completion:^
    {
        NSLog(@"--------登录成功--------");
    } failed:^{
        NSLog(@"--------登录失败-------");
    }];
    
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    button.backgroundColor = [UIColor redColor];
    button.frame = CGRectMake(0, 0, 150, 60);
    button.center = self.window.center;
    [button setTitle:@"发送消息" forState:UIControlStateNormal];
    [button addTarget:self action:@selector(button) forControlEvents:UIControlEventTouchUpInside];
    [self.window addSubview:button];
    
    return YES;
}

- (void)button
{
    [[LYXMPPManager sharedInstance] sendMessage:@"hello"
                                           from:@"我"
                                             to:@"2203065"
                                           type:@"text"];
}

#pragma mark - 接收消息成功
- (void)xmppManager:(LYXMPPManager *)manager didReceiveMessageWithMessage:(XMPPMessage *)message
{
    NSLog(@"message === %@",message);
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:nil message:message.body delegate:nil cancelButtonTitle:nil otherButtonTitles:@"确定", nil];
    [alert show];
}

@end
