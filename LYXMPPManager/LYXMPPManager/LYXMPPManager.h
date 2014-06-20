//
//  LYXMPPManager.h
//  LYXMPPManager
//
//  Created by 老岳 on 14-6-5.
//  Copyright (c) 2014年 老岳. All rights reserved.
//

#define HostName @"tigase.xmpp.etiantian.com" //服务器地址
//#define HostName @"yuedongkui.com"

#define kXMPPUserNameKey    @"xmppUserName"
#define kXMPPPasswordKey    @"xmppPassword"

#define XMPP_Resource @"mobile_im" //定死jid中的resource
#define Body_Type @"subject"        //发送的xml语句中增加一个属性，判断发送类型

#import <Foundation/Foundation.h>
#import "XMPPFramework.h"

typedef void(^CompletionBlock)();


@protocol LYXMPPManagerDelegate;
@interface LYXMPPManager : NSObject


#pragma mark - XMPP相关的属性和方法定义
/**
 *  全局的XMPPStream，只读属性
 */
@property (strong, nonatomic, readonly) XMPPStream *xmppStream;

/**
 *  是否注册用户标示
 */
@property (assign, nonatomic) BOOL isRegisterUser;

/**
 *  用户是否登录成功
 */
@property (assign, nonatomic) BOOL isUserLogon;

@property (nonatomic, weak) id <LYXMPPManagerDelegate> delegete;

/**
 * @brief 全局单例
 */
+ (LYXMPPManager *)sharedInstance;


/**
 *  连接到服务器
 *  @param completion 连接正确的块代码
 *  @param faild      连接错误的块代码
 */
- (void)connectWithUSerName:(NSString *)userName
                   passWord:(NSString *)passWord
                 completion:(CompletionBlock)completion
                     failed:(CompletionBlock)faild;

/**
 * @brief 发送文本消息
 * @param type : text  文本
 * @param type : image 图片
 * @param type : voice 语音
 */
- (void)sendMessage:(NSString *)message from:(NSString *)fromUserName to:(NSString *)toUserName type:(NSString *)type;


@end




@protocol LYXMPPManagerDelegate <NSObject>

/** 接受到消息 */
- (void)xmppManager:(LYXMPPManager *)manager didReceiveMessageWithMessage:(XMPPMessage *)message;

@end

