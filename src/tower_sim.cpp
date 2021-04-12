#include "tower_sim.hpp"

#include "GL/opengl_interface.hpp"
#include "aircraft.hpp"
#include "airport.hpp"
#include "config.hpp"
#include "img/image.hpp"
#include "img/media_path.hpp"

#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std::string_literals;


TowerSimulation::TowerSimulation(int argc, char** argv) :
    help { (argc > 1) && (std::string { argv[1] } == "--help"s || std::string { argv[1] } == "-h"s) }
{
    MediaPath::initialize(argv[0]);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    GL::init_gl(argc, argv, "Airport Tower Simulation");
    GL::move_queue.emplace(&aircraft_manager);
    create_keystrokes();
}

TowerSimulation::~TowerSimulation()
{
    delete airport;
}

void TowerSimulation::create_keystrokes()
{
    GL::keystrokes.emplace('x', []() { GL::exit_loop(); });
    GL::keystrokes.emplace('q', []() { GL::exit_loop(); });
    GL::keystrokes.emplace('c', [this]() { factory.create_random_aircraft(airport->get_tower(), aircraft_manager); });
    GL::keystrokes.emplace('+', []() { GL::change_zoom(0.95f); });
    GL::keystrokes.emplace('-', []() { GL::change_zoom(1.05f); });
    GL::keystrokes.emplace('f', []() { GL::toggle_fullscreen(); });
    GL::keystrokes.emplace('p', []() { GL::change_ticks(15); });
    GL::keystrokes.emplace('m', []() { GL::change_ticks(-15); });
    GL::keystrokes.emplace('k', [this]() { aircraft_manager.get_crash_counter(); });
    GL::keystrokes.emplace('0', [this]() { std::cout<< "There is "<< factory.aircrafts_count("AF") << " plane(s) from AF" <<std::endl;});
    GL::keystrokes.emplace('1', [this]() { std::cout<< "There is "<< factory.aircrafts_count("LH") << " plane(s) from LH" <<std::endl;});
    GL::keystrokes.emplace('2', [this]() { std::cout<< "There is "<< factory.aircrafts_count("EY") << " plane(s) from EY" <<std::endl;});
    GL::keystrokes.emplace('3', [this]() { std::cout<< "There is "<< factory.aircrafts_count("DL") << " plane(s) from DL" <<std::endl;});
    GL::keystrokes.emplace('4', [this]() { std::cout<< "There is "<< factory.aircrafts_count("KL") << " plane(s) from KL" <<std::endl;});
    GL::keystrokes.emplace('5', [this]() { std::cout<< "There is "<< factory.aircrafts_count("BA") << " plane(s) from BA" <<std::endl;});
    GL::keystrokes.emplace('6', [this]() { std::cout<< "There is "<< factory.aircrafts_count("AY") << " plane(s) from AY" <<std::endl;});
    GL::keystrokes.emplace('7', [this]() { std::cout<< "There is "<< factory.aircrafts_count("EY") << " plane(s) from EY" <<std::endl;});
}

void TowerSimulation::display_help() const
{
    std::cout << "This is an airport tower simulator" << std::endl
              << "the following keysstrokes have meaning:" << std::endl;

    for (auto[touch, mapping] : GL::keystrokes)
    {
        std::cout << touch << ' ';
    }

    std::cout << std::endl;
}

void TowerSimulation::init_airport(AircraftManager& manager)
{
    airport = new Airport { one_lane_airport, Point3D { 0, 0, 0 },
                            new img::Image { one_lane_airport_sprite_path.get_full_path() }, manager };

    GL::display_queue.emplace_back(airport);
    GL::move_queue.emplace(airport);
}

void TowerSimulation::launch()
{
    if (help)
    {
        display_help();
        return;
    }

    init_airport(aircraft_manager);
    factory.init_aircraft_types();

        GL::loop();
}
