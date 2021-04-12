#pragma once

#include "AircraftManager.hpp"
#include "AircraftFactory.hpp"

class Airport;
struct AircraftType;

class TowerSimulation
{
private:
    bool help        = false;
    Airport* airport = nullptr;
    AircraftFactory factory;
    AircraftManager aircraft_manager;

    TowerSimulation(const TowerSimulation&) = delete;
    TowerSimulation& operator=(const TowerSimulation&) = delete;

    void create_keystrokes();
    void display_help() const;

    void init_airport(AircraftManager&);

    Airport* get_airport()
    {
        return airport;
    }

public:
    TowerSimulation(int argc, char** argv);
    ~TowerSimulation();

    void launch();
};