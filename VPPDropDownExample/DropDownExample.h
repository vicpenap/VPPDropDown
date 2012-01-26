//
//  DropDownExample.h
//  VPPLibraries
//
//  Created by Víctor on 13/12/11.
//  Copyright (c) 2011 Víctor Pena Placer. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "VPPDropDown.h"
#import "VPPDropDownDelegate.h"

@interface DropDownExample : UITableViewController <VPPDropDownDelegate, UIActionSheetDelegate> {
@private
    VPPDropDown *_dropDownSelection;
    VPPDropDown *_dropDownDisclosure;
    VPPDropDown *_dropDownCustom;
    
    NSIndexPath *_ipToDeselect;
}

@end
