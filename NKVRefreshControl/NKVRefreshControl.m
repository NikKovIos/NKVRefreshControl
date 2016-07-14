//
//  NKVRefreshControl.m
//  NKVRefreshControlExample
//
//  Created by Nik Kov on 14.07.16.
//  Copyright © 2016 Nik Kov. All rights reserved.
//

#import "NKVRefreshControl.h"

@implementation NKVRefreshControl

- (instancetype)initWithPullToRefresh:(NKVPullToRefresh *)pullToRefresh infinityScroll:(NKVInfinityScroll *)infinityScroll
{
    self = [super init];
    if (self)
    {
        if (pullToRefresh)
            self.pullToRefresh = pullToRefresh;
        if (infinityScroll)
            self.infinityScroll = infinityScroll;
    }
    return self;
}

+ (NKVRefreshControl *)addPullToRefreshToScrollView:(UIScrollView *)scrollView delegate:(id)delegate pullToRefreshAction:(SEL)pullToRefreshAcrtion
{
    NKVPullToRefresh *pullToRefreshInstance = [NKVPullToRefresh new];
    return [[NKVRefreshControl alloc]initWithPullToRefresh:pullToRefreshInstance infinityScroll:nil];
}

+ (NKVRefreshControl *)addInfinityScrollToScrollView:(UIScrollView *)scrollView delegate:(id)delegate infinityScrollAction:(SEL)infinityScrollAction
{
    NKVInfinityScroll *infinityScrollInstance = [NKVInfinityScroll new];
    return [[NKVRefreshControl alloc]initWithPullToRefresh:nil infinityScroll:infinityScrollInstance];
}

+ (NKVRefreshControl *)addBOTHRefreshControlsToScrollView:(UIScrollView *)scrollView delegate:(id)delegate pullToRefreshAction:(SEL)pullToRefreshAcrtion
{
    NKVPullToRefresh *pullToRefreshInstance = [NKVPullToRefresh new];
    NKVInfinityScroll *infinityScrollInstance = [NKVInfinityScroll new];
    return [[NKVRefreshControl alloc]initWithPullToRefresh:pullToRefreshInstance infinityScroll:infinityScrollInstance];
}

@end
