// Mongoose Traveller Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <vector>
#include <array>
#include "Tools.h"
#include "WorldCreation.h"
#include "IO.h"

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
    std::cout << std::left << std::setw(command_col_width) << "'systemhex'" << std::setw(effect_col_width) << "randomly generate a systemhex." << std::endl;
    std::cout << std::left << std::setw(command_col_width) << "'subsector'" << std::setw(effect_col_width) << "randomly generate a subsector." << std::endl;
    std::cout << std::left << std::setw(command_col_width) << "'coordinates'" << std::setw(effect_col_width) << "fetch a systemhex by its coordinates in the current subsector." << std::endl;
    std::cout << std::left << std::setw(command_col_width) << "'save'" << std::setw(effect_col_width) << "save the current subsector." << std::endl;
    std::cout << std::left << std::setw(command_col_width) << "'help'" << std::setw(effect_col_width) << "see this menu again." << std::endl;
}

int main()
try
{
    std::string input_stream;
    srand(std::time(0));

    WorldCreation::Planet p = WorldCreation::Planet();
    WorldCreation::SystemHex sh = WorldCreation::SystemHex();
    WorldCreation::Subsector sb = WorldCreation::Subsector();

    OutputHelpText();
    std::cout << "\nCommand: ";
    while (std::cin >> input_stream)
    {
        if (input_stream == "planet")
        {
            p = WorldCreation::Planet();
            std::cout << p;
        }
        else if (input_stream == "help")
        {
            OutputHelpText();
        }
        else if (input_stream == "save")
        {
            IO::SaveToFile(p);
        }
        else if (input_stream == "systemhex")
        {
            sh = WorldCreation::SystemHex();
            std::cout << sh;
        }
        else if (input_stream == "subsector")
        {
            sb = WorldCreation::Subsector();
            std::cout << "New subsector generated!\n";
        }
        else if (input_stream == "coordinates")
        {
            int x;
            int y;

            std::cout << "What is the X coordinate?\n";
            std::cin >> x;
            std::cout << "What is the Y coordinate?\n";
            std::cin >> y;

            if (x <= 8 && x >= 1 && y >= 1 && y <= 10)
            {
                WorldCreation::SystemHex target = sb.GetHexByCoordinates(x - 1, y - 1);
                std::cout << target;
            }
            else {
                std::cout << "Invalid coordinates!\n";
            }

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
