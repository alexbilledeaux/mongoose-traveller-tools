#pragma once
#include "WorldCreation.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace IO {

    std::string ConvertToUWP(WorldCreation::Planet p)
    {
        // Universal World Profile is a standard format for saving world data. It is a string and a series of numbers in hexidecimal.
        // (NAME) (COORDINATES) (STARPORTSIZE)(ATMOSPHERE)(HYDRO)(POPULATION)(GOV)(LAWLEVEL)-(TECH)
        // Example UWP: Cogri 0101 CA6A643-9
        std::string uwp;
        std::ostringstream os;

        os << p.name() << " " << "11" << " " << std::hex << p.starport() << p.atmosphere() << p.hydrology() << p.population() << p.government() << p.law_level() << '-' << p.technology_level();
        uwp = os.str();
        return uwp;
    }

    void SaveToFile(WorldCreation::Planet p)
    {
        std::cout << "Please enter the name of your save file: ";
        std::string file_name;
        std::cin >> file_name;

        std::ofstream save_file(file_name);
        if (save_file.is_open())
        {
            save_file << ConvertToUWP(p);
            save_file.close();
            std::cout << "Save successful.\n";
        }
        else std::cout << "An error occured while opening the file.";

    }
}