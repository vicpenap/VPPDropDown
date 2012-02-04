# VPPDropDown 0.2.0

VPPDropDown is an iOS library that allows you to create dropdown-like menus
in a table view, as seen in old Twitter 3 for iPhone. 

You can create three kinds of dropdown menus:
 
- Disclosure, childs of drop down cell are treated as disclosure cells, 
useful for grouping detailed view controllers.
- Selection, childs of drop down cell are treated as selection cells, 
useful for editing preferences.
- Custom, childs of drop down cell should be decorated by the delegate.
 
This project contains a sample application using it. Just open the project in 
XCode, build it and run it. 


For full documentation check out 
http://vicpenap.github.com/VPPDropDown

## Using the component

First create a dropdown instance with any constructor. For example:

	[[VPPDropDown alloc] initSelectionWithTitle:@"Selection Combo"
                                          tableView:self.tableView
                                          indexPath:[NSIndexPath indexPathForRow:kRowDropDownSelection inSection:kSection1] 
                                           delegate:self 
                                      selectedIndex:1
                                      elementTitles:@"Option 1", @"Option 2", @"Option 3", nil];

Now, fill your table view data source and delegate for example as follows:

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

Where `kNumberOfRowsInSection1` and `kNumberOfRowsInSection2` indicate the 
amount of rows for those sections, without taking into account if the dropdowns
are expanded or not.

	- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
	{
		...
		
		if ([VPPDropDown tableView:tableView dropdownsContainIndexPath:indexPath]) {
			return [VPPDropDown tableView:tableView cellForRowAtIndexPath:indexPath];
		}
		
		...
	}

And the delegate:

	- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
	{
		...
		
		if ([VPPDropDown tableView:tableView dropdownsContainIndexPath:indexPath]) {
			[VPPDropDown tableView:tableView didSelectRowAtIndexPath:indexPath];
			return;
		}
		
		...
	}

Now implement `VPPDropDownDelegate` and you're done!

Read the included example app for full information.


## Screenshots 

![](https://github.com/vicpenap/VPPDropDown/raw/master/screenshot.png)

## Changelog

- 2012/02/04 (0.2.0)
	- Added intelligent scrolling when expanding dropdowns.
	- Deprecated all methods using relative index paths.
- 2011/01/24 (0.1.0)
	- Initial release.
