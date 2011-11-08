//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Abilities Class Source
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
#include "dmgtabilities.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
DmgtAbilities::DmgtAbilities()
{
    // Seed random table
    std::srand(std::time(NULL) * std::rand() );
    // Roll six ability scores and insert them into the abilities list
    for (int i = 0; i <= 5; ++i)
    {
        unsigned int               score   = 0; // The resulting ability score
        std::vector<unsigned int>  rolls;       // Each individual dice roll
        std::vector<unsigned int>::iterator it; // A vector iterator for later
        // Roll four six sided dice and create a list of rolls
        for (int j = 0; j <= 3; ++j)
        {
            unsigned int roll = std::rand() % 6 + 1;
            rolls.push_back(roll);
        }
        // Sort the list of rolls from highest to lowest and drop the lowest
        std::sort(rolls.rbegin(), rolls.rend() );
        rolls.pop_back();
        // Add up the three highest rolls to create the score
        for (it = rolls.begin(); it != rolls.end(); ++it)
        {
            score += *it;
        }
        // Insert the ability score into the abilities list
        base_ability_scores_.push_back(score);
    }
}

//------------------------------------------------------------------------------
DmgtAbilities::DmgtAbilities(const unsigned int &strength,
                             const unsigned int &dexterity,
                             const unsigned int &constitution,
                             const unsigned int &intelligence,
                             const unsigned int &wisdom,
                             const unsigned int &charisma)
{
    // Insert all scores into the abilities list
    base_ability_scores_.push_back(strength);
    base_ability_scores_.push_back(dexterity);
    base_ability_scores_.push_back(constitution);
    base_ability_scores_.push_back(intelligence);
    base_ability_scores_.push_back(wisdom);
    base_ability_scores_.push_back(charisma);
}

//------------------------------------------------------------------------------
void DmgtAbilities::reroll()
{
    // Seed random table
    std::srand(std::time(NULL) * std::rand() );
    // Clear the base ability scores
    base_ability_scores_.clear();
    // Roll six ability scores and insert them into the abilities list
    for (int i = 0; i <= 5; ++i)
    {
        unsigned int               score   = 0; // The resulting ability score
        std::vector<unsigned int>  rolls;       // Each individual dice roll
        std::vector<unsigned int>::iterator it; // A vector iterator for later
        // Roll four six sided dice and create a list of rolls
        for (int j = 0; j <= 3; ++j)
        {
            unsigned int roll = std::rand() % 6 + 1;
            rolls.push_back(roll);
        }
        // Sort the list of rolls from highest to lowest and drop the lowest
        std::sort(rolls.rbegin(), rolls.rend() );
        rolls.pop_back();
        // Add up the three highest rolls to create the score
        for (it = rolls.begin(); it != rolls.end(); ++it)
        {
            score += *it;
        }
        // Insert the ability score into the abilities list
        base_ability_scores_.push_back(score);
    }
}

//------------------------------------------------------------------------------
signed int DmgtAbilities::score(const unsigned int &ability,
                                const signed int   &misc_mod)
{
    // Throw error if outside range
    if (ability >= 6)
    {
        std::string functionName = "dmgt::DmgtAbilities::score()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Return a single ability score
    return base_ability_scores_[ability] + misc_mod;
}

//------------------------------------------------------------------------------
signed int DmgtAbilities::mod(const unsigned int &ability,
                              const signed int   &misc_mod)
{
    // Throw error if outside range
    if (ability >= 6)
    {
        std::string functionName = "dmgt::DmgtAbilities::mod()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Return a single ability modifier by subtracting ten from the ability
    // score, after modifiers, and dividing by two.
    signed int ability_modifier = base_ability_scores_[ability] +
                                  misc_mod - 10;
    if (ability_modifier % 2 != 0) --ability_modifier;
    ability_modifier = ability_modifier / 2;
    return ability_modifier;
}

//------------------------------------------------------------------------------
void DmgtAbilities::order(const unsigned int &first_ability,
                          const unsigned int &second_ability,
                          const unsigned int &third_ability,
                          const unsigned int &fourth_ability,
                          const unsigned int &fifth_ability,
                          const unsigned int &sixth_ability)
{
    // Throw error if outside range
    if (first_ability  >= 6 ||
        second_ability >= 6 ||
        third_ability  >= 6 ||
        fourth_ability >= 6 ||
        fifth_ability  >= 6 ||
        sixth_ability  >= 6)
    {
        std::string functionName = "dmgt::DmgtAbilities::order()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Throw error if ability used twice
    if (first_ability  == second_ability ||
        first_ability  == third_ability  ||
        first_ability  == fourth_ability ||
        first_ability  == fifth_ability  ||
        first_ability  == sixth_ability  ||
        second_ability == first_ability  ||
        second_ability == third_ability  ||
        second_ability == fourth_ability ||
        second_ability == fifth_ability  ||
        second_ability == sixth_ability  ||
        third_ability  == first_ability  ||
        third_ability  == second_ability ||
        third_ability  == fourth_ability ||
        third_ability  == fifth_ability  ||
        third_ability  == sixth_ability  ||
        fourth_ability == first_ability  ||
        fourth_ability == second_ability ||
        fourth_ability == third_ability  ||
        fourth_ability == fifth_ability  ||
        fourth_ability == sixth_ability  ||
        fifth_ability  == first_ability  ||
        fifth_ability  == second_ability ||
        fifth_ability  == third_ability  ||
        fifth_ability  == fourth_ability ||
        fifth_ability  == sixth_ability  ||
        sixth_ability  == first_ability  ||
        sixth_ability  == second_ability ||
        sixth_ability  == third_ability  ||
        sixth_ability  == fourth_ability ||
        sixth_ability  == fifth_ability)
    {
        std::string functionName = "dmgt::DmgtAbilities::order()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Copy the abilities
    std::vector<unsigned int> tempVector = base_ability_scores_;
    // Reorder the abilities as specified
    base_ability_scores_[0] = tempVector[first_ability];
    base_ability_scores_[1] = tempVector[second_ability];
    base_ability_scores_[2] = tempVector[third_ability];
    base_ability_scores_[3] = tempVector[fourth_ability];
    base_ability_scores_[4] = tempVector[fifth_ability];
    base_ability_scores_[5] = tempVector[sixth_ability];
}

//------------------------------------------------------------------------------
void DmgtAbilities::scoreUp(const unsigned int &ability)
{
    // Throw error if outside range
    if (ability >= 6)
    {
        std::string functionName = "dmgt::DmgtAbilities::scoreUp()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Add one point to given ability
    base_ability_scores_[ability] = base_ability_scores_[ability] + 1;
}

//------------------------------------------------------------------------------
void DmgtAbilities::scoreDown(const unsigned int &ability)
{
    // Throw error if outside range
    if (ability >= 6)
    {
        std::string functionName = "dmgt::DmgtAbilities::scoreDown()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Throw error if trying to go below zero
    if (base_ability_scores_[ability] == 0)
    {
        std::string functionName = "dmgt::DmgtAbilities::scoreDown()";
        std::string errorMessage = "Integer outside range (0-5).";
        throw DmgtError(functionName, errorMessage);
    }
    // Remove one point to given ability
    base_ability_scores_[ability] = base_ability_scores_[ability] - 1;
}

} // namespace dmgt

