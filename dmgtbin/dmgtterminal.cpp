//------------------------------------------------------------------------------
// Author:            Ian Whitnall
// Website URL:       http://www.riskywhiskey.com.au
// Contact eMail:     riskywhiskey@gmail.com
// Project:           Dungeon Master Geek Tools
// This File:         Terminal Class Source
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
#include "dmgtterminal.h"

//------------------------------------------------------------------------------
namespace dmgt {

//------------------------------------------------------------------------------
DmgtTerminal::DmgtTerminal(const std::string &in_symbol,
                           const std::string &out_symbol,
                           const std::string &alert_symbol,
                           const std::string &revision)
{
    in_symbol_    = in_symbol;    // Store the input symbol
    out_symbol_   = out_symbol;   // Store the output symbol
    alert_symbol_ = alert_symbol; // Store the alert symbol
    revision_     = revision;     // Store revision number
    // Input user command
    std::cout << in_symbol_;
    std::getline(std::cin, line_of_input_);
    std::stringstream input_string(line_of_input_);
    std::string       argument;
    while (input_string >> argument)
    {
        list_of_arguments_.push_back(argument);
    }
    // If no operand is supplied use NULL
    if (list_of_arguments_.size() == 0) list_of_arguments_.push_back("\0");
    // Make first argument lowercase for use as operand
    operand_ = commandOperand(list_of_arguments_[0]);
    switch (operand_)
    {
        // Quit application
        case 0:
            std::cout << out_symbol_ << "Exiting dmgt...\n";
            break;
        // Print help
        case 1:
            DmgtManual(in_symbol_, out_symbol_, revision_);
            break;
        // Quick dice roll tool
        case 2:
            if (list_of_arguments_.size() >= 2) simpleRoll();
            else std::cout << alert_symbol_ << "No D20 notation given.\n";
            break;
        // Quick dice roll tool with working
        case 3:
            if (list_of_arguments_.size() >= 2) rollWithWorking();
            else std::cout << alert_symbol_ << "No D20 notation given.\n";
            break;
        // Quick abilities tool
        case 4:
            abilities();
            break;
        // Unknown operand
        default:
            std::cout << alert_symbol_
                      << "Incorrect usage, type 'h' or 'help' for help.\n";
    }
}

//------------------------------------------------------------------------------
const int DmgtTerminal::operand()
{
    return operand_; // The operand as an integer
}

//------------------------------------------------------------------------------
int DmgtTerminal::commandOperand(std::string &operand)
{
    operand = stringToLower(operand);
    if      (operand == "q"      ||
             operand == "quit"   ||
             operand == "exit"    ) return  0; // Quit application
    else if (operand == "h"      ||
             operand == "help"   ||
             operand == "manual" ||
             operand == "man"     ) return  1; // Show manual
    else if (operand == "r"       ) return  2; // Simple dice roll
    else if (operand == "rw"      ) return  3; // Dice roll with working
    else if (operand == "a"       ) return  4; // Simple attributes roll
    else                            return 99; // Something undefined
}

//------------------------------------------------------------------------------
std::string DmgtTerminal::stringToLower(std::string &string_to_convert)
{
    //change each element of the string to lower case
    for(unsigned int i=0; i < string_to_convert.length(); ++i) {
        string_to_convert[i] = std::tolower(string_to_convert[i]);
    }
    return string_to_convert; //return the converted string
}

//------------------------------------------------------------------------------
void DmgtTerminal::abilities()
{
    DmgtAbilities abilities; // Create abilities object
    // Print ability scores
    std::cout << out_symbol_;
    for (int i = 0; i != 6; ++i)
    {
        std::cout.width(2);
        std::cout << std::right << abilities.score(i, 0);
        if (i <= 4) std::cout << " ";
    }
    std::cout << "\n";
    // Print ability modifiers
    std::cout << out_symbol_;
    for (int i = 0; i != 6; ++i)
    {
        std::cout.width(2);
        std::cout << std::right << std::showpos << abilities.mod(i, 0)
                  << std::noshowpos;
        if (i <= 4) std::cout << " ";
    }
    std::cout << "\n";
}

//------------------------------------------------------------------------------
void DmgtTerminal::simpleRoll()
{
    // Roll each given notation
    for (unsigned long i = 1; i != list_of_arguments_.size(); ++i)
    {
        // Create dice roll and print the result
        try
        {
            DmgtDice current_roll(list_of_arguments_[i]);
            std::cout << out_symbol_ << current_roll.result() << "\n";
        }
        // Alert the user if notation is incorrect
        catch (DmgtError)
        {
            std::cout << alert_symbol_ << "Incorrect D20 notation in roll "
                      << i << ".\n";
        }
    }
}

//------------------------------------------------------------------------------
void DmgtTerminal::rollWithWorking()
{
    // Roll each given notation
    for (unsigned long i = 1; i != list_of_arguments_.size(); ++i)
    {
        // Create dice roll and print all working and the result
        try
        {
            DmgtDice current_roll(list_of_arguments_[i]);
            for (long j = 0; j != current_roll.size(); ++j)
            {
                std::cout << out_symbol_;
                // Print roll symbol if not the first
                if (current_roll.rollSymbol(j) != '0')
                {
                    std::cout << current_roll.rollSymbol(j);
                }
                // Print all the individual rolls
                std::cout << current_roll.notation(j, j) << " (";
                for (long k = 0; k != current_roll.numberOfRolls(j); ++k)
                {
                    std::cout << current_roll.roll(j, k);
                    if (k < current_roll.numberOfRolls(j) - 1)
                    {
                        std::cout << ", ";
                    }
                }
                std::cout << ") = ";
                // Print the result of this part of the notation
                if (current_roll.rollSymbol(j) == '-')
                {
                    std::cout << "-";
                }
                std::cout << current_roll.result(j, j) << "\n";
            }
            // Print final result
            std::cout << out_symbol_ << "Total = " << current_roll.result()
                      << "\n";
        }
        // Alert the user if notation is incorrect
        catch (DmgtError)
        {
            std::cout << alert_symbol_ << "Incorrect D20 notation in roll "
                      << i << ".\n";
        }
    }
}

} // namespace dmgt

