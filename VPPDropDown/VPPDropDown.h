//
//  VPPDropDown.h
//  VPPLibraries
//
//  Created by Víctor on 12/12/11.


//Copyright (c) 2012 Víctor Pena Placer (@vicpenap)
//http://www.victorpena.es/
//
//
//Permission is hereby granted, free of charge, to any person obtaining a copy 
//of this software and associated documentation files (the "Software"), to deal
//in the Software without restriction, including without limitation the rights 
//to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
//copies of the Software, and to permit persons to whom the Software is furnished
//to do so, subject to the following conditions:
//
//The above copyright notice and this permission notice shall be included in
//all copies or substantial portions of the Software.
//
//THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
//IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.





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
 
 Take into account that if you add multiple dropdowns in the same section, they must be 
 together, so all cells between the first dropdown and the last one are managed by the library.
 
 ### Relative index path
 
 If you are using any of the relative index path deprecated methods, you should read this. 
 Otherwise, skip it.
 
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
    NSIndexPath *_globalRootIndexPath;
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
 @name Managing dropdown status
*/

/** Specifies whether the dropdown is exanded or not. */
@property (nonatomic, assign, getter = isExpanded) BOOL expanded;

/** Specifies the dropdown's selected index. 
 
 This property only applies to selection dropdowns. If you change this value
 manually, no dropdown delegate's method will be called. */
@property (nonatomic, assign) int selectedIndex;


/** ---
 @name Storing data
 */
 
/** This property stores custom data. Use it to store any information you want. */
@property (nonatomic, retain) id object;



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

/** Indicates if the given indexPath is contained in any dropdown associated with 
 the given tableView. */
+ (BOOL) tableView:(UITableView *)tableView dropdownsContainIndexPath:(NSIndexPath *)indexPath;

/** Returns the current number of expanded cells for all dropdowns included in 
 the given section of the given table.
 
 **Important** the returned number doesn't take into account any root cell.
 
 @warning **Example** for a dropdown with three child rows, if the dropdown is 
 expanded the returned value will be three. Otherwise it will be zero.
*/
+ (NSInteger) tableView:(UITableView *)tableView numberOfExpandedRowsInSection:(NSInteger)section;

/** Returns the corresponding cell for the given parameters.
 
 LIbrary will automatically set up the cell according to the corresponding dropdown. */
+ (UITableViewCell *) tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;

/** Indicates if dropdown's root cell is placed in the given indexPath. */
- (BOOL) isRootCellAtIndexPath:(NSIndexPath *)indexPath;

/** Returns YES if the given indexPath is root for any dropdown. Otherwise 
returns NO. */
+ (BOOL) tableView:(UITableView *)tableView isRootCellAtIndexPath:(NSIndexPath *)indexPath;


/** Indicates the dropdown's visible number of rows. 
 
 If the dropdown is contracted, numberOfRows will be 0. Otherwise, 
 numberOfRows will be the count of elements. */
@property (nonatomic, readonly) int numberOfRows;

    
/** **Deprecated** Indicates if the given relativeIndexPath is contained and managed by the
 dropdown.
 
 @bug **Deprecated** Use tableView:dropdownsContainIndexPath: instead. */
- (BOOL) containsRelativeIndexPath:(NSIndexPath *)relativeIndexPath __attribute__ ((deprecated));

/** **Deprecated** Indicates if dropdown's root cell is placed in the given
 relativeIndexPath.

 @bug **Deprecated** Use isRootCellAtIndexPath: instead. */
- (BOOL) isRootCellAtRelativeIndexPath:(NSIndexPath *)relativeIndexPath __attribute__ ((deprecated));

/** 
 **Deprecated** Returns the corresponding cell for the given parameters. 
 
 @bug **Deprecated** Use tableView:cellForRowAtIndexPath: instead.
 */
- (UITableViewCell *) cellForRowAtRelativeIndexPath:(NSIndexPath *)relativeIndexPath globalIndexPath:(NSIndexPath *)globalIndexPath __attribute__ ((deprecated));




/** ---
 @name Table view delegate
 */

/** Lets specify a custom height for the given index path. 
 
 This method will automatically delegate on the corresponding dropdown's delegate. 
 If it does not implement the method `dropDown:heightForElement:atIndexPath:`, `tableView.rowHeight` will be returned, so
 you should call this only when the dropdown's delegate is expected to return an 
 height. */
+ (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

/** Indicates that the specified indexPath has been selected. 
 
 Library will automatically notify the dropdown containing the selected row. */
+ (void) tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath;


/** **Deprecated** Indicates the dropdown the corresponding cell for the given parameters 
 has been selected. */
- (void) didSelectRowAtRelativeIndexPath:(NSIndexPath *)relativeIndexPath
                         globalIndexPath:(NSIndexPath *)globalIndexPath;

@end
