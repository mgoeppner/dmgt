//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Dice Class Header
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
#ifndef DMGT_LIBRARY_DMGTDICE_H_
#define DMGT_LIBRARY_DMGTDICE_H_

//------------------------------------------------------------------------------
// Included Libraries
#include <ctime>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>

#include "dmgterror.h"

//------------------------------------------------------------------------------
// Begin Namespace
namespace dmgt {

//------------------------------------------------------------------------------
// A dice class which creates and stores realistic virtual dice rolls. It
// records all input as a dice roll (either as D20 notation or integers),
// generates each dice roll and records the total results of the over roll.
// Each roll, notation and result can be retrieved from the class as well as
// the overall notation and result. A dice roll and a modifier are treated in
// the same way within the object, eg. 1d20+3 counts as two rolls; 1d20 and
// then add the 3. When reading the notation it is treated as a roll, then an
// operator and then the next roll etc.
class DmgtDice
{
  public:
    // The default constructor which will take an amount of dice and the number
    // of sides on the specified dice. The default value is one six-sided die.
    DmgtDice(const unsigned long &amount = 1, const unsigned long &sides = 6);
    // Constructor which takes proper D20 notation. The notation is checked if
    // it is correctly written and will throw an error if incorrect
    DmgtDice(const std::string &notation);
    // Destructor
    ~DmgtDice() {};
    // Operators, in the case the dice class is needed to be added to or
    // subtracted from either another dice value or integer.
    DmgtDice&      operator=  (const DmgtDice &other_dice);
    DmgtDice&      operator+= (const DmgtDice &other_dice);
    DmgtDice&      operator+= (const long     &number_to_add);
    DmgtDice&      operator-= (const DmgtDice &other_dice);
    DmgtDice&      operator-= (const long     &number_to_subtract);
    const DmgtDice operator+  (const DmgtDice &other_dice) const;
    const DmgtDice operator+  (const long     &number_to_add) const;
    const DmgtDice operator-  (const DmgtDice &other_dice) const;
    const DmgtDice operator-  (const long     &number_to_subtract) const;
    // Return the numeric result. The specified result can be returned by using
    // an ineger specifying the start and end of the roll to include in the
    // result. The default value returns the result of the entire set of rolls.
    // Eg. "roll.result(0, 3);" will return the overall value of the first
    //     four rolls. If the values for each result contained where 14, 5, 10,
    //     13, 17 and 9, the result returned would be 32 (14+5+10+13).
    //     "roll.result();" would return 58.
    long result();
    long result(const unsigned long &start, const unsigned long &end);
    // Return the notation of stored rolls as a single string. The notation is
    // returned by specifying the start and end as an integer. The default
    // value returns the entire notation for the set of rolls.
    // Eg. "roll.notation(1, 2);" will return the second and third stored
    //     notations. If the full notation stored was "1d20+1d6+4d4-5", the
    //     returned string would be "1d6+4d4". "roll.notation();" would return
    //     "1d20+1d6+4d4-5".
    std::string notation();
    std::string notation(const unsigned long &start, const unsigned long &end);
    // Return an individual roll. The first integer represents the notation in
    // the object while the second is the roll it self.
    // Eg. "roll.roll(1, 3);" will return the fourth roll of the second
    //     notation. Which could be 4 if the second roll in the object was 4d6
    //     with 3, 2, 5 and 4 as rolls.
    long roll(const unsigned long &notation, const unsigned long &roll);
    // Return the length of the history within the object.
    // Eg. "roll.size();" will return 2 if the object contains a roll of
    //     "1d20+3"; 1d20 '+' 3.
    long size();
    // Return the amount of rolls that took place within a notation. An integer
    // represents which notation.
    // Eg. "roll.nmuberOfRolls(1);" will return the amount of rolls from the
    //     second notation in the record. 1 would be the return from the
    //     notation "+3", while 4 would be the return from the notation "4d6".
    long numberOfRolls(const unsigned long &notation);
    // Return the operator character which belongs to the notation. The return
    // for the first notation is a '0' as it does not link to any previous
    // notations.
    // Eg. "roll.rollSymbol(1);" will return the symbol for the second notation
    //     which links it to the last notation, '+' in the the case of "2d4+2".
    char rollSymbol(const unsigned long &notation);
  private:
    std::vector<std::vector<long> > dice_rolls_;     // Each induvidual roll
    std::vector<std::string>        roll_notations_; // Notation for each roll
    std::vector<long>               roll_results_;   // Each result
    std::vector<char>               roll_operators_; // Operators between rolls
    // A function used to test D20 notation when entered into the object.
    bool diceNotation(const std::string &notation);
};

} // namespace dmgt
#endif

