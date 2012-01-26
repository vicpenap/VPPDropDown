//
//  VPPDropDownDelegate.h
//  VPPLibraries
//
//  Created by Víctor on 12/12/11.
//  Copyright (c) 2011 Víctor Pena Placer. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VPPDropDownElement.h"


@class VPPDropDown;

/** This protocol defines a set of methods to notify the delegate when:
 
 - any dropdown child has been selected.
 - dropdown needs delegate cell customization.
 
 While for the first case implementing the methods is mandatory, for the second
 case it is mandatory only in case you are using a custom drop down.
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

@end
