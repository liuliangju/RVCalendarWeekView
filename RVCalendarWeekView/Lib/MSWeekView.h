//
//  RVWeekView.h
//  RVCalendarWeekView
//
//  Created by Badchoice on 22/8/16.
//  Copyright © 2016 revo. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MSCollectionViewCalendarLayout.h"
#import "MSDragableEvent.h"
#import "MSEvent.h"


@protocol MSWeekViewDelegate <NSObject>
-(void)MSWeekView:(id)sender eventSelected:(MSEventCell*)eventCell;
@end

@interface MSWeekView : UIView <UICollectionViewDataSource, UICollectionViewDelegate,MSCollectionViewDelegateCalendarLayout>
{
    NSArray             * mEvents;
}

@property(strong,nonatomic) UICollectionView* collectionView;
@property(strong,nonatomic) MSCollectionViewCalendarLayout* weekFlowLayout;

@property(nonatomic) int daysToShowOnScreen;
@property(nonatomic) int daysToShow;
@property(strong,nonatomic) NSArray* events;

@property(weak,nonatomic) id<MSWeekViewDelegate> delegate;

/**
 * Usually the section is the day, but you can create your decorator with custom eventsBySection and make
 * The section whatever you want
 */
@property(strong,nonatomic,readonly) NSMutableDictionary *eventsBySection;

/**
 * Override this function to customize the views you want to use
 */
-(void)registerClasses;

/**
 * Call this function to reload (when
 */
-(void)forceReload:(BOOL)reloadEvents;

-(void)addEvent   :(MSEvent*)event;
-(void)addEvents  :(NSArray*)events;
-(void)removeEvent:(MSEvent*)event;

-(NSDate*)firstDay;

@end
