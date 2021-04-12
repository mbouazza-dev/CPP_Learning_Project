#include "tower.hpp"

#include "airport.hpp"
#include "terminal.hpp"

#include <cassert>

WaypointQueue Tower::get_circle() const
{
    return { { Point3D { -1.5f, -1.5f, .5f }, wp_air },
             { Point3D { 1.5f, -1.5f, .5f }, wp_air },
             { Point3D { 1.5f, 1.5f, .5f }, wp_air },
             { Point3D { -1.5f, 1.5f, .5f }, wp_air } };
}

WaypointQueue Tower::get_instructions(Aircraft& aircraft)
{
    if(!aircraft.is_at_terminal){
        const WaypointQueue p = reserve_terminal(aircraft);
        if(!p.empty())
        {
            return p;
        } 
        else
        {
            return get_circle();
        } 
    }
    else
    {
        // get a path for the craft to start
        const auto it = reserved_terminals.find(&aircraft);
        assert(it != reserved_terminals.end());
        const auto terminal_num = it->second;
        Terminal& terminal      = airport.get_terminal(terminal_num);
        if (!terminal.is_servicing())
        {
            terminal.finish_service();
            reserved_terminals.erase(it);
            aircraft.is_at_terminal = false;
            return airport.start_path(terminal_num);
        }
        else
        {
            return {};
        }
    }
}

void Tower::arrived_at_terminal(const Aircraft& aircraft)
{
    const auto it = reserved_terminals.find(&aircraft);
    assert(it != reserved_terminals.end());
    airport.get_terminal(it->second).start_service(aircraft);
}

WaypointQueue Tower::reserve_terminal(Aircraft& aircraft)
{
    if (!aircraft.is_at_terminal)
    {
        // try and reserve a terminal for the craft to land
            const auto vp = airport.reserve_terminal(aircraft);
            if (!vp.first.empty())
            {
                reserved_terminals.insert(std::pair<const Aircraft* ,size_t> (&aircraft, vp.second));
                return vp.first;
            }
            else
            {   
                return {};
            }
    }
    return {};
}

void Tower::update_terminals(Aircraft* aircraft)
{
    for (auto& t : airport.terminals)
    {
        if (t.get_aircraft() == aircraft)
        {
            std::cout << "equal aircraft" << std::endl;
            t.free_aircraft();
        }
    }
    auto it = reserved_terminals.find(aircraft);
    if (it != reserved_terminals.end())
    {
        reserved_terminals.erase(it);
    }
}