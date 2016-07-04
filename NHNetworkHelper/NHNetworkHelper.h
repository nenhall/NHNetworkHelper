//
//  NHNetworkHelper.h
//  NHNetworkHelper
//
//  Created by simope on 16/6/17.
//  Copyright © 2016年 NegHao.W. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

typedef enum : NSInteger{
    
    StatusUnknown = 0,//未知状态
    StatusNotReachable,//无网状态
    StatusReachableViaWWAN,//手机网络
    StatusReachableViaWiFi,//Wifi网络
    
} NetworkStatus;

@interface  NHNetworkHelper : NSObject

@property (nonatomic, assign) NetworkStatus netStatus;
@property (nonatomic, strong) NSOutputStream *outputStream;

/**
 *  建立网络请求单例
 */
+ (id)shareInstance;


/**
 *  GET请求
 *
 *  @param url        请求接口
 *  @param parameters 向服务器请求时的参数
 *  @param success    请求成功，block的参数为服务返回的数据
 *  @param failure    请求失败，block的参数为错误信息
 */
- (void)GET:(NSString *)url
 Parameters:(NSDictionary *)parameters
    Success:(void(^)(id responseObject))success
    Failure:(void (^)(NSError *error))failure;


/**
 *  POST请求
 *
 *  @param url        要提交的数据结构
 *  @param parameters 要提交的数据
 *  @param success    成功执行，block的参数为服务器返回的内容
 *  @param failure    执行失败，block的参数为错误信息
 */
- (void)Post:(NSString *)url
  Parameters:(NSDictionary *)parameters
     Success:(void(^)(id responseObject))success
     Failure:(void(^)(NSError *error))failure;

/**
 *  向服务器上传文件
 *
 *  @param url       要上传的文件接口
 *  @param parameter 上传的参数
 *  @param fileData  上传的文件\数据
 *  @param FieldName 服务对应的字段
 *  @param fileName  上传到时服务器的文件名
 *  @param mimeType  上传的文件类型
 *  @param success   成功执行，block的参数为服务器返回的内容
 *  @param failure   执行失败，block的参数为错误信息
 */
- (void)Post:(NSString *)url
   Parameter:(NSDictionary *)parameter
        Data:(NSData *)fileData
   FieldName:(NSString *)fieldName
    FileName:(NSString *)fileName
    MimeType:(NSString *)mimeType
     Success:(void(^)(id responseObject))success
     Failure:(void(^)(NSError *error))failure;



/**
 *  下载文件
 *
 *  @param url       下载地址
 *  @param patameter 下载参数
 *  @param savedPath 保存路径
 *  @param complete  下载成功返回文件：NSData
 *  @param progress  设置进度条的百分比：progressValue
 */
- (void)downloadFileWithRequestUrl:(NSString *)url
                         Parameter:(NSDictionary *)patameter
                         SavedPath:(NSString *)savedPath
                          Complete:(void (^)(NSData *data, NSError *error))complete
                          Progress:(void (^)(id downloadProgress, double progressValue))progress;


/**
 *  NSData上传文件
 *
 *  @param str        目标地址
 *  @param fromData   文件源
 *  @param progress   实时进度回调
 *  @param completion 完成结果
 */
- (void)updataDataWithRequestStr:(NSString *)str
                        FromData:(NSData *)fromData
                        Progress:(void(^)(NSProgress *uploadProgress))progress
                      Completion:(void(^)(id object,NSError *error))completion;


/**
 *  NSURL上传文件
 *
 *  @param str        目标地址
 *  @param fromUrl    文件源
 *  @param progress   实时进度回调
 *  @param completion 完成结果
 */
- (void)updataFileWithRequestStr:(NSString *)str
                        FromFile:(NSURL *)fromUrl
                        Progress:(void(^)(NSProgress *uploadProgress))progress
                      Completion:(void(^)(id object,NSError *error))completion;

/**
 *   监听网络状态的变化
 */
- (NetworkStatus)checkingNetwork;


@end
