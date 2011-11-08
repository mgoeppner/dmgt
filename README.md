
![dmgt Logo](http://dmgt.riskywhiskey.com.au/images/dmgt128.png)

Dungeon Master Geek Tools
================================================================================

Dungeon Master Geek Tools is a command line application for use with the Revised
Third Edition of the pen and paper role playing game Dungeons and Dragons. This
simple to use, but yet complex, calculations tool will be designed so that a
computer can generate statistics and intelligently select features to create
Non-Player Characters on the go. With minimal input from the user and an
expandable store of data, this application shall generate the needed game stats
of any creature.

Author:            Ian Whitnall

Website URL:       http://www.riskywhiskey.com.au

Contact eMail:     riskywhiskey@gmail.com

Project:           Dungeon Master Geek Tools

Copyright (C) 2007-2011 RiskyWhiskey http://www.riskywhiskey.com.au/

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, version 3 of the License.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see http://www.gnu.org/licenses/.

Linux Distro, Mac OSX and other Unix-like OS Install
================================================================================

Simply move the application file "dmgt" to /usr/local/bin with root permission
and the application should become available while in the terminal much like any
system tool.

Windows Install
================================================================================

Move the application to somewhere on C drive and edit your environment settings
as follows:

1. Right-click on "My Computer" and select "Properties".

2. Click Advanced -> Environment Variables.

3. In the box entitled "System Variables" scroll down to the line that says
   "PATH" and double-click the entry.

4. You will be presented with a dialog box with two text boxes, the bottom text
   box allows you to edit the PATH variable. It is very important that you do
   not delete the existing values in the PATH string, this will cause all sorts
   of problems for you!

5. Scroll to the end of the string and at the end add ";<dmgt-directory>\".
   Here <dmgt-directory> is the full absolute path name of the installation
   directory; eg "C:\dmgt\dir\". Don't forget the semicolon (;) this separates
   the entries in the PATH.

6. Press OK -> OK -> OK and you are done.

Once you have edited your environment settings, dmgt should be accessable from
the Command Prompt like a system tool.

Compile and Install
================================================================================

If you have chosen to compile the application from source a handy make file
should be found within the directory. The following explains:

make             Build the application.
                 Build flags overridden by: make FLAGS="insert flags here"

make install     **Linux, OSX and other Unix-like OSs only.**
                 With root premision installs the application to the directory
                 "/usr/local/bin" making it available in terminal.
                 PREFIX overridden by: make PREFIX=/insert/dir/here/ install

make clean       Removes objects from the directory

make cleanall    Removes all build files from directory
