#include <ros/ros.h>
#include "robot_info/agv_robot_info_class.h"

AGVRobotInfo::AGVRobotInfo()
{
    nh = new ros::NodeHandle();
    this->init_publisher();
}

AGVRobotInfo::AGVRobotInfo(ros::NodeHandle *nh)
{
    this->nh = nh;
    this->init_publisher();
}

void AGVRobotInfo::publish_data()
{
    ROS_INFO("data published");
    robot_msg.data_field_01 = this->robot_description;
    robot_msg.data_field_02 = this->serial_number;
    robot_msg.data_field_03 = this->ip_address;
    robot_msg.data_field_04 = this->firmware_version;
    robot_msg.data_field_05 = maximun_payload;
    /*
    robot_msg.data_field_06 = "-";
    robot_msg.data_field_07 = "-";
    robot_msg.data_field_08 = "-";
    robot_msg.data_field_09 = "-";
    robot_msg.data_field_10 = "-";
    */
    robot_pub.publish(robot_msg);
}