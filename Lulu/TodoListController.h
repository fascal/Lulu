//
//  todoListController.h[
//  Lulu
//
//  Created by Dingzhong Weng on 6/10/12.
//  Copyright (c) 2012 Oasislulu. All rights reserved.
//

//alarm clock at edit, icloud support, notification on all devices via icloud, local notification for alarm, customizable font size and color, swipe to forward in cell, search, recover last deletion, change color back to green,diy navigation controller,shake to switch color, tap green dot 3 times going to VIP service

#import <UIKit/UIKit.h>

#import "AddTodoListController.h"
#import "TodoListDetailController.h"
#import "FPPopoverController.h"
#import "ListDatesViewController.h"
#import "AppDelegate.h"
#import "Settings.h"

#define kTableViewBackgroundColorBlack [UIColor colorWithRed:245.0f/255.0f green:245.0f/255.0f blue:245.0f/255.0f alpha:1]
#define kTableViewBackgroundColorGreen [UIColor colorWithRed:245.0f/255.0f green:255.0f/255.0f blue:245.0f/255.0f alpha:1]
#define kContentViewBackground [UIColor colorWithPatternImage:[UIImage imageNamed:@"whitePaper.png"]]
#define kAlarmPosition CGRectMake(0, 0, 15,15)
#define bFullAlphaScrollPoint 63
#define bDifferenceFromFullAlpha 47

@interface TodoListController : UIViewController <UIGestureRecognizerDelegate,UISearchBarDelegate,UITableViewDataSource,UITableViewDelegate,AddTodoDelegate,TodoListDetailDelegate>{
}
@property (strong, nonatomic) TodoListDetailController *childDetailController;
@property (strong, nonatomic) AddTodoListController * childAddController;

@property (strong, nonatomic) NSManagedObjectContext *managedObjectContext;
@property (strong, nonatomic) UIView *cover;
@property (strong, nonatomic) FPPopoverController *popOver;
@property (strong,nonatomic) IBOutlet UITableView* tableView;
@property (strong, nonatomic) IBOutlet UIView *contentView;
@property (strong, nonatomic) NSArray *lists;
@property NSInteger totalRows;
@property (strong, nonatomic) Settings *settings;
@property CGPoint parentCenter;
@property CGRect parentFrame;
@property CGRect originalFrame;
@property CGPoint originalCenter;
@property CGRect  frameDifference;
@property CGPoint centerDifference;
@property BOOL debugMode;
@property BOOL firstTime;

//search
@property (strong, nonatomic) NSMutableArray *filteredLists;
@property (strong, nonatomic) IBOutlet UISearchBar *searchBar;
@property BOOL searching;
//sound
@property (readwrite)	CFURLRef		soundFileURLRef;
@property (readonly)	SystemSoundID	addFileObject;
@property (readonly)	SystemSoundID	closeFileObject;
@property (readonly)	SystemSoundID	detailFileObject;

//guide
@property (strong, nonatomic) IBOutlet UIView *guideView;
@property (strong, nonatomic) IBOutlet UIImageView *arrowTop;
@property (strong, nonatomic) IBOutlet UIImageView *tapTop;
@property (strong, nonatomic) IBOutlet UIImageView *prompt;
@property (strong, nonatomic) IBOutlet UIImageView *arrowBottom;
@property (strong, nonatomic) IBOutlet UIImageView *tapBottom;

//pragma Table Data Source Methods
//pragma Table Delegate Methods
//pragma Todo List Support
//pragma Segue
//pragma Search Data Source
//pragma Search Delegate Methods
//pragma Gesture Recognizer Delegate Methods
-(void)handlePinch:(UIPinchGestureRecognizer*) pinchRecognizer;

//miscs
-(void)newFilteredLists;
-(void)updateFilteredLists:(NSString*)searchTerm;
-(void)debug:(id)object orFunctionOrNil:(NSString*)function withItsStringOrNil: (NSString*)itsString;
-(void)save:(NSManagedObject*)objectOrNil;
-(void)updateBadgeNumber;
-(void)popOver:(id)sender WithCreationDate:(NSDate *)dateCreated andFinishDate:(NSDate *)dateFinished andAlarm:(NSDate *)alarm;
-(void)dismissView;
-(void)newLists;
-(void)initTableView;
-(void)initContentView;
-(void)initSearchView;
-(void)initSound;
-(void)initCover;
-(void)prepareForReturnSegue;
-(void)presentGuide;
-(void)createTestTodoList;
-(void)notFirstTime;

//IBActions
-(IBAction)add:(id)sender;
-(IBAction)accessoryButtonTappedForRowWithIndexPath:(id)sender;

@end