#include "AircraftManager.hpp"

bool AircraftManager::move()
{    
    std::sort(aircrafts.begin(), aircrafts.end(), [](std::unique_ptr<Aircraft>& aircraft1, std::unique_ptr<Aircraft>& aircraft2) 
    { 
         if(aircraft1->has_terminal() == aircraft2->has_terminal())
         {
             return aircraft1->fuel <= aircraft2->fuel; 
         }
         return aircraft1->has_terminal();
    });

    aircrafts.erase(
        std::remove_if(aircrafts.begin(), aircrafts.end(),
        [this](std::unique_ptr<Aircraft> & aircraft) {
            
            try
            {
                return aircraft->move();
            }
            catch (const AircraftCrash& err)
            {
                aircraft->control.update_terminals(aircraft.get());
                crash_counter++;
                std::cerr << err.what() << std::endl;
                return true;
            }
            
            }),
        aircrafts.end());

    return false;
}

void AircraftManager::add_aircraft(std::unique_ptr<Aircraft>& aircraft)
{
    aircrafts.emplace_back(std::move(aircraft));
}