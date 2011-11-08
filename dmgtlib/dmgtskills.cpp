//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Skills List Class Source
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
#include "dmgtskills.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
DmgtSkills::DmgtSkills()
{
    // Insert all 51 default skills into new list with no ranks or modifiers
    skills_.push_back("Apraise");
    key_ablts_.push_back(3);
    skills_.push_back("Balance");
    key_ablts_.push_back(1);
    skills_.push_back("Bluff");
    key_ablts_.push_back(5);
    skills_.push_back("Climb");
    key_ablts_.push_back(0);
    skills_.push_back("Concentration");
    key_ablts_.push_back(2);
    skills_.push_back("Craft");
    key_ablts_.push_back(3);
    skills_.push_back("Decipher Script");
    key_ablts_.push_back(3);
    skills_.push_back("Diplomacy");
    key_ablts_.push_back(5);
    skills_.push_back("Disable Device");
    key_ablts_.push_back(3);
    skills_.push_back("Disguise");
    key_ablts_.push_back(5);
    skills_.push_back("Escape Artist");
    key_ablts_.push_back(1);
    skills_.push_back("Forgery");
    key_ablts_.push_back(3);
    skills_.push_back("Gather Information");
    key_ablts_.push_back(5);
    skills_.push_back("Handle Animal");
    key_ablts_.push_back(5);
    skills_.push_back("Heal");
    key_ablts_.push_back(4);
    skills_.push_back("Hide");
    key_ablts_.push_back(1);
    skills_.push_back("Imtimidate");
    key_ablts_.push_back(5);
    skills_.push_back("Jump");
    key_ablts_.push_back(0);
    skills_.push_back("Knowledge (Arcana)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Architecture and Engineering)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Dungeoneering)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Geography)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (History)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Local)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Nature)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Nobility and Royalty)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (Religion)");
    key_ablts_.push_back(3);
    skills_.push_back("Knowledge (The Planes)");
    key_ablts_.push_back(3);
    skills_.push_back("Listen");
    key_ablts_.push_back(4);
    skills_.push_back("Move Silently");
    key_ablts_.push_back(1);
    skills_.push_back("Open Lock");
    key_ablts_.push_back(1);
    skills_.push_back("Perform (Act)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (Comedy)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (Dance)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (Keyboard)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (Oractory)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (String Instruments)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (Wind Instruments)");
    key_ablts_.push_back(5);
    skills_.push_back("Perform (Sing)");
    key_ablts_.push_back(5);
    skills_.push_back("Profession");
    key_ablts_.push_back(5);
    skills_.push_back("Ride");
    key_ablts_.push_back(1);
    skills_.push_back("Search");
    key_ablts_.push_back(3);
    skills_.push_back("Sense Motive");
    key_ablts_.push_back(4);
    skills_.push_back("Sleight of Hand");
    key_ablts_.push_back(1);
    skills_.push_back("Spellcraft");
    key_ablts_.push_back(1);
    skills_.push_back("Spot");
    key_ablts_.push_back(4);
    skills_.push_back("Survival");
    key_ablts_.push_back(4);
    skills_.push_back("Swim");
    key_ablts_.push_back(0);
    skills_.push_back("Tumble");
    key_ablts_.push_back(1);
    skills_.push_back("Use Magic Device");
    key_ablts_.push_back(5);
    skills_.push_back("Use Rope");
    key_ablts_.push_back(1);
    // All ranks start at 0
    for (int i = 0; i != 50; ++i)
    {
       ranks_.push_back(0);
       half_ranks_.push_back(false);
    }
    // Initiate point records
    spent_pts_   = 0;
    unspent_pts_ = 0;
}

//------------------------------------------------------------------------------
unsigned int DmgtSkills::rank(const unsigned int &skill)
{
    // Throw error if skill not found
    unsigned int highest = skills_.size();
    if (skill > highest)
    {
        std::stringstream highestStr;
        highestStr << highest;
        std::string functionName = "dmgt::DmgtSkills::rank()";
        std::string errorMessage = "Skill not found (0-";
        errorMessage            += highestStr.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    return ranks_[skill]; // Return skill rank
}

//------------------------------------------------------------------------------
unsigned int DmgtSkills::ability(const unsigned int &skill)
{
    // Throw error if skill not found
    unsigned int highest = skills_.size();
    if (skill > highest)
    {
        std::stringstream highestStr;
        highestStr << highest;
        std::string functionName = "dmgt::DmgtSkills::ability()";
        std::string errorMessage = "Skill not found (0-";
        errorMessage            += highestStr.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    return key_ablts_[skill]; // Return skill base ability
}

//------------------------------------------------------------------------------
void DmgtSkills::addPoints(const unsigned int &points)
{
    // Add given amount of points
    unspent_pts_ = unspent_pts_ + points;
}

//------------------------------------------------------------------------------
void DmgtSkills::addRank(const unsigned int &skill, const bool &class_skill)
{
    // Throw error if points have been spent
    if (unspent_pts_ == 0)
    {
        std::string functionName = "dmgt::DmgtSkills::addRank()";
        std::string errorMessage = "All points used.";
        throw DmgtError(functionName, errorMessage);
    }
    // Throw error if skill not found
    unsigned int highest = skills_.size();
    if (skill > highest)
    {
        std::stringstream highestStr;
        highestStr << highest;
        std::string functionName = "dmgt::DmgtSkills::addRank()";
        std::string errorMessage = "Skill not found (0-";
        errorMessage            += highestStr.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    // Raise rank by one for class skill
    if (class_skill)
    {
        ++ranks_[skill];
        ++spent_pts_;
        --unspent_pts_;
    }
    // Raise rank by half for cross-class skill
    else
    {
        if (half_ranks_[skill])
        {
            half_ranks_[skill] = false;
            ++ranks_[skill];
            ++spent_pts_;
            --unspent_pts_;
        }
        else
        {
            half_ranks_[skill] = true;
            ++spent_pts_;
            --unspent_pts_;
        }
    }
}

//------------------------------------------------------------------------------
void DmgtSkills::removeRank(const unsigned int &skill, const bool &class_skill)
{
    // Throw error if skill not found
    unsigned int highest = skills_.size();
    if (skill > highest)
    {
        std::stringstream highestStr;
        highestStr << highest;
        std::string functionName = "dmgt::DmgtSkills::removeRank()";
        std::string errorMessage = "Skill not found (0-";
        errorMessage            += highestStr.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    // Lower rank by one for class skill
    if (class_skill)
    {
        // Throw error if trying to go below zero
        if (ranks_[skill] == 0)
        {
            std::string functionName = "dmgt::DmgtSkills::removeRank()";
            std::string errorMessage = "Ranks already at zero.";
            throw DmgtError(functionName, errorMessage);
        }
        else
        {
            --ranks_[skill];
            --spent_pts_;
            ++unspent_pts_;
        }
    }
    // Lower rank by half for cross-class skill
    else
    {
        if (half_ranks_[skill])
        {
            half_ranks_[skill] = false;
            --spent_pts_;
            ++unspent_pts_;
        }
        else
        {
            // Thow error if trying to go below zero
            if (ranks_[skill] == 0)
            {
                std::string functionName = "dmgt::DmgtSkills::removeRank()";
                std::string errorMessage = "Ranks already at zero.";
                throw DmgtError(functionName, errorMessage);
            }
            else
            {
                half_ranks_[skill] = true;
                --ranks_[skill];
                --spent_pts_;
                ++unspent_pts_;
            }
        }
    }
}

//------------------------------------------------------------------------------
void DmgtSkills::clear()
{
    // Return everything to zero
    for (unsigned int i = 0; i != skills_.size(); ++i)
    {
        ranks_[i] = 0;
    }
    for (unsigned int i = 0; i != skills_.size(); ++i)
    {
        half_ranks_[i] = false;
    }
    spent_pts_   = 0;
    unspent_pts_ = 0;
}

//------------------------------------------------------------------------------
void DmgtSkills::clearRanks()
{
    // Return ranks to zero
    for (unsigned int i = 0; i != skills_.size(); ++i)
    {
        ranks_[i] = 0;
    }
    for (unsigned int i = 0; i != skills_.size(); ++i)
    {
        half_ranks_[i] = false;
    }
    // Make spent points unspent
    unspent_pts_ = unspent_pts_ + spent_pts_;
    spent_pts_   = 0;
}

} // namespace dmgt

