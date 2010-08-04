//
//  PLTabBarController.h
//  PlutoLand
//
//  Created by xu xhan on 7/22/10.
//  Copyright 2010 xu han. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PLSegmentView.h"

#define USING_UITABBAR_CONTROLLER_SUBCLASS

#ifndef USING_UITABBAR_CONTROLLER_SUBCLASS

@protocol PLTabBarControllerDelegate <UITabBarDelegate>

@optional


@end

//TODO: add lazy load viewController , by using a delegate when need to display a new ViewController's contents
@interface PLTabBarController : UIViewController<PLSegmentViewDelegate> {
	
	NSArray *viewControllers;
	PLSegmentView *tabBarView;
	UIView *containerView;
	
	int _selectedIndex;
}

@property (nonatomic, retain) PLSegmentView *tabBarView;
@property(nonatomic,readonly) int selectedIndex;
@property(nonatomic,readonly) UIViewController* selectedVC;

- (id)initWithTabBar:(PLSegmentView*)tabBar viewControllers:(NSArray*)viewControllers;

- (void)updateViewAndTabBarToIndex:(int)index;


@end

#else

@interface PLTabBarController : UITabBarController<PLSegmentViewDelegate>
{
	PLSegmentView* _plTabbar;
}
@property(nonatomic,retain) PLSegmentView *tabBarView;


@end


#endif
