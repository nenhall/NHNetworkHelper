//
//  ViewController.m
//  NHNetworkHelper
//
//  Created by simope on 16/6/17.
//  Copyright © 2016年 NegHao.W. All rights reserved.
//

#import "ViewController.h"
#import "NHNetworkHelper.h"
#import "MBProgressHUD+NH.h"


@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

}



- (IBAction)downFile:(id)sender {
    
    NHNetworkHelper *helper = [NHNetworkHelper shareInstance];
    NSString *downUrl = @"http://dldir1.qq.com/qqfile/QQforMac/QQ_V4.1.1.dmg";
    
    MBProgressHUD *hud = [MBProgressHUD showProgressToView:nil ProgressModel:MBProgressHUDModeDeterminate Text:@"loading"];

    [helper downloadFileWithRequestUrl:downUrl Parameter:nil SavedPath:nil Complete:^(NSData *data, NSError *error) {
        
        [hud hide:YES];
        
        if (error) {
            [MBProgressHUD showError:@"下载失败" ToView:self.view];
        }else{
            [MBProgressHUD showSuccess:@"下载完成" ToView:self.view];
        }
    } Progress:^(id downloadProgress, double currentValue) {
        hud.progress = currentValue;
//        NSLog(@"progressValue: %0.f",progressValue);
    }];
}

- (IBAction)autoDisappearPrompt:(id)sender {
    
    [MBProgressHUD showAutoMessage:@"自动消失"];
    
}

- (IBAction)onlyText:(id)sender {
    [MBProgressHUD showMessage:@"纯文字,不自动消失" ToView:self.view];
    
//    [MBProgressHUD hideHUD];//使用此方法进行隐藏
}

- (IBAction)onlyTextAutoDidappear:(id)sender {
    
    [MBProgressHUD showMessage:@"纯文字，X秒后自动消失" ToView:self.view RemainTime:3];

}


- (IBAction)textAndPicture:(id)sender {
    
    [MBProgressHUD showCustomIcon:@"talk_gift.png" Title:@"自定义图片" ToView:self.view];
}

- (IBAction)defaultPictureAndText:(id)sender{
    
    [MBProgressHUD showIconMessage:@"默认图,X秒后自动消失" ToView:self.view RemainTime:3];
}


@end
