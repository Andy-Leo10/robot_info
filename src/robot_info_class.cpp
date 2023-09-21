#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

RobotInfo::RobotInfo()
{
    nh = new ros::NodeHandle();
    init_server();
}

RobotInfo::RobotInfo(ros::NodeHandle *nh)
{
    this->nh = nh;
    init_server();
    this->robot_pub = nh->advertise<robot_info::RobotInfoMsg>("robot_info", 1);
}

void RobotInfo::init_server()
{
    this->robot_server = nh->advertiseService("robot_info_server", &RobotInfo::server_callback, this);
}

bool RobotInfo::server_callback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res)
{
    if (req.data)
    {
        ROS_INFO("RobotInfo: server_callback: true");
        publish_data();
        res.success = true;
        res.message = "RobotInfo: server_callback: true";
    }
    else
    {
        ROS_INFO("RobotInfo: server_callback: false");
        res.success = false;
        res.message = "RobotInfo: server_callback: false";
    }
    return true;
}

