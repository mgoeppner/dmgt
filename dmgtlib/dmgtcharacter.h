//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Character Class Header
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
#ifndef DMGT_LIBRARY_DMGTCHARACTER_H_
#define DMGT_LIBRARY_DMGTCHARACTER_H_

//------------------------------------------------------------------------------
// Included Libraries
#include <string>

#include "dmgterror.h"
#include "dmgtabilities.h"
#include "dmgtskills.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
//
class DmgtCharacter
{
  public:
    DmgtCharacter(const std::string &gender,
                  const std::string &alignment,
                  const std::string &name);
    ~DmgtCharacter() {};
    
    //Level up the character by x number of levels passed
    void levelUp(const int &levels);
    
    //void parse(const std::string &file_name);
  private:
    std::string             name_;
    std::string             gender_;
    std::string             alignment_;
    DmgtAbilities           abilities_;
    DmgtSkills              skills_;
};

} // namespace dmgt
#endif

