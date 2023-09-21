#pragma once
#include <ros/ros.h>

class HydraulicSystemMonitor
{
public:
    HydraulicSystemMonitor();

protected:
    std::string hydraulic_oil_temperature = "";
    std::string hydraulic_oil_tank_fill_level = "";
    std::string hydraulic_oil_pressure = "";

public:
    int random_number_generator(int min, int max);
    std::string get_hydraulic_oil_temperature();
    std::string get_hydraulic_oil_tank_fill_level();
    std::string get_hydraulic_oil_pressure();
};