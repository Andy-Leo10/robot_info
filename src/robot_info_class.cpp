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

