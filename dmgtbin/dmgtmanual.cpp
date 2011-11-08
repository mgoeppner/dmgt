//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Manual Class Source
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
#include "dmgtmanual.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
DmgtManual::DmgtManual(const std::string &in_symbol,
                       const std::string &out_symbol,
                       const std::string &revision) {
    in_symbol_  = in_symbol;  // Characters which represent the in stream
    out_symbol_ = out_symbol; // Characters which represent the out stream
    revision_   = revision;   // Store revision number
    // Print to screen the manual
    std::cout << "--------------------------------------------------------------------------------\n"
              << "                 Dungeon Master Geek Tools - Revision " << revision << "\n"
              << "--------------------------------------------------------------------------------\n"
              << "\n"
              << " Please note: This is a very early revision and much of it is still under\n"
              << "              development at this present time.\n"
              << "\n"
              << " Dungeon Master Geek Tools is a command line application for use with the\n"
              << " Revised Third Edition of the pen and paper role playing game Dungeons and\n"
              << " Dragons. This simple to use, but yet complex, calculations tool will be\n"
              << " designed so that a computer can generate statistics and intelligently select\n"
              << " features to create Non-Player Characters on the go. With minimal input from\n"
              << " the user and an expandable store of data, this application shall generate the\n"
              << " needed game stats of any creature.\n"
              << "\n"
              << " Operands are as follows:\n"
              << "\n"
              << "  h     This manual. The keyword 'help' also work.\n"
              << "\n"
              << "  r     This followed by correct D20 notation will return a single result. This\n"
              << "        followed by multiple roll notations seperated by spaces will return the\n"
              << "        result of each notation.\n"
              << "\n"
              << "        Example:  " << in_symbol_  << " r 1d4+4 2d6\n"
              << "                  " << out_symbol_ << " 6\n"
              << "                  " << out_symbol_ << " 9\n"
              << "                  " << in_symbol_  << "\n"
              << "\n"
              << "  rw    This followed by correct D20 notation will print to screen the working\n"
              << "        and result of the dice roll. This followed by multiple roll notations\n"
              << "        seperated by spaces will also print the working of each roll notation.\n"
              << "\n"
              << "        Example:  " << in_symbol_  << " rw 1d4+4d6-3 2d6\n"
              << "                  " << out_symbol_ << " 1d4 (2) = 2\n"
              << "                  " << out_symbol_ << " +4d6 (4, 3, 6, 1) = 14\n"
              << "                  " << out_symbol_ << " -3 (3) = -3\n"
              << "                  " << out_symbol_ << " Total = 16\n"
              << "                  " << out_symbol_ << " 2d6 (2, 1) = 3\n"
              << "                  " << out_symbol_ << " Total = 3\n"
              << "                  " << in_symbol_  << "\n"
              << "\n"
              << "  a     Six attributes will be rolled, calculated and printed to screen with\n"
              << "        modifiers. No other information is needed; this tool simply rolls all\n"
              << "        six attributes automatically.\n"
              << "\n"
              << "        Example:  " << in_symbol_  << " a\n"
              << "                  " << out_symbol_ << " 10 14  9 10 10 17\n"
              << "                  " << out_symbol_ << " +0 +2 -1 +0 +0 +3\n"
              << "                  " << in_symbol_  << "\n"
              << "\n"
              << " Copyright: All materials used within this application are found within the 3.5\n"
              << " System Reference Document and are used under the Open Gaming License. This\n"
              << " application and code library remain the intellectual property of Ian Whitnall\n"
              << " of RiskyWhiskey.com.au and can be shared under the GUN General Public License.\n"
              << "\n"
              << " Scroll up to read from the top.                        www.riskywhiskey.com.au\n"
              << "--------------------------------------------------------------------------------\n";
}

} // namespace dmgt

