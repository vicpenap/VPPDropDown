//
//  VPPDropDownElement.m
//  VPPLibraries
//
//  Created by Víctor on 12/12/11.
//  Copyright (c) 2011 Víctor Pena Placer. All rights reserved.
//

#import "VPPDropDownElement.h"

@implementation VPPDropDownElement

@synthesize title;
@synthesize object;

- (VPPDropDownElement *) initWithTitle:(NSString *)ttitle andObject:(id)oobject {
    if (self = [super init]) {
        self.title = ttitle;
        self.object = oobject;
    }
    
    return self;
}

@end
