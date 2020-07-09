#pragma once
#include <vector>
#include <string>
#include "Tools.h"

namespace WorldCreation
{

    namespace PlanetTables
    {
        const std::vector<int> size_as_km
        {
            800,
            1600,
            3200,
            4800,
            6400,
            8000,
            9600,
            11200,
            12800,
            14400,
            16000
        };
        const std::vector<float> surface_gravity
        {
            0.0,
            0.05,
            0.15,
            0.25,
            0.35,
            0.45,
            0.7,
            0.9,
            1.0,
            1.25,
            1.4
        };
        const std::vector<std::string> atmosphere_description
        {
            "None",
            "Trace",
            "Very Thin, Tainted",
            "Very Thin",
            "Thin, Tainted",
            "Thin",
            "Standard",
            "Standard, Tainted",
            "Dense",
            "Dense, Tainted",
            "Exotic",
            "Corrosive",
            "Insidious",
            "Dense, High",
            "Thin, Low",
            "Unusual"
        };
        const std::vector<std::array<float, 2>> atmosphere_pressure_range
        {
            { 0.00, 0.00 },
            { 0.001, 0.09 },
            { 0.1, 0.42 },
            { 0.1, 0.42 },
            { 0.43, 0.7 },
            { 0.43, 0.7 },
            { 0.71, 1.49 },
            { 0.71, 1.49 },
            { 1.5, 2.49 },
            { 1.5, 2.49 },
            { 0.00, 2.49 },
            { 0.00, 2.49 },
            { 0.00, 2.49 },
            { 2.49, 5 },
            { 0.00, 0.5 },
            { 0.00, 2.49 }
        };
        const std::vector<std::array<float, 2>> hydrographic_as_percent_range
        {
            { 0, 0.05 },
            { 0.06, 0.15 },
            { 0.16, 0.25 },
            { 0.26, 0.35 },
            { 0.36, 0.45 },
            { 0.46, 0.55 },
            { 0.56, 0.65 },
            { 0.66, 0.75 },
            { 0.76, 0.85 },
            { 0.86, 0.95 },
            { 0.96, 100 }
        };
        const std::vector<std::string> hydrographic_description
        {
            "Desert world",
            "Dry world",
            "A few small seas",
            "Small seas and oceans",
            "Wet world",
            "Large oceans",
            "Large oceans",
            "Earth-like world",
            "Water world",
            "Only a few small islands and archipelagos",
            "Almost entirely water"
        };
        const std::vector<std::array<long long int, 2>> population_range
        {
            {0,0},
            {1,99},
            {100,999},
            {1000,9999},
            {10000,99999},
            {100000,999999},
            {1000000,9999999},
            {10000000,99999999},
            {100000000,999999999},
            {1000000000,9999999999},
            {10000000000,99999999999},
            {100000000000,999999999999},
            {1000000000000,9999999999999}
        };
        const std::vector<std::string> population_description
        {
            "None",
            "A tiny famstead or a single family",
            "A village",
            "A mid-sized village",
            "A small town",
            "An average city",
            "An above average city",
            "A large city",
            "Several large cities",
            "Prsent day Earth",
            "Crowded world",
            "Incredibly crowded world",
            "World-city"
        };
        const std::vector<std::string> government_title
        {
            "None",
            "Company/corporation",
            "Participating democracy",
            "Self-perpetuating oligarchy",
            "Representative democracy",
            "Feudal technocracy",
            "Captive government",
            "Balkanisation",
            "Civil service bureaucracy",
            "Impersonal Bureaucracy",
            "Charismatic dictator",
            "Non-charismatic leader",
            "Charismatic oligarchy",
            "Religious dictatorship"
        };
        const std::vector<std::string> government_description
        {
            "No government structure. In many cases, family bonds predominate.",
            "Ruling functions are assumed by a company or managerial elite, and most citizenry are company employees or dependants.",
            "Ruling functions are reached by the advice and consent of the citizenry directly.",
            "Ruling functions are performed by a restricted minority, with little or no input from the mass of citizenry.",
            "Ruling functions are performed by elected representatives.",
            "Ruling functions are performed by specific individuals for persons who agree to be ruled by them. Relationships are based on the performance of technical activities which are mutually beneficial.",
            "Ruling functions are performed by an imposed leadership answerable to an outside group.",
            "No central authority exists; rival governments compete for control. Law level refers to the government nearest the starport.",
            "Ruling functions are performed by government agencies employing individuals selected for their expertise.",
            "Ruling functions are performed by agencies which have become insulated from the governed citizens.",
            "Ruling functions are performed by agencies directed by a single leader who enjoys the overwhelming confidence of the citizens.",
            "A previous charismatic dictator has been replaced by a leader through normal channels.",
            "Ruling functions are performed by a select group of members of an organisation or class which enjoys the overwhelming confidence of the citizenry.",
            "Ruling functions are performed by a religious organisation without regard to the specific individual needs of the citizenry."
        };
    }

    class Base
    {
    public:
        Base(std::string type)
        {
            _type = type;
        };
    private:
        std::string _type;
    };

    class Planet
    {
    public:
        Planet();
        Planet(std::string name);
        std::string name() { return _name; }
        int size() { return _size; }
        int atmosphere() { return _atmosphere; }
        int hydrology() { return _hydrology; }
        int population() { return _population; }
        int government() { return _government; }
        int law_level() { return _law_level; }
        int starport() { return _starport; }
        int technology_level() { return _technology_level; }
        std::vector<Base> bases() { return _bases; }
        char GetStarportRank();
    private:
        std::string _name;
        int _size;
        int _atmosphere;
        int _hydrology;
        int _population;
        int _government;
        int _law_level;
        int _starport;
        int _technology_level;
        std::vector<Base> _bases;
    };

    Planet::Planet()
    {
        _name = Tools::GenerateRandomAlphanum(6);
        _size = Tools::RollDice(2) - 2;

        _atmosphere = Tools::RollDice(2) - 7 + _size;
        _atmosphere = Tools::clamp(_atmosphere, 0, 15);

        _hydrology = Tools::RollDice(2) - 7;
        if (_size < 2)
        {
            _hydrology = 0;
        }
        // No or irregular atmosphere means no water.
        switch (_atmosphere)
        {
        case 0:
        case 1:
        case 10:
        case 11:
        case 12:
            _hydrology -= 4;
            break;
        }
        _hydrology = Tools::clamp(_hydrology, 0, 10);

        _population = Tools::RollDice(2) - 2;
        _government = Tools::RollDice(2) - 7 + _population;
        _government = Tools::clamp(_government, 0, 13);
        _law_level = Tools::RollDice(2) - 7 + _government;
        _law_level = Tools::clamp(_law_level, 0, 13);
        _starport = Tools::RollDice(2);

        _technology_level = Tools::RollDice(1);

        // Nicer starport means nicer technology.
        switch (_starport)
        {
        case 2:
            _technology_level -= 4;
            break;
        case 7:
        case 8:
            _technology_level += 2;
            break;
        case 9:
        case 10:
            _technology_level += 4;
            break;
        case 11:
        case 12:
            _technology_level += 6;
            break;
        }

        // Small planets require more tech to survive.
        switch (_size)
        {
        case 0:
        case 1:
            _technology_level += 2;
            break;
        case 2:
        case 3:
        case 4:
            _technology_level += 1;
            break;
        }

        // No atosphere or abnormally dense atmosphere require more technology.
        switch (_atmosphere)
        {
        case 0:
        case 1:
        case 2:
        case 3:
            _technology_level += 1;
            break;
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
            _technology_level += 1;
            break;
        }

    };

    Planet::Planet(std::string name)
    {
        _name = name;
    }

    char Planet::GetStarportRank()
    {
        switch (_starport)
        {
        case 0:
        case 1:
        case 2:
            return 'X';
            break;
        case 3:
        case 4:
            return 'E';
            break;
        case 5:
        case 6:
            return 'D';
            break;
        case 7:
        case 8:
            return 'C';
            break;
        case 9:
        case 10:
            return 'B';
            break;
        case 11:
        case 12:
            return 'A';
            break;
        }
    }

    std::vector<std::string> GenerateTradeCodes(Planet planet)
    {
        std::vector<std::string> tradecodes;

        if (Tools::IsInRange(planet.atmosphere(), 4, 9) && Tools::IsInRange(planet.hydrology(), 4, 8) && Tools::IsInRange(planet.population(), 5, 7))
        {
            tradecodes.push_back("Ag");
        }
        return tradecodes;
    }

    std::ostream& operator<<(std::ostream& os, Planet& p)
    {
        os << "NAME: " << p.name() << '\n';
        os << "SIZE: " << PlanetTables::size_as_km[p.size()] << "km\n";
        os << "ATMOSPHERE: " << PlanetTables::atmosphere_description[p.atmosphere()] << " with " << PlanetTables::atmosphere_pressure_range[p.atmosphere()][0] << " pressure." << '\n';
        os << "HYDROLOGY: " << PlanetTables::hydrographic_as_percent_range[p.hydrology()][0] * 100 << "% surface water. " << PlanetTables::hydrographic_description[p.hydrology()] << "." << '\n';
        os << "POPULATION: " << PlanetTables::population_range[p.population()][0] << ". Distribution: " << PlanetTables::population_description[p.population()] << ".\n";
        os << "GOVERNMENT: " << PlanetTables::government_title[p.government()] << ". " << PlanetTables::government_description[p.government()] << '\n';
        os << "LAW LEVEL: " << p.law_level() << '\n';
        os << "STARPORT: " << p.GetStarportRank() << '\n';
        os << "TECH LEVEL: " << p.technology_level() << '\n';
        return os;
    }

    class SystemHex
    {
    public:
        SystemHex();
        bool has_world() { return _has_world; }
        bool has_gas_giant() { return _has_gas_giant; }
        std::string name() { return _name; }
        Planet planet() { return _planet; }
    private:
        bool _has_world;
        bool _has_gas_giant;
        std::string _name;
        Planet _planet;
    };

    SystemHex::SystemHex()
    {
        _has_world =  3 < Tools::RollDice(1);
        _has_gas_giant = 10 > Tools::RollDice(2);
        if (_has_world)
        {
            // If the system has a world, the system is usually named after said world.
            _planet = Planet();
            _name = _planet.name();
        }
        else
        {
            _name = Tools::GenerateRandomAlphanum(6);
        }
            
    }

    std::ostream& operator<<(std::ostream& os, SystemHex& sh)
    {
        os << "NAME: " << sh.name() << "\n\n" << "*** PLANETS ***\n";
        if (sh.has_world())
        {
            Planet p = sh.planet();
            os << p << '\n';
        }
        else {
            os << "NO PLANETARY BODIES.\n\n";
        }

        os << "** GAS GIANT **\n";

        if (sh.has_gas_giant())
        {
            os << "STANDARD GAS GIANT DETECTED.\n";
        }
        else {
            os << "NO GAS GIANTS DETECTED.\n";
        }
        return os;
    }

    class Subsector
    {
    public:
        Subsector();
        SystemHex GetHexByCoordinates(int x, int y) { return system_hexes[x][y]; }
    private:
        SystemHex system_hexes[8][10];
    };

    Subsector::Subsector()
    {
        // Loop through our 2D array and spawn a systemhex for each element
        for (int i = 0; i < 8; ++i)
        {
            for (SystemHex sh : system_hexes[i])
            {
                sh = SystemHex();
            }
        }
    }

    class Sector
    {

    };

    class Polity
    {

    };

}