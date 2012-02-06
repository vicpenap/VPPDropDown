//
//  VPPDropDownElement.h
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
