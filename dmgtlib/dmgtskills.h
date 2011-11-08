//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Skill List Class Header
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
#ifndef DMGT_LIBRARY_DMGTSKILLS_H_
#define DMGT_LIBRARY_DMGTSKILLS_H_

//------------------------------------------------------------------------------
// Included Libraries
#include <map>
#include <string>
#include <sstream>
#include <vector>

#include "dmgterror.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
// The list of skills used by a game character or monster. The initial list
// consists of 51 default skills and can be expanded to accommodate more. Each
// skill also lists the appropriate corresponding ability in the form of a int
// relating easily to the abilities class (DmgtAblts).
// Default skills are as follows:
//    0 Apraise
//    1 Balance
//    2 Bluff
//    3 Climb
//    4 Concentration
//    5 Craft
//    6 Decipher Script
//    7 Diplomacy
//    8 Disable Device
//    9 Disguise
//   10 Escape Artist
//   11 Forgery
//   12 Gather Information
//   13 Handle Animal
//   14 Heal
//   15 Hide
//   16 Imtimidate
//   17 Jump
//   18 Knowledge (Arcana)
//   19 Knowledge (Architecture and Engineering)
//   20 Knowledge (Dungeoneering)
//   21 Knowledge (Geography)
//   22 Knowledge (History)
//   23 Knowledge (Local)
//   24 Knowledge (Nature)
//   25 Knowledge (Nobility and Royalty)
//   26 Knowledge (Religion)
//   27 Knowledge (The Planes)
//   28 Listen
//   29 Move Silently
//   30 Open Lock
//   31 Perform (Act)
//   32 Perform (Comedy)
//   33 Perform (Dance)
//   34 Perform (Keyboard)
//   35 Perform (Oractory)
//   36 Perform (String Instruments)
//   37 Perform (Wind Instruments)
//   38 Perform (Sing)
//   39 Profession
//   40 Ride
//   41 Search
//   42 Sense Motive
//   43 Sleight of Hand
//   44 Spellcraft
//   45 Spot
//   46 Survival
//   47 Swim
//   48 Tumble
//   49 Use Magic Device
//   50 Use Rope
class DmgtSkills
{
  public:
    // Default constructor which takes no arguments and produces the initial
    // list of 51 skills used by a game character or monster with a rank and
    // misc mod of 0 each.
    DmgtSkills();
    // Default destructor
    ~DmgtSkills() {};
    // Retrieve the rank of a skill by name represented by an interger.
    // Eg. "skills.rank(1);" will return the rank for the skill Balance
    //     in the form of an integer.
    unsigned int rank(const unsigned int &skill);
    // Retrieve the corresponding ability to a skill by name represented as a
    // string.
    // Eg. "skills.ability(1);" which is balance will return the integer '1'
    //     specifying the ability Dexterity
    unsigned int ability(const unsigned int &skill);
    // Add skill points to be spent. The amount given will be added to the
    // already existing unspent points.
    // Eg. "skills.addPoints(1);" will add one skill unspent point.
    void addPoints(const unsigned int &points);
    // Add a rank to the given skill according to rules if it is a class rank or
    // cross-class rank. A boolean argument of true will note the skill as a
    // class skill and a false will note the skill as a cross-class skill where
    // only half a point will be spent. Points are recorded.
    // Eg. "skills.addRank(1, true);" will add a full rank to the skill balance
    //     as it is given as a class skill.
    void addRank(const unsigned int &skill, const bool &class_skill);
    // Remove ranks from skills much like the above function adds ranks. This
    // gives the option to remove ranks to the developer.
    // Eg. "skills.removeRank(1, true);" will remove a full rank from the skill
    //     balance as it is given as a class skill.
    void removeRank(const unsigned int &skill, const bool &class_skill);
    // Clear all skill data. Including ranks, half ranks, spent and unspent
    // points. All will be returned to 0.
    void clear();
    // Clear just the ranks. All spent points will return to unspent points
    // leaving the total of points for the character.
    void clearRanks();
  private:
    std::vector<std::string>            skills_;      // List of skills
    std::vector<unsigned int>           key_ablts_;   // Key abilities for each
    std::vector<unsigned int>           ranks_;       // The ranks in each
    std::vector<bool>                   half_ranks_;  // Current half ranks
    unsigned int                        spent_pts_;   // Spent points amount
    unsigned int                        unspent_pts_; // Unspent points amount
};

} // namespace dmgt
#endif

