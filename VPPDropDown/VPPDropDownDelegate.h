//
//  VPPDropDownDelegate.h
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
#import "VPPDropDownElement.h"


@class VPPDropDown;

/** This protocol defines a set of methods to notify the delegate when:
 
 - any dropdown child has been selected.
 - dropdown needs delegate cell customization.
 - dropdown needs row's height.
 */
@protocol VPPDropDownDelegate <NSObject>

@required
/** This method is called when any dropdown child is selected. This method 
 is mandatory. 
 
 @param dropDown the involved dropdown.
 @param element the involved element.
 @param globalIndexPath the tableView's selected indexPath.
 */
- (void) dropDown:(VPPDropDown *)dropDown elementSelected:(VPPDropDownElement *)element atGlobalIndexPath:(NSIndexPath *)globalIndexPath;


// implementation of these methods is required if you use a custom dropdown. 
// Return nil in any of them if you don't need to customize the cell.
@optional

/** This method is called when the dropdown needs the root cell.
 @param dropDown the involved dropdown.
 @param globalIndexPath the tableView's involved indexPath.
 @return the customized cell. You can return `nil` if you don't want to 
 customize it. In that case, the dropdown will automatically do it for you.
 */
- (UITableViewCell *) dropDown:(VPPDropDown *)dropDown rootCellAtGlobalIndexPath:(NSIndexPath *)globalIndexPath;

/** This method is called when the dropdown needs an element cell.
 @param dropDown the involved dropdown.
 @param element the involved element.
 @param globalIndexPath the tableView's involved indexPath.
 @return the customized cell. You can return `nil` if you don't want to 
 customize it. In that case, the dropdown will automatically do it for you.
 */
- (UITableViewCell *) dropDown:(VPPDropDown *)dropDown cellForElement:(VPPDropDownElement *)element atGlobalIndexPath:(NSIndexPath *)globalIndexPath;


/** This method is called when the dropdown is asked about the row's height.
 @param dropDown the involved dropdown.
 @param element the involved element.
 @param indexPath the tableView's involved indexPath.
 @return the row's height.
 
 If you do not implement this method, dropDown tableView's `rowHeight` property
 will be returned instead.
 */
- (CGFloat) dropDown:(VPPDropDown *)dropDown heightForElement:(VPPDropDownElement *)element atIndexPath:(NSIndexPath *)indexPath;


@end
