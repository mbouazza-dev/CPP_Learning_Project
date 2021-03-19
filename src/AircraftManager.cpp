#include "AircraftManager.hpp"

bool AircraftManager::move()
{
    for (auto it = aircrafts.begin(); it != aircrafts.end();)
    {
        if ((*it)->move())
        {
            it = aircrafts.erase(it);
        } else {
            ++it;
        }
    }
    return false;
}

void AircraftManager::add_aircraft(const AircraftType& type, Airport* airport, std::string number)
{
    const std::string flight_number = number;
    const float angle       = (rand() % 1000) * 2 * 3.141592f / 1000.f; // random angle between 0 and 2pi
    const Point3D start     = Point3D { std::sin(angle), std::cos(angle), 0 } * 3 + Point3D { 0, 0, 2 };
    const Point3D direction = (-start).normalize();

    std::unique_ptr<Aircraft> aircraft = std::make_unique<Aircraft>(type, flight_number, start, direction, airport->get_tower());
    aircrafts.emplace(std::move(aircraft));
}