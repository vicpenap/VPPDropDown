//
//  VPPDropDownElement.h
//  VPPLibraries
//
//  Created by Víctor on 12/12/11.
//  Copyright (c) 2011 Víctor Pena Placer. All rights reserved.
//

#import <Foundation/Foundation.h>

/** This clase conforms a VPPDropDown element. It is composed by a title and 
 an object. The title will be the one shown in the associated cell. Using the
 object is up to you.
 
 You can use it to hold any information you may need. If you don't need it, 
 you can set it to `nil`.
 */

@interface VPPDropDownElement : NSObject {
@private
    NSString *title;
    id object;
}

/** ---
 @name Element properties 
 */

/** Element title. 
 
 This title will be the one shown in the associated cell. */
@property (nonatomic, retain) NSString *title;

/** The element object. 
 
 Using the object is up to you.
 
 You can use it to hold any information you may need. If you don't need it, 
 you can set it to `nil`. */
@property (nonatomic, retain) id object;


/** ---
 @name Constructor 
 */

/* Returns a newly initialized element with the given title and object.
 
 `object` can be `nil` if you don't need it. */
- (VPPDropDownElement *) initWithTitle:(NSString *)title andObject:(id)object;

@end
