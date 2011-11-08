//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Main Application Source
//
//                     /
//                    /0
//                   /00                            /
//                ____00 ___  __    __     __   /  /0
//               0000000 000 0000  0000   0000000 /00000
//              000  000  0000 00000 000 000000    00
//              00    00  000   000   00 00  00    00
//              00    00  00    00    00 00  00    00
//              00    00  00    00    00  0000     00
//              000  000  00    00    00 00        000 /
//               00000000_00_  _00_  _00_ 000000    0000
//                                       00    00
//                                       00   000
//                                        000000
//
// Copyright (C) 2007-2011 RiskyWhiskey <http://www.riskywhiskey.com.au/>
//
// This program is free software: you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation, version 3 of the License.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
// more details
//
// You should have received a copy of the GNU General Public License along with
// this program; gpl.txt. If not, see <http://www.gnu.org/licenses/>.

//------------------------------------------------------------------------------
// Included Libraries
#include <cstdio>
#include <iostream>
#include <string>
#include <sys/stat.h>

#include "dmgtterminal.h"

//------------------------------------------------------------------------------
// Included Windows Libraries
#ifdef _WIN32
#include <direct.h>   // For Windows
#endif

//------------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    std::string name_of_app  = argv[0];    // Name of the application
    std::string revision     = "11.07.01"; // The current revision of dmgt
    std::string in_symbol    = "<- ";      // Character for terminal output
    std::string out_symbol   = "-> ";      // Character for input of user
    std::string alert_symbol = "!! ";      // Character for terminal warning
    std::string home_directory;            // User's home directory
    std::string data_directory;            // Data directory
    struct stat directory_status;          // Data directory status
    std::string temp_data_file;            // Temp data file
    FILE        *p_temp_data_file;         // Pointer to temp data file
    // Check for arguments
    if (argc >= 2)
    {
        std::string operand = argv[1]; // User given commandline operand
        if (operand == "version" || operand == "v" || operand == "-v")
        {
            // Print revision number
            std::cout << "dmgt revision: " << revision << std::endl;
        }
        else
        {
            // Print incorrect usage message
            std::cout << "Incorrect usage! Consult readme.txt!" << std::endl;
        }
        exit(0);
    }
    // Greet user
    std::cout << out_symbol << "Welcome to Dungeon Master Geek Tools\n";
    std::cout << out_symbol << "Revision: " << revision << "\n";
    // Notify user of start process
    std::cout << out_symbol << "Writing temporary data...\n";
    // Collect appropiate information and begin data write according to OS
    #ifdef _WIN32
    if (getenv("APPDATA") != NULL)
    #else
    if (getenv("HOME") != NULL)
    #endif
    {
        // Create data directory according to OS
        #ifdef _WIN32
        home_directory = getenv("APPDATA");
        data_directory = home_directory + "\\dmgt\\";
        if (stat(data_directory.c_str(), &directory_status) != 0)
        {
            mkdir(data_directory.c_str() );
        }
        #else
        home_directory = getenv("HOME");
        data_directory = home_directory + "/.dmgt/";
        if (stat(data_directory.c_str(), &directory_status) != 0)
        {
            mkdir(data_directory.c_str(), 0777);
        }
        #endif
    }
    else
    {
        std::cout << alert_symbol << "Data write error.\n";
        std::cout << out_symbol << "Exiting dmgt...\n";
        exit(1);
    }
    // Create files for temporary data storage
    temp_data_file = data_directory + "temp.data";
    p_temp_data_file = std::fopen(temp_data_file.c_str(), "w");
    if (p_temp_data_file == NULL)
    {
        std::cout << alert_symbol << "Data write error.\n";
        std::cout << out_symbol << "Exiting dmgt...\n";
        exit(1);
    }
    else
    {
        std::fclose(p_temp_data_file);
    }
    // Display helpful message for new users
    std::cout << out_symbol << "Type 'h' for help. Type 'q' to quit dmgt.\n";
    // Infinite loop for terminal until quit command is used
    while (true)
    {
        dmgt::DmgtTerminal the_terminal(in_symbol,    out_symbol,
                                        alert_symbol, revision);
        if (!the_terminal.operand()) break;
    }
    // End application
    exit(0);
}

