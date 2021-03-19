#pragma once

#include "aircraft_types.hpp"
#include "AircraftManager.hpp"

class AircraftFactory
{   
private:
    const std::string airlines[8] = { "AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY" };
    std::vector<std::string> number_used;
    AircraftType* aircraft_types[3] {};
    
public:
    inline void init_aircraft_types()
    {
        aircraft_types[0] = new AircraftType { .02f, .05f, .02f, MediaPath { "l1011_48px.png" } };
        aircraft_types[1] = new AircraftType { .02f, .05f, .02f, MediaPath { "b707_jat.png" } };
        aircraft_types[2] = new AircraftType { .07f, .07f, .07f, MediaPath { "concorde_af.png" } };
    }

    void create_aircraft(const AircraftType& type, Airport* airport, AircraftManager& aircraft_manager)
    {
        assert(airport); // make sure the airport is initialized before creating aircraft
        std::string number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
        auto it = std::find(number_used.begin(), number_used.end(), number);

        while (it != number_used.end())
        {
            number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
            it = std::find(number_used.begin(), number_used.end(), number);
        }
        
        add_flight_number(number);
        aircraft_manager.add_aircraft(type, airport, number);
    }

    void create_random_aircraft(Airport* airport, AircraftManager& aircraft_manager)
    {
        create_aircraft(*(aircraft_types[rand() % 3]), airport, aircraft_manager);
    }

    void add_flight_number(const std::string num)
    {
        number_used.emplace_back(num);
    }
};