#pragma once
#include <string>
#include <iostream>
#include "aircraft_types.hpp"
#include "AircraftManager.hpp"

class AircraftFactory
{   
private:
    std::string airlines[8] = { "AF", "LH", "EY", "DL", "KL", "BA", "AY", "EY" };
    std::vector<std::string> number_used;
    AircraftType* aircraft_types[3] {};
    
public:
    inline void init_aircraft_types()
    {
        aircraft_types[0] = new AircraftType { .02f, .05f, .02f, MediaPath { "l1011_48px.png" } };
        aircraft_types[1] = new AircraftType { .02f, .05f, .02f, MediaPath { "b707_jat.png" } };
        aircraft_types[2] = new AircraftType { .07f, .07f, .07f, MediaPath { "concorde_af.png" } };
    }

    void create_aircraft(const AircraftType& type, Tower& tower, AircraftManager& aircraft_manager)
    {
        //assert(tower); // make sure the airport is initialized before creating aircraft
        std::string number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
        auto it = std::find(number_used.begin(), number_used.end(), number);

        while (it != number_used.end())
        {
            number = airlines[std::rand() % 8] + std::to_string(1000 + (rand() % 9000));
            it = std::find(number_used.begin(), number_used.end(), number);
        }
        
        add_flight_number(number);
        const std::string flight_number = number;
        const float angle       = (rand() % 1000) * 2 * 3.141592f / 1000.f; // random angle between 0 and 2pi
        const Point3D start     = Point3D { std::sin(angle), std::cos(angle), 0 } * 3 + Point3D { 0, 0, 2 };
        const Point3D direction = (-start).normalize();
        float fuel = 150 + ( std::rand() % (3000-150+1) );

        std::unique_ptr<Aircraft> aircraft = std::make_unique<Aircraft>(type, flight_number, start, direction, tower, fuel);
        aircraft_manager.add_aircraft(aircraft);
    }

    void create_random_aircraft(Tower& tower, AircraftManager& aircraft_manager)
    {
        create_aircraft(*(aircraft_types[rand() % 3]), tower, aircraft_manager);
    }

    void add_flight_number(const std::string num)
    {
        number_used.emplace_back(num);
    }

    int aircrafts_count(std::string company)
    {
        return std::count_if(number_used.begin(), number_used.end(), [company](std::string number){return number.compare(0, 2, company, 0, 2) == 0;});
    }
};