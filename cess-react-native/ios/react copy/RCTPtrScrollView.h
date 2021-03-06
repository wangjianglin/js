/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <UIKit/UIScrollView.h>

//#import <React/RCTRootView.h>

//#import "React/RCTAutoInsetsProtocol.h"
//#import "React/RCTEventDispatcher.h"
#import "React/RCTScrollableProtocol.h"
#import "React/RCTView.h"
#import "React/RCTScrollView.h"


@protocol UIScrollViewDelegate;

@interface RCTPtrScrollView : RCTScrollView

@property(nonatomic, copy) RCTDirectEventBlock onRefreshData;
@property(nonatomic, assign) BOOL isOnPullToRefresh;
@property (assign, nonatomic) BOOL currentRefreshingState;
@property(nonatomic, assign) BOOL enablePullToRefresh;


@property(nonatomic, copy) RCTDirectEventBlock onLoadMoreData;
@property(nonatomic, assign) BOOL isOnLoadMore;
@property (assign, nonatomic) BOOL currentLoadMoreState;
@property(nonatomic, assign) BOOL enableLoadMore;


- (void)startPullToRefresh;
- (void)stopPullToRefresh;

- (void)startLoadMore;
- (void)stopLoadMore;

- (instancetype)initWithEventDispatcher:(RCTEventDispatcher *)eventDispatcher NS_DESIGNATED_INITIALIZER;


//@property NSObject<UIScrollViewDelegate> * nativeScrollDelegate;
///**
// * The `RCTScrollView` may have at most one single subview. This will ensure
// * that the scroll view's `contentSize` will be efficiently set to the size of
// * the single subview's frame. That frame size will be determined somewhat
// * efficiently since it will have already been computed by the off-main-thread
// * layout system.
// */
//@property (nonatomic, readonly) UIView *contentView;
//
///**
// * If the `contentSize` is not specified (or is specified as {0, 0}, then the
// * `contentSize` will automatically be determined by the size of the subview.
// */
//@property (nonatomic, assign) CGSize contentSize;
//
///**
// * The underlying scrollView (TODO: can we remove this?)
// */
//@property (nonatomic, readonly) UIScrollView *scrollView;
//
//@property (nonatomic, assign) UIEdgeInsets contentInset;
//@property (nonatomic, assign) BOOL automaticallyAdjustContentInsets;
//@property (nonatomic, assign) NSTimeInterval scrollEventThrottle;
//@property (nonatomic, assign) BOOL centerContent;
//@property (nonatomic, assign) int snapToInterval;
//@property (nonatomic, copy) NSString *snapToAlignment;
//@property (nonatomic, copy) NSIndexSet *stickyHeaderIndices;
//
//// NOTE: currently these event props are only declared so we can export the
//// event names to JS - we don't call the blocks directly because scroll events
//// need to be coalesced before sending, for performance reasons.
//@property (nonatomic, copy) RCTDirectEventBlock onScrollBeginDrag;
//@property (nonatomic, copy) RCTDirectEventBlock onScroll;
//@property (nonatomic, copy) RCTDirectEventBlock onScrollEndDrag;
//@property (nonatomic, copy) RCTDirectEventBlock onMomentumScrollBegin;
//@property (nonatomic, copy) RCTDirectEventBlock onMomentumScrollEnd;
//@property (nonatomic, copy) RCTDirectEventBlock onScrollAnimationEnd;

@end

@interface RCTEventDispatcher (RCTPtrScrollView)

/**
 * Send a fake scroll event.
 */
- (void)sendFakePtrScrollEvent:(NSNumber *)reactTag;

@end
