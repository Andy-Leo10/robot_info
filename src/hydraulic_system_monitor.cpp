#include <ros/ros.h>
#include "hydraulic_system_monitor.h"
#include <cstdlib>

HydraulicSystemMonitor::HydraulicSystemMonitor()
{

}

int HydraulicSystemMonitor::random_number_generator(int min, int max)
{
    return rand()%(max-min + 1) + min;
}

std::string HydraulicSystemMonitor::get_hydraulic_oil_temperature()
{
    this->hydraulic_oil_temperature=std::to_string(random_number_generator(35, 45)) + " C";
    return this->hydraulic_oil_temperature;
}

std::string HydraulicSystemMonitor::get_hydraulic_oil_tank_fill_level()
{
    this->hydraulic_oil_tank_fill_level=std::to_string(random_number_generator(60, 90)) + " %";
    return this->hydraulic_oil_tank_fill_level;
}

std::string HydraulicSystemMonitor::get_hydraulic_oil_pressure()
{
    this->hydraulic_oil_pressure=std::to_string(random_number_generator(150, 300)) + " bar";
    return this->hydraulic_oil_pressure;
}