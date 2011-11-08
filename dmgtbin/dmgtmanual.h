//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Manual Class Header
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
#ifndef DMGT_BINARY_DMGTMANUAL_H_
#define DMGT_BINARY_DMGTMANUAL_H_

//------------------------------------------------------------------------------
// Included Libraries
#include <iostream>
#include <string>

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
// A simple class which prints the manual to screen.
class DmgtManual
{
  public:
    // Constructor
    DmgtManual(const std::string &in_symbol,
               const std::string &out_symbol,
               const std::string &revision);
    // Destructor
    ~DmgtManual() {};
  private:
    std::string revision_;   // The revision number of dmgt
    std::string in_symbol_;  // The characters which represent the in stream
    std::string out_symbol_; // The characters which represent the out stream
};

} // namespace dmgt
#endif

