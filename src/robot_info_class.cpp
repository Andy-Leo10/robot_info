#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

RobotInfo::RobotInfo()
{
    nh = new ros::NodeHandle();
    init_publisher();
}

RobotInfo::RobotInfo(ros::NodeHandle *nh)
{
    this->nh = nh;
    init_publisher();
}

void RobotInfo::init_publisher()
{
    robot_pub = nh->advertise<robotinfo_msgs::RobotInfo10Fields>("robot_info", 1);
    ros::Rate loop_rate(2);
}

void RobotInfo::publish_data()
{
    robot_msg.data_field_01 = robot_description;
    robot_msg.data_field_02 = serial_number;
    robot_msg.data_field_03 = ip_address;
    robot_msg.data_field_04 = firmware_version;
    robot_msg.data_field_05 = "-";
    robot_msg.data_field_06 = "-";
    robot_msg.data_field_07 = "-";
    robot_msg.data_field_08 = "-";
    robot_msg.data_field_09 = "-";
    robot_msg.data_field_10 = "-";
    robot_pub.publish(robot_msg);
}