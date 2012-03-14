//
//  DropDownExample.m
//  VPPLibraries
//
//  Created by Víctor on 13/12/11.
//  Copyright (c) 2011 Víctor Pena Placer. All rights reserved.
//

#import "DropDownExample.h"

#define kNumberOfSections 2

enum {
    kSection1 = 0,
    kSection2
};


// including the dropdown cell !!
/* set to 3 if you want to see how it behaves 
 when having more cells in the same section 
 */
#define kNumberOfRowsInSection1 3 

enum {
    kRowDropDownSelection = 0,
    kRowDropDownDisclosure,    
    kRow1
};


/* set to 2 if you want to see how it behaves 
 when having more cells in the same section 
 */

#define kNumberOfRowsInSection2 1
enum {
    kRowDropDownCustom = 0,
    kS2Row1
};


@implementation DropDownExample

- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
        _dropDownSelection = [[VPPDropDown alloc] initSelectionWithTitle:@"Selection Combo"
                                                              tableView:self.tableView
                                                              indexPath:[NSIndexPath indexPathForRow:kRowDropDownSelection inSection:kSection1] 
                                                               delegate:self 
                                                          selectedIndex:1
                                                          elementTitles:@"Option 1", @"Option 2", @"Option 3", nil];

        _dropDownDisclosure = [[VPPDropDown alloc] initDisclosureWithTitle:@"Disclosure Combo"
                                                                tableView:self.tableView
                                                                indexPath:[NSIndexPath indexPathForRow:kRowDropDownDisclosure inSection:kSection1] 
                                                                 delegate:self 
                                                            elementTitles:@"Disclosure 1", @"Disclosure 2", @"Disclosure 3", @"Disclosure 4", @"Disclosure 5", nil];
        
        
        NSMutableArray *elts = [NSMutableArray array];
        for (int i = 1; i <= 4; i++) {
            // just some mock elements
            VPPDropDownElement *e = [[VPPDropDownElement alloc] initWithTitle:[NSString stringWithFormat:@"Element %d",i] andObject:[NSNumber numberWithInt:i]];
            [elts addObject:e];
            [e release];
        }
        
        _dropDownCustom = [[VPPDropDown alloc] initWithTitle:@"Custom Combo" 
                                                       type:VPPDropDownTypeCustom 
                                                  tableView:self.tableView 
                                                  indexPath:[NSIndexPath indexPathForRow:kRowDropDownCustom inSection:kSection2]
                                                   elements:elts 
                                                   delegate:self];
    }
    return self;
}

- (void) dealloc {
    
    if (_dropDownSelection != nil) {
        [_dropDownSelection release];
        _dropDownSelection = nil;
    }
    if (_dropDownDisclosure != nil) {
        [_dropDownDisclosure release];
        _dropDownDisclosure = nil;
    }
    if (_ipToDeselect != nil) {
        [_ipToDeselect release];
        _ipToDeselect  = nil;
    }
    if (_dropDownCustom != nil) {
        [_dropDownCustom release];
        _dropDownCustom = nil;
    }
    
    [super dealloc];
}
- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];

    // Uncomment the following line to preserve selection between presentations.
    // self.clearsSelectionOnViewWillAppear = NO;
 
    // Uncomment the following line to display an Edit button in the navigation bar for this view controller.
    // self.navigationItem.rightBarButtonItem = self.editButtonItem;
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source

- (CGFloat) tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    switch (indexPath.section) {
        case kSection2:
            if (indexPath.row > 0) {
                return [VPPDropDown tableView:tableView heightForRowAtIndexPath:indexPath];
            }
            
        default:
            break;
    }
    
    return 44;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    // Return the number of sections.
    return kNumberOfSections;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    // Return the number of rows in the section.
    int rows = [VPPDropDown tableView:tableView numberOfExpandedRowsInSection:section];
    switch (section) {
        case kSection1:
            rows += kNumberOfRowsInSection1;
            break;
        case kSection2:
            rows += kNumberOfRowsInSection2;
            break;
            
    }
    return rows;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier] autorelease];
    }
    
    
    // Configure the cell...
    cell.textLabel.text = nil;

    if ([VPPDropDown tableView:tableView dropdownsContainIndexPath:indexPath]) {
        return [VPPDropDown tableView:tableView cellForRowAtIndexPath:indexPath];
    }
    
    // first check if any dropdown contains the requested cell
    int row = indexPath.row - [VPPDropDown tableView:tableView numberOfExpandedRowsInSection:indexPath.section];
    switch (indexPath.section) {
        case kSection1:
            switch (row) {
                case kRow1:
                    cell.textLabel.text = @"This is an independent cell";
                    break;
            }
            break;
        case kSection2:
            switch (row) {
                case kS2Row1:
                    cell.textLabel.text = @"This is an independent cell";
                    break;
            }
            break;
    }
        
    return cell;
}

/*
// Override to support conditional editing of the table view.
- (BOOL)tableView:(UITableView *)tableView canEditRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the specified item to be editable.
    return YES;
}
*/

/*
// Override to support editing the table view.
- (void)tableView:(UITableView *)tableView commitEditingStyle:(UITableViewCellEditingStyle)editingStyle forRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (editingStyle == UITableViewCellEditingStyleDelete) {
        // Delete the row from the data source
        [tableView deleteRowsAtIndexPaths:[NSArray arrayWithObject:indexPath] withRowAnimation:UITableViewRowAnimationFade];
    }   
    else if (editingStyle == UITableViewCellEditingStyleInsert) {
        // Create a new instance of the appropriate class, insert it into the array, and add a new row to the table view
    }   
}
*/

/*
// Override to support rearranging the table view.
- (void)tableView:(UITableView *)tableView moveRowAtIndexPath:(NSIndexPath *)fromIndexPath toIndexPath:(NSIndexPath *)toIndexPath
{
}
*/

/*
// Override to support conditional rearranging of the table view.
- (BOOL)tableView:(UITableView *)tableView canMoveRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Return NO if you do not want the item to be re-orderable.
    return YES;
}
*/

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     [detailViewController release];
     */

    
    // first check if any dropdown contains the requested cell
    if ([VPPDropDown tableView:tableView dropdownsContainIndexPath:indexPath]) {
        [VPPDropDown tableView:tableView didSelectRowAtIndexPath:indexPath];
        return;
    }
    
    int row = indexPath.row - [VPPDropDown tableView:tableView numberOfExpandedRowsInSection:indexPath.section];
    UIAlertView *av;
    switch (indexPath.section) {
        case kSection1:
            switch (row) {
                case kRow1:
                    av = [[UIAlertView alloc] initWithTitle:@"Cell selected" message:@"The independent cell 1 has been selected" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
                    [av show];
                    [av release];
                    [tableView deselectRowAtIndexPath:indexPath animated:YES];
                    break;
                    
                default:
                    break;
            }

            
            break;
            
        case kSection2:
            switch (row) {
                case kS2Row1:
                    av = [[UIAlertView alloc] initWithTitle:@"Cell selected" message:@"The independent cell 2 has been selected" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
                    [av show];
                    [av release];
                    [tableView deselectRowAtIndexPath:indexPath animated:YES];
                    break;
                    
                default:
                    break;
            }
            
            break;
    }
    
}


#pragma mark - VPPDropDownDelegate

- (void) dropDown:(VPPDropDown *)dropDown elementSelected:(VPPDropDownElement *)element atGlobalIndexPath:(NSIndexPath *)indexPath {
    if (dropDown == _dropDownDisclosure) {
        _ipToDeselect = [indexPath retain];
        UIAlertView *av = [[UIAlertView alloc] initWithTitle:@"Disclosure pressed" message:[NSString stringWithFormat:@"%@ has been pressed!",element.title] delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [av show];
        [av release];    
    }
    
    if (dropDown == _dropDownCustom) {
        [self.tableView deselectRowAtIndexPath:indexPath animated:YES];
    }
}
- (UITableViewCell *) dropDown:(VPPDropDown *)dropDown rootCellAtGlobalIndexPath:(NSIndexPath *)globalIndexPath {
    
    return nil;
}
- (UITableViewCell *) dropDown:(VPPDropDown *)dropDown cellForElement:(VPPDropDownElement *)element atGlobalIndexPath:(NSIndexPath *)globalIndexPath {
    static NSString *cellIdentifier = @"CustomDropDownCell";

    UITableViewCell *cell = [self.tableView dequeueReusableCellWithIdentifier:cellIdentifier];
    if (!cell) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:cellIdentifier] autorelease];
    }
    
    cell.textLabel.text = @"Custom cell";
    cell.detailTextLabel.text = [NSString stringWithFormat:@"row %d",globalIndexPath.row];
    
    return cell;
}


- (CGFloat) dropDown:(VPPDropDown *)dropDown heightForElement:(VPPDropDownElement *)element atIndexPath:(NSIndexPath *)indexPath {
    float height = dropDown.tableView.rowHeight;
    
    return height + indexPath.row * 10;
}


#pragma mark - UIAlertViewDelegate
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    if (_ipToDeselect != nil) {
        [self.tableView deselectRowAtIndexPath:_ipToDeselect animated:YES];
        [_ipToDeselect release];
        _ipToDeselect = nil;
    }
}

@end
