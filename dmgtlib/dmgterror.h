//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Error Class Header
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
#ifndef DMGT_LIBRARY_DMGTERROR_H_
#define DMGT_LIBRARY_DMGTERROR_H_

//------------------------------------------------------------------------------
// Included Libraries
#include <string>
#include <exception>

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
// A simple custom error class for the dmgt library. An error code and human
// readable message is produced on an error creation.
class DmgtError : public std::exception
{
  public:
    // Default constructor
    DmgtError(const std::string &function, const std::string &error);
    // Deconstructor
    ~DmgtError() throw() {};
    // Exception's what() override
    virtual const char* what() const throw() {return error_message_.c_str();}
    // Retrun the error message
    const std::string message();
  private:
    std::string error_message_; // The human readable error message
};

} // namespace dmgt
#endif

