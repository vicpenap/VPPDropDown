# VPPDropDown 0.3.0

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

- 2012/02/08 (0.3.0)
	- Added ability to modify some dropdown status' properties, 
such as expanded or selectedIndex.
	- Added height method to be able to change the row's height
according to the associated dropdown's element.
- 2012/02/08 (0.2.2)
	- Fixed a bug that caused a crash when the first dropdown cell 
was not the first cell on its section. 
- 2012/02/08 (0.2.1)
	- Fixed a bug when adding new dropdown to an indexPath that 
was already used. 
- 2012/02/04 (0.2.0)
	- Added intelligent scrolling when expanding dropdowns.
	- Deprecated all methods using relative index paths.
- 2011/01/24 (0.1.0)
	- Initial release.

## License 

Copyright (c) 2012 Víctor Pena Placer ([@vicpenap](http://www.twitter.com/vicpenap))
http://www.victorpena.es/


Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

