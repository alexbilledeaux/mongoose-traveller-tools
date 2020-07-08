// Mongoose Traveller Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <array>
#include "Tools.h"
#include "WorldCreation.h"

int main()
try
{
    std::string input_stream;
    srand(std::time(0));

    std::cout << "Enter 'planet' to generate a new planet or 'roll' to roll a die.\n";
    while (std::cin >> input_stream)
    {
        if (input_stream == "planet")
        {
            WorldCreation::Planet p = WorldCreation::Planet();
            std::cout << p;
        }
        else if (input_stream == "roll")
        {
            std::cout << Tools::RollDice(1) << '\n';
        }
        else if (input_stream == "help")
        {
            std::cout << "Enter 'planet' to generate a new planet or 'roll' to roll a die.\n";
        }
        else
        {
            std::cout << "Sorry, I don't know what to do with that command. Please type 'help' to see your options.\n";
        }
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
