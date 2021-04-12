#pragma once

#include "GL/dynamic_object.hpp"
#include "aircraft.hpp"
#include "tower.hpp"

#include <algorithm>
#include <memory>
#include <numeric>
#include <vector>

class AircraftManager : public GL::DynamicObject
{
private:
    int crash_counter = 0;
    std::vector<std::unique_ptr<Aircraft>> aircrafts;
    

public:
    bool move() override;
    void add_aircraft(std::unique_ptr<Aircraft>&);
    int get_crash_counter() { return crash_counter; };
    int get_required_fuel()
    {
        return accumulate(aircrafts.begin(), aircrafts.end(), 0.0, [] (float sum, const std::unique_ptr<Aircraft>& a1) {
        if(a1->is_low_on_fuel() && a1->is_at_terminal)
        {
            return sum + (3000 - a1->fuel);
        }
        return sum;
        });
    }
};