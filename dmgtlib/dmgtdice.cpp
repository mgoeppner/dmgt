//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Dice Class Source
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
#include "dmgtdice.h"

//------------------------------------------------------------------------------
// Begin Namespace
namespace dmgt {

//------------------------------------------------------------------------------
DmgtDice::DmgtDice(const unsigned long &amount, const unsigned long &sides)
{
    std::srand(std::time(NULL) * std::rand() ); // Seed random table
    char              modifier_operand =   '0'; // Initiate add as naught
    long              overall_result   =    0 ; // Result of dice roll
    long              single_roll      =    0 ; // Temporary int for each roll
    std::vector<long> vector_of_rolls;          // Temporary vector for rolls
    std::stringstream string_of_notation;       // Stream to create notation
    // Create individual rolls
    for (unsigned long i = 0; i != amount; ++i)
    {
        single_roll = std::rand() % sides + 1;
        overall_result += single_roll;
        vector_of_rolls.push_back(single_roll);
    }
    // Create notation
    string_of_notation << amount << "d" << sides;
    // Create and store class information
    roll_notations_.push_back(string_of_notation.str() );
    dice_rolls_.push_back(vector_of_rolls);
    roll_results_.push_back(overall_result);
    roll_operators_.push_back(modifier_operand);
}

//------------------------------------------------------------------------------
DmgtDice::DmgtDice(const std::string &notation)
{
    std::srand(std::time(NULL) * std::rand() );  // Seed random table
    char              modifier_operand =    '0'; // Initiate add as '0'
    long              roll_result      =     0 ; // Result of dice roll
    long              each_roll        =     0 ; // Temp int for each roll
    long              track_roll       =     0 ; // Keep track of rolls
    long              temporary_int    =     0 ; // Temporary integer
    char              temporary_char   =    'a'; // Temporary character
    std::vector<long> vector_of_rolls;           // Temporary vector for rolls
    std::vector<long> vector_of_ints;            // Vector of integers
    std::vector<char> vector_of_chars;           // Vector of characters
    std::stringstream notation_stream(notation); // Turn notation into a stream
    std::stringstream new_notation_stream;       // Stream for new notation
    std::vector<char>::iterator iterator_char;   // Vector iterator
    // Test notation before going any further
    if (diceNotation(notation) )
    {
        // As long as there is an input
        while (!notation_stream.eof() )
        {
            notation_stream >> temporary_int;          // Bring in an integer
            vector_of_ints.push_back(temporary_int);   // Push vector of ints
            if (notation_stream.eof() ) break;         // Break loop if at end
            notation_stream >> temporary_char;         // Bring in an character
            vector_of_chars.push_back(temporary_char); // Push vector of chars
        }
        // Run through all the notation
        for (iterator_char =  vector_of_chars.begin();
             iterator_char != vector_of_chars.end();
             ++iterator_char)
        {
            // If the character is a 'd'
            if (vector_of_chars[track_roll] == 'd')
            {
                // Create individual rolls
                for (long i = 0; i != vector_of_ints[track_roll]; ++i)
                {
                    each_roll = std::rand() % vector_of_ints[track_roll+1] + 1;
                    roll_result += each_roll;
                    vector_of_rolls.push_back(each_roll);
                }
                // Create notation
                new_notation_stream << vector_of_ints[track_roll]
                                    << "d"
                                    << vector_of_ints[track_roll+1];
                // Create and store class information
                roll_notations_.push_back(new_notation_stream.str() );
                dice_rolls_.push_back(vector_of_rolls);
                roll_results_.push_back(roll_result);
                roll_operators_.push_back(modifier_operand);
                // Clear reused variables
                roll_result = 0;
                vector_of_rolls.clear();
                new_notation_stream.str("");
                new_notation_stream.clear();
            }
            // If character is a '+'
            else if (vector_of_chars[track_roll] == '+')
            {
                // If adding a roll
                if (vector_of_chars[track_roll+1] == 'd' && track_roll >= 1)
                {
                    modifier_operand = '+'; // The operator for the next roll
                }
                // If adding a number to a roll
                else if (track_roll == 0)
                {
                    // The current integer
                    roll_result = vector_of_ints[track_roll];
                    // Create notation
                    new_notation_stream << vector_of_ints[track_roll];
                    // Create and store class information
                    vector_of_rolls.push_back(roll_result);
                    roll_notations_.push_back(new_notation_stream.str() );
                    dice_rolls_.push_back(vector_of_rolls);
                    roll_results_.push_back(roll_result);
                    roll_operators_.push_back(modifier_operand);
                    modifier_operand = '+';
                    // Clear reused variables
                    roll_result = 0;
                    vector_of_rolls.clear();
                    new_notation_stream.str("");
                    new_notation_stream.clear();
                }
                // If adding a single number
                else
                {
                    // The operator
                    modifier_operand = '+';
                    // The current integer
                    roll_result = vector_of_ints[track_roll+1];
                    // Create notation
                    new_notation_stream << vector_of_ints[track_roll+1];
                    // Create and store class information
                    vector_of_rolls.push_back(roll_result);
                    roll_notations_.push_back(new_notation_stream.str() );
                    dice_rolls_.push_back(vector_of_rolls);
                    roll_results_.push_back(roll_result);
                    roll_operators_.push_back(modifier_operand);
                    // Clear reused variables
                    roll_result = 0;
                    vector_of_rolls.clear();
                    new_notation_stream.str("");
                    new_notation_stream.clear();
                }
            }
            // If character is a '-'
            else if (vector_of_chars[track_roll] == '-')
            {
                // If subtracting a roll
                if (vector_of_chars[track_roll+1] == 'd' && track_roll >= 1)
                {
                    modifier_operand = '-'; // The operator for the next roll
                }
                // If subtracting a number from a roll
                else if (track_roll == 0)
                {
                    // Current integer
                    roll_result = vector_of_ints[track_roll];
                    // Create notation
                    new_notation_stream << vector_of_ints[track_roll];
                    // Create and store class information
                    vector_of_rolls.push_back(roll_result);
                    roll_notations_.push_back(new_notation_stream.str() );
                    dice_rolls_.push_back(vector_of_rolls);
                    roll_results_.push_back(roll_result);
                    roll_operators_.push_back(modifier_operand);
                    modifier_operand = '-';
                    // Clear reused variables
                    roll_result = 0;
                    vector_of_rolls.clear();
                    new_notation_stream.str("");
                    new_notation_stream.clear();
                }
                // If subtracting a single number
                else
                {
                    // The operator
                    modifier_operand = '-';
                    // Current integer
                    roll_result = vector_of_ints[track_roll+1];
                    // Create notation
                    new_notation_stream << vector_of_ints[track_roll+1];
                    // Create and store class information
                    vector_of_rolls.push_back(roll_result);
                    roll_notations_.push_back(new_notation_stream.str() );
                    dice_rolls_.push_back(vector_of_rolls);
                    roll_results_.push_back(roll_result);
                    roll_operators_.push_back(modifier_operand);
                    // Clear reused variables
                    roll_result = 0;
                    vector_of_rolls.clear();
                    new_notation_stream.str("");
                    new_notation_stream.clear();
                }
            }
            ++track_roll; // Keep track of notation
        }
    }
    // Broken notation create default roll
    else
    {
        // Throw error in the case of bad notation
        std::string functionName = "dmgt::DmgtDice()";
        std::string errorMessage = "Incorrect D20 notation used.";
        throw DmgtError(functionName, errorMessage);
    }
}

//------------------------------------------------------------------------------
DmgtDice& DmgtDice::operator= (const DmgtDice &other_dice)
{
    // Drop all current data
    roll_notations_.clear();
    dice_rolls_.clear();
    roll_results_.clear();
    roll_operators_.clear();
    // Assign new data from other dice roll to this dice roll
    roll_notations_ = other_dice.roll_notations_;
    dice_rolls_     = other_dice.dice_rolls_;
    roll_results_   = other_dice.roll_results_;
    roll_operators_ = other_dice.roll_operators_;
    // Return new modified dice roll
    return *this;
}

//------------------------------------------------------------------------------
DmgtDice& DmgtDice::operator+= (const DmgtDice &other_dice)
{
    long size = other_dice.roll_notations_.size(); // The size of other roll
    // Add other roll's data to this roll's data
    for (long i = 0; i != size; ++i)
    {
        if (other_dice.roll_operators_[i] == '0')
        {
            roll_operators_.push_back('+');
        }
        else
        {
            roll_operators_.push_back(other_dice.roll_operators_[i]);
        }
        roll_notations_.push_back(other_dice.roll_notations_[i]);
        dice_rolls_.push_back(other_dice.dice_rolls_[i]);
        roll_results_.push_back(other_dice.roll_results_[i]);
    }
    // Return new modified dice roll
    return *this;
}

//------------------------------------------------------------------------------
DmgtDice& DmgtDice::operator+= (const long &number_to_add)
{
    std::stringstream notation_stream;        // Stream for notation
    std::vector<long> vector_of_rolls;        // Vector for passing rolls
    notation_stream << number_to_add;         // Create notation
    vector_of_rolls.push_back(number_to_add); // Create rolls
    // Create and store data for dice roll
    roll_operators_.push_back('+');
    roll_notations_.push_back(notation_stream.str() );
    dice_rolls_.push_back(vector_of_rolls);
    roll_results_.push_back(number_to_add);
    // Return new modified dice roll
    return *this;
}

//------------------------------------------------------------------------------
DmgtDice& DmgtDice::operator-= (const DmgtDice &other_dice)
{
    long size = other_dice.roll_notations_.size(); // The size of other roll
    // Add other roll's data to this roll's data
    for (long i = 0; i != size; ++i)
    {
        if (other_dice.roll_operators_[i] == '0')
        {
            roll_operators_.push_back('-');
        }
        else
        {
            roll_operators_.push_back(other_dice.roll_operators_[i]);
        }
        roll_notations_.push_back(other_dice.roll_notations_[i]);
        dice_rolls_.push_back(other_dice.dice_rolls_[i]);
        roll_results_.push_back(other_dice.roll_results_[i]);
    }
    // Return new modified dice roll
    return *this;
}

//------------------------------------------------------------------------------
DmgtDice& DmgtDice::operator-= (const long &number_to_subtract)
{
    std::stringstream notation_stream;             // Stream for notation
    std::vector<long> vector_of_rolls;             // Vector for passing rolls
    notation_stream << number_to_subtract;         // Create notation
    vector_of_rolls.push_back(number_to_subtract); // Create rolls
    // Create and store data for dice roll
    roll_operators_.push_back('-');
    roll_notations_.push_back(notation_stream.str() );
    dice_rolls_.push_back(vector_of_rolls);
    roll_results_.push_back(number_to_subtract);
    // Return new modified dice roll
    return *this;
}

//------------------------------------------------------------------------------
const DmgtDice DmgtDice::operator+ (const DmgtDice &other_dice) const
{
    DmgtDice copy_to_return = *this; // Create copy of dice roll
    copy_to_return += other_dice;    // Add copy to other dice roll
    return copy_to_return;           // Return new modified copy of dice roll
}

//------------------------------------------------------------------------------
const DmgtDice DmgtDice::operator+ (const long &number_to_add) const
{
    DmgtDice copy_to_return = *this; // Create copy of dice roll
    copy_to_return += number_to_add; // Add single number to copy
    return copy_to_return;           // Return new modified copy of dice roll
}

//------------------------------------------------------------------------------
const DmgtDice DmgtDice::operator- (const DmgtDice &other_dice) const
{
    DmgtDice copy_to_return = *this; // Create copy of dice roll
    copy_to_return -= other_dice;    // Subtract copy to other dice roll
    return copy_to_return;           // Return new modified copy of dice roll
}

//------------------------------------------------------------------------------
const DmgtDice DmgtDice::operator- (const long &number_to_subtract) const
{
    DmgtDice copy_to_return = *this;      // Create copy of dice roll
    copy_to_return -= number_to_subtract; // Subtract single number from copy
    return copy_to_return;                // Retrun new modified copy of roll
}

//------------------------------------------------------------------------------
long DmgtDice::result()
{
    long result = 0; // The result to later be returned
    // Add up all results specified
    for (unsigned long i = 0; i != roll_notations_.size(); ++i)
    {
        if (i != 0 && roll_operators_[i] == '-') result -= roll_results_[i];
        else                                     result += roll_results_[i];
    }
    return result; // Return complete result
}

//------------------------------------------------------------------------------
long DmgtDice::result(const unsigned long &start, const unsigned long &end)
{
    long result = 0; // The result to later be returned
    // The highest possible integer
    unsigned long highest = roll_notations_.size();
    // Throw error if data is outside range
    if (start > highest || end > highest)
    {
        std::stringstream highestStr;
        highestStr << highest;
        std::string functionName = "dmgt::DmgtDice::result()";
        std::string errorMessage = "Integers outside range (0-";
        errorMessage            += highestStr.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    // Add up all results specified
    for (unsigned long i = start; i != end + 1; ++i)
    {
        if (i != start && roll_operators_[i] == '-') result -= roll_results_[i];
        else                                         result += roll_results_[i];
    }
    return result; // Return complete result
}

//------------------------------------------------------------------------------
std::string DmgtDice::notation()
{
    std::stringstream notation_stream; // Stream used to create notation
    // Create notation of rolls specified
    for (unsigned long i = 0; i != roll_notations_.size(); ++i)
    {
        if (i != 0) notation_stream << roll_operators_[i];
        notation_stream << roll_notations_[i];
    }
    return notation_stream.str(); // Return notation
}

//------------------------------------------------------------------------------
std::string DmgtDice::notation(const unsigned long &start,
                               const unsigned long &end)
{
    std::stringstream notation_stream; // Stream used to create notation
    // The highest possible integer
    unsigned long highest = roll_notations_.size();
    // Throw error if data is outside range
    if (start > roll_notations_.size() || end > highest)
    {
        std::stringstream highestStr;
        highestStr << highest;
        std::string functionName = "dmgt::DmgtDice::notation()";
        std::string errorMessage = "Integer outside range (";
        errorMessage            += highestStr.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    // Create notation of rolls specified
    for (unsigned long i = start; i != end + 1; ++i)
    {
        if (i != start) notation_stream << roll_operators_[i];
        notation_stream << roll_notations_[i];
    }
    return notation_stream.str(); // Return notation
}

//------------------------------------------------------------------------------
long DmgtDice::roll(const unsigned long &notation, const unsigned long &roll)
{
    // The highest possible integers
    unsigned long highest0 = roll_notations_.size();
    unsigned long highest1 = dice_rolls_[notation].size();
    // Throw error if data outside range
    if (notation > highest0)
    {
        std::stringstream highestStr0;
        highestStr0 << highest0;
        std::string functionName = "dmgt::DmgtDice::roll()";
        std::string errorMessage = "First integer outside range (0-";
        errorMessage            += highestStr0.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    // Throw error if data outside range
    if (roll > highest1)
    {
        std::stringstream highestStr1;
        highestStr1 << highest1;
        std::string functionName = "dmgt::DmgtDice::roll()";
        std::string errorMessage = "First integer outside range (0-";
        errorMessage            += highestStr1.str();
        errorMessage            += ").";
        throw DmgtError(functionName, errorMessage);
    }
    // Return the roll
    return dice_rolls_[notation][roll];
}

//------------------------------------------------------------------------------
long DmgtDice::size()
{
    return roll_notations_.size(); // Return the length of the vector
}

//------------------------------------------------------------------------------
long DmgtDice::numberOfRolls(const unsigned long &notation)
{
    return dice_rolls_[notation].size(); // Return the number of rolls
}

//------------------------------------------------------------------------------
char DmgtDice::rollSymbol(const unsigned long &notation)
{
    return roll_operators_[notation]; // Return the operator
}

//------------------------------------------------------------------------------
bool DmgtDice::diceNotation(const std::string &notation)
{
    bool testOne   = false; // Test for 'd', '+' or '-'
    bool testTwo   = false; // Test if there is a '+' or '-' between 'd's
    bool testThree = false; // Test that there were characters
    // Go through all notation
    for (unsigned long i = 0; i < notation.length(); ++i)
    {
        // Test if alphbetic character
        if (std::isalpha(notation[i]) )
        {
            if (testOne) return false;
            if (testTwo) return false;
            if (notation[i] == 'd' || notation[i] == 'D')
            {
                if (i == 0) return false;
                testOne   = true;
                testTwo   = true;
                testThree = true;
            }
            else
            {
                return false;
            }
        }
        // Test if punctuation
        else if (std::ispunct(notation[i]) )
        {
            if (testOne) return false;
            if (notation[i] == '+' || notation[i] == '-')
            {
                if (i == 0) return false;
                testOne   = true;
                testTwo   = false;
                testThree = true;
            }
            else
            {
                return false;
            }
        }
        // Reset test if digit is found
        else if (std::isdigit(notation[i]) )
        {
            testOne = false;
        }
        // In case something funky happens
        else
        {
            return false;
        }
    }
    if (!testThree) return false;
    return true; // Return true if notation is correct
}

} // namespace dmgt

