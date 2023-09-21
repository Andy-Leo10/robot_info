#include <ros/ros.h>
#include "robot_info/agv_robot_info_class.h"

AgvRobotInfo::AgvRobotInfo()
{
    nh = new ros::NodeHandle();
    this->init_publisher();
}

AgvRobotInfo::AgvRobotInfo(ros::NodeHandle *nh)
{
    this->nh = nh;
    this->init_publisher();
}

void AgvRobotInfo::publish_data()
{
    ROS_INFO("data published");
    robot_msg.data_field_01 = "robot_description: "+robot_description;
    robot_msg.data_field_02 = "serial_number: "+serial_number;
    robot_msg.data_field_03 = "ip_address: "+ip_address;
    robot_msg.data_field_04 = "firmware_version: "+firmware_version;
    robot_msg.data_field_05 = "maximun_payload: "+maximun_payload;
    robot_msg.data_field_06 = "hydraulic_oil_temperature: "+hydraulic_system_monitor.get_hydraulic_oil_temperature();
    robot_msg.data_field_07 = "hydraulic_oil_tank_fill_level: "+hydraulic_system_monitor.get_hydraulic_oil_tank_fill_level();
    robot_msg.data_field_08 = "hydraulic_oil_pressure: "+hydraulic_system_monitor.get_hydraulic_oil_pressure();
    /*
    robot_msg.data_field_09 = "-";
    robot_msg.data_field_10 = "-";
    */
    robot_pub.publish(robot_msg);
}