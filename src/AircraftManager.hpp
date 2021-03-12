#pragma once

#include <vector>
#include <memory>
#include "GL/dynamic_object.hpp"
#include "aircraft.hpp"
#include "airport.hpp"

class AircraftManager : public GL::DynamicObject
{
private:
    std::unordered_set<std::unique_ptr<Aircraft>> aircrafts;

public:
    bool move() override;
    void add_aircraft(const AircraftType& type, const std::string airlines[8], Airport* airport);
};