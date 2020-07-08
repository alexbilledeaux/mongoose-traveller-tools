// Mongoose Traveller Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <array>
#include "Tools.h"
#include "WorldCreation.h"

void OutputHelpText()
{
    const int command_col_width = 20;
    const int effect_col_width = 60;

    std::cout << "Welcome to Mongoose Traveller RPG tools!\n"
        "You can use this program to help you create procedurally generated content for the Mongoose Traveller tabletop RPG (1st Edition) found here: https://www.mongoosepublishing.com/rpgs/1st-edition-traveller.html. \n\n"
        "-------------------------------------\n"
        "COMMAND LIST\n"
        "-------------------------------------\n";
    std::cout << std::left << std::setw(command_col_width) << "command" << std::setw(effect_col_width) << "effect" << std::endl;
    std::cout << std::left << std::setw(command_col_width) << "'planet'" << std::setw(effect_col_width) << "randomly generate a planet." << std::endl;
    std::cout << std::left << std::setw(command_col_width) << "'help'" << std::setw(effect_col_width) << "see this menu again." << std::endl;
}

int main()
try
{
    std::string input_stream;
    srand(std::time(0));

    OutputHelpText();
    std::cout << "\nCommand: ";
    while (std::cin >> input_stream)
    {
        if (input_stream == "planet")
        {
            WorldCreation::Planet p = WorldCreation::Planet();
            std::cout << p;
        }
        else if (input_stream == "help")
        {
            OutputHelpText();
        }
        else
        {
            std::cout << "Sorry, I don't know what to do with that command. Please type 'help' to see your options.\n";
        }
        
        std::cout << "\nCommand: ";
    };
}
catch (...)
{
    std::cerr << "Something broke!";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
