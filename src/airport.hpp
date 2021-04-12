#pragma once

#include "GL/displayable.hpp"
#include "GL/dynamic_object.hpp"
#include "GL/texture.hpp"
#include "airport_type.hpp"
#include "AircraftManager.hpp"
#include "Point.hpp"
#include "img/image.hpp"
#include "runway.hpp"
#include "terminal.hpp"
#include "tower.hpp"

#include <vector>

class Airport : public GL::Displayable, public GL::DynamicObject
{
private:
    const AirportType& type;
    const Point3D pos;
    const GL::Texture2D texture;
    std::vector<Terminal> terminals;
    Tower tower;
    int fuel_stock = 10000;
    int ordered_fuel = 0;
    int next_refill_time = 100;
    AircraftManager& manager;

    std::pair<WaypointQueue, size_t> reserve_terminal(Aircraft& aircraft)
    {
        const auto it =
            std::find_if(terminals.begin(), terminals.end(), [](const Terminal& t) { return !t.in_use(); });

        if (it != terminals.end())
        {
            it->assign_craft(aircraft);
            const auto term_idx = std::distance(terminals.begin(), it);
            return { type.air_to_terminal(pos, 0, term_idx), term_idx };
        }
        else
        {
            return { {}, 0u };
        }
    }
    WaypointQueue start_path(const size_t terminal_number)
    {
        return type.terminal_to_air(pos, 0, terminal_number);
    }
    Terminal& get_terminal(const size_t terminal_num) { return terminals.at(terminal_num); }

public:
    Airport(const AirportType& type_, const Point3D& pos_, const img::Image* image, AircraftManager& manager_ ,const float z_ = 1.0f) :
        GL::Displayable { z_ },
        type { type_ },
        pos { pos_ },
        texture { image },
        terminals { type.create_terminals() },
        tower { *this },
        manager { manager_ }
    {}

    Tower& get_tower() { return tower; }
    void display() const override { texture.draw(project_2D(pos), { 2.0f, 2.0f }); }
    bool move() override
    {
        if (next_refill_time == 0)
        {
            ordered_fuel = std::min(manager.get_required_fuel(), 5000);
            fuel_stock+=ordered_fuel;
            next_refill_time = 100;
            std::cout<<"Fuel stock: "<<fuel_stock<<" / Ordered fuel: "<<ordered_fuel<<std::endl;
        }
        else
        {
            next_refill_time--;
        }
        for (auto& t : terminals)
        {
            t.move();
            t.refill_if_needed(fuel_stock);
        }
        return false;
    }
    
    friend class Tower;
};