//
//  VPPDropDown.h
//  VPPLibraries
//
//  Created by Víctor on 12/12/11.
//  Copyright (c) 2011 Víctor Pena Placer. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "VPPDropDownDelegate.h"

typedef enum {
    VPPDropDownTypeDisclosure = 0, // childs of drop down cell are treated as disclosure cells 
    VPPDropDownTypeSelection, // childs of drop down cell are treated as selection cells 
    VPPDropDownTypeCustom // childs of drop down cell must be decorated by delegate
} VPPDropDownType; 





/** 
 VPPDropDown is a library that allows you to create dropdown-like menus in a 
 table view, as seen in old Twitter 3 for iPhone. 
 
 You can create three kinds of dropdown menus (*VPPDropDownType*):
 
 - *VPPDropDownTypeDisclosure*, childs of drop down cell are treated as disclosure cells,
 useful for grouping detailed view controllers.
 - *VPPDropDownTypeSelection*, childs of drop down cell are treated as selection cells,
 useful for editing preferences.
 - *VPPDropDownTypeCustom*, childs of drop down cell should be decorated by the delegate.
 
 You can mix different dropdowns in the same or different section.
 
 ### Relative index path
 
 The concepts of relative index path and global index path are widely used in this library. 
 Some method signatures require a relative index path, and some requires both index paths.
 
 What is exactly a relative index path? If in the table's section where the drop down 
 will be placed are more drop downs, the relative index path's row is substraction 
 of the number of rows in the precedent drop downs (using *numberOfRows* dropdown property)
 to the tableview indexpath's row.
 
 This relative index path is used to know which dropdown's child cell is been treated.
 
 The global index path is the tableview's index path itself.
 
 Checking the included sample application will clear these concepts.
 
 @warning If there is only one dropdown per section, relativeIndexPath and 
 globalIndexPath have the same value.
 */

@interface VPPDropDown : NSObject {
@private
    VPPDropDownType _type;
    NSArray *_elements;
    NSString *_title;
    id<VPPDropDownDelegate> _delegate;
    UITableView *_tableView;
    NSIndexPath *_rootIndexPath;
    BOOL _expanded;
    int _selectedIndex;
}






/** ---
 @name Reading dropdown setup
 */

/** Indicates the drop down type.
 
 Type can be:
 
 - *VPPDropDownTypeDisclosure*, childs of drop down cell are treated as disclosure cells,
 useful for grouping detailed view controllers.
 - *VPPDropDownTypeSelection*, childs of drop down cell are treated as selection cells,
 useful for editing preferences.
 - *VPPDropDownTypeCustom*, childs of drop down cell should be decorated by the delegate.
 */
@property (nonatomic, readonly) VPPDropDownType type;

/**  VPPDropDownElement objects. They conform the dropdown's childs. */
@property (nonatomic, readonly) NSArray *elements;

/** The root cell's title. */
@property (nonatomic, readonly) NSString *title;

/** The root cell's indexPath. All childs will be placed after it. */
@property (nonatomic, readonly) NSIndexPath *indexPath;

/** The tableView where the dropdown is. */
@property (nonatomic, readonly) UITableView *tableView;

/** Holds a reference to the delegate */
@property (nonatomic, readonly) id<VPPDropDownDelegate> delegate;

/** Tells the dropdown if it is using the entire tableView's section.
 
 This changes the expanding/contracting animation. 
 
 - If usesEntireSection is set to YES, expanding/contracting will be done
 by inserting/removing cells. 
 - Otherwise, expanding/contracting will be done refreshing the section.
 */
@property (nonatomic, assign) BOOL usesEntireSection;





/** ---
 @name Reading dropdown status
*/

/** Indicates whether the dropdown is exanded or not. */
@property (nonatomic, readonly, getter = isExpanded) BOOL expanded;






/** ---
 @name Constructors
 */

/** Returns a newly initialized dropdown. 
 
 This is the designated initializer.
 
 @param title Indicates the title of the root cell.
 
 @param type Should be one of:
 
 - *VPPDropDownTypeDisclosure*, childs of drop down cell are treated as disclosure cells,
 useful for grouping detailed view controllers.
 - *VPPDropDownTypeSelection*, childs of drop down cell are treated as selection cells,
 useful for editing preferences.
 - *VPPDropDownTypeCustom*, childs of drop down cell should be decorated by the delegate.
 
 @param tableView The tableView where the dropdown will be placed.
 
 @param indexPath The tableView's indexPath where the dropdown will be placed.
 
 @param elements An array of VPPDropDownElement objects. They will conform the dropdown's childs.
 
 @param delegate A reference to the delegate.
 */ 
- (VPPDropDown *) initWithTitle:(NSString *)title 
                           type:(VPPDropDownType)type 
                      tableView:(UITableView *)tableView
                      indexPath:(NSIndexPath *)indexPath
                       elements:(NSArray *)elements 
                       delegate:(id<VPPDropDownDelegate>)delegate;


/** Returns a newly initialized disclosure dropdown. 
  
 @param title Indicates the title of the root cell.
 
 @param tableView The tableView where the dropdown will be placed.
 
 @param indexPath The tableView's indexPath where the dropdown will be placed.
 
 @param delegate A reference to the delegate.
 
 @param firstObject, ... A comma-separated list of strings ending with `nil`. 
 It represents the titles of all dropdown's childs.
 */ 
- (VPPDropDown *) initDisclosureWithTitle:(NSString *)title 
                                tableView:(UITableView *)tableView
                                indexPath:(NSIndexPath *)indexPath
                                 delegate:(id<VPPDropDownDelegate>)delegate
                            elementTitles:(NSString *)firstObject, ... NS_REQUIRES_NIL_TERMINATION;

/** Returns a newly initialized selection dropdown. 
 
 @param title Indicates the title of the root cell.
 
 @param tableView The tableView where the dropdown will be placed.
 
 @param indexPath The tableView's indexPath where the dropdown will be placed.
 
 @param delegate A reference to the delegate.

 @param selectedIndex The initial selected index.

 @param firstObject, ... A comma-separated list of strings ending with `nil`. 
 It represents the titles of all dropdown's childs.
 */ 
- (VPPDropDown *) initSelectionWithTitle:(NSString *)title
                               tableView:(UITableView *)tableView
                               indexPath:(NSIndexPath *)indexPath
                                delegate:(id<VPPDropDownDelegate>)delegate 
                           selectedIndex:(int)selectedIndex
                           elementTitles:(NSString *)firstObject, ... NS_REQUIRES_NIL_TERMINATION;




/** ---
 @name Table view data source
 */


/** Indicates if the given relativeIndexPath is contained and managed by the
 dropdown */
- (BOOL) containsRelativeIndexPath:(NSIndexPath *)relativeIndexPath;

/** Indicates if dropdown's root cell is placed in the given
 relativeIndexPath */
- (BOOL) isRootCellAtRelativeIndexPath:(NSIndexPath *)relativeIndexPath;


/** Indicates the visible number of rows. 
 
 If the dropdown is contracted, numberOfRows will be 0. Otherwise, 
 numberOfRows will be the count of elements. */
@property (nonatomic, readonly) int numberOfRows;

/** Returns the corresponding cell for the given parameters. */
- (UITableViewCell *) cellForRowAtRelativeIndexPath:(NSIndexPath *)relativeIndexPath globalIndexPath:(NSIndexPath *)globalIndexPath;




/** ---
 @name Table view delegate
 */

/** Indicates the dropdown the corresponding cell for the given parameters 
 has been selected. */
- (void) didSelectRowAtRelativeIndexPath:(NSIndexPath *)relativeIndexPath
                         globalIndexPath:(NSIndexPath *)globalIndexPath;

@end
