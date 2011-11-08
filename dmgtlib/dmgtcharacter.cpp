//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Character Class Source
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
#include "dmgtcharacter.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
DmgtCharacter::DmgtCharacter(const std::string &gender,
                             const std::string &alignment,
                             const std::string &name)
{
    if (gender != "m" && gender != "M" && gender!= "f" && gender != "F")
    {
        std::string functionName = "dmgt::DmgtCharacter()";
        std::string errorMessage = "Incorrect gender given.";
        throw DmgtError(functionName, errorMessage);
    }
    if (alignment != "LG" && alignment != "NG" && alignment != "CG" &&
        alignment != "lg" && alignment != "ng" && alignment != "cg" &&
        alignment != "LN" && alignment != "NN" && alignment != "CN" &&
        alignment != "ln" && alignment != "nn" && alignment != "cn" &&
        alignment != "LE" && alignment != "NE" && alignment != "CE" &&
        alignment != "le" && alignment != "ne" && alignment != "ce")
    {
        std::string functionName = "dmgt::DmgtCharacter()";
        std::string errorMessage = "Incorrect alignment given";
        throw DmgtError(functionName, errorMessage);
    }
    gender_    = gender;
    alignment_ = alignment;
    name_      = name;
    abilities_ = DmgtAbilities();
    skills_    = DmgtSkills();
}

} // namespace dmgt

