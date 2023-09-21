#pragma once
#include <ros/ros.h>
#include "robot_info/robot_info_class.h"

//inherit the RobotInfo class

class AgvRobotInfo : public RobotInfo
{
    public:
        AgvRobotInfo();
        AgvRobotInfo(ros::NodeHandle *nh);
        //overriding the virtual function
        void publish_data();
        
    protected:
        std::string maximun_payload="100 Kg";
};