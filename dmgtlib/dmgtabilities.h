//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Abilities Class Header
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
#ifndef DMGT_LIBRARY_DMGTABILITIES_H_
#define DMGT_LIBRARY_DMGTABILITIES_H_

//------------------------------------------------------------------------------
// Included Libraries
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cctype>
#include <algorithm>

#include "dmgterror.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
// The dmgtAbilities class is a store of the six base abilities used by a game
// character or monster. Whenever an ability score or is retrieved or modified
// within this class, an integer between 0 and 5 represents the ability as
// follows:
//   0 Strength     (STR)
//   1 Dexterity    (DEX)
//   2 Constitution (CON)
//   3 Intelligence (INT)
//   4 Wisdom       (WIS)
//   5 Charisma     (CHA)
class DmgtAbilities
{
  public:
    // Default constructor which takes no arguments and creates the six ability
    // scores. Ability scores are given by the sum of the three highest of four
    // six-sided dice. This results in a possible score between 3 and 18 for
    // each; 10 being the average.
    DmgtAbilities();
    // Constructor which creates the abilities from given scores.
    // Eg. "DmgtAbilities abilities(12, 14, 10, 16, 13, 16);" will create a list
    //     of abilities scores as follows:
    //       STR 12
    //       DEX 14
    //       CON 10
    //       INT 16
    //       WIS 13
    //       CHA 16
    DmgtAbilities(const unsigned int &strength,
                  const unsigned int &dexterity,
                  const unsigned int &constitution,
                  const unsigned int &intelligence,
                  const unsigned int &wisdom,
                  const unsigned int &charisma);
    // Deconstructor
    ~DmgtAbilities() {};
    // Reroll the ability base scores. The same method as the default
    // constructor is used.
    void reroll();
    // Return the ability score with the addition of a given modifier.
    // Eg. "abilities.score(0, -1);" will return the strength ability score
    //     minus one.
    signed int score(const unsigned int &ability, const signed int &misc_mod);
    // Return the ability modifier calculated according to the SRD 3.5 with any
    // given misc modifier. The misc modifier and base score are summed before
    // the ability modifier is made.
    // ... 8 to 9 = -1; 10 to 11 = 0; 12 to 13 = +1; 14 to 15 = +2; ...
    // Eg. "abilities.mod(0, -1);" will return the strength ability modifier
    //     with addition of a -1 to the base score.
    signed int mod(const unsigned int &ability, const signed int &misc_mod);
    // Organise the ability scores into a new order by placing the abilities in
    // order of highest to lowest.
    // Eg. "abilities.order(3, 4, 5, 0, 1, 2);" will reorder the scores so that
    //     Intelligence is the highest score and Constitution is the lowest.
    void order(const unsigned int &first_ability,
               const unsigned int &second_ability,
               const unsigned int &third_ability,
               const unsigned int &fourth_ability,
               const unsigned int &fifth_ability,
               const unsigned int &sixth_ability);
    // Add a point onto any ability score. Often a character will add a point to
    // any given ability on every fourth character level. Also a simple function
    // to give game developers the ability to add to a score.
    // Eg. "abilities.scoreUp(1);" will add a point to the Dexterity ability.
    void scoreUp(const unsigned int &ability);
    // Remove a point from any ability score. This is much like the scoreUp
    // function, giving the option to remove a point from an ability score.
    // Eg. "abilities.scoreDown(1);" will remove a point from the Dexterity
    // ability score.
    void scoreDown(const unsigned int &ability);
  private:
    std::vector<unsigned int> base_ability_scores_; // Base ability scores
};

} // namespace dmgt
#endif

