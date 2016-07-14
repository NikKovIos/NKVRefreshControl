//
//  NKVRefreshControl.h
//  NKVRefreshControlExample
//
//  Created by Nik Kov on 14.07.16.
//  Copyright © 2016 Nik Kov. All rights reserved.
//

#import "NKVInfinityScroll.h"
#import "NKVPullToRefresh.h"
#import <UIKit/UIKit.h>

@interface NKVRefreshControl : UIView

/**
 Add Pull to refresh to ScrollView with delegate controller (typically 'self') and action selector. Pull to refresh call selector when user pull ScrollView (UITableView) down. Typically it uses to load data.
 */
+ (NKVRefreshControl *)addPullToRefreshToScrollView:(UIScrollView *)scrollView delegate:(id)delegate pullToRefreshAction:(SEL)pullToRefreshAcrtion;

/**
 Add Infinity Scroll to ScrollView with delegate controller (typically 'self') and action selector. Infinity scroll call selector, when user srolls down to bottom of ScrollView.
 */
+ (NKVRefreshControl *)addInfinityScrollToScrollView:(UIScrollView *)scrollView delegate:(id)delegate infinityScrollAction:(SEL)infinityScrollAction;

/**
 Add both Pull to refresh and Infinity Scroll by one method. You also can do it separately.
 */
+ (NKVRefreshControl *)addBOTHRefreshControlsToScrollView:(UIScrollView *)scrollView delegate:(id)delegate pullToRefreshAction:(SEL)pullToRefreshAcrtion;

@property (strong, nonatomic) NKVPullToRefresh *pullToRefresh;
@property (strong, nonatomic) NKVInfinityScroll *infinityScroll;

//1
//:TODO State of controls
//:TODO UIView of natural activity indicators
//:TODO Implementing of own activity indicator
//:TODO Adding customizeble activity indicator from pod
//:TODO Property for stop action when it already in process
//:TODO Customizable placing in screen (constraints)
//2
//:TODO Add Cocoapods
//:TODO Add Cartage

@end


@protocol NKVCustomActivityIndicatorProtocol <NSObject>

@required
/**
 Height for refreshing view, when it is refreshing
 */
- (CGFloat)heightForRefreshView;

/**
 Calls when it starts to refresh. You should put here add animations methods.
 */
- (void)startRefreshing;

/**
 Calls when it stops to refresh. You should put here remove animations methods.
 */
- (void)stopRefreshing;

@optional
/**
 You can customize position or animation of your activity indicator depending on pull distance.
 */
- (void)didUpdatePullRatio:(CGFloat)pullRatio;

@end
