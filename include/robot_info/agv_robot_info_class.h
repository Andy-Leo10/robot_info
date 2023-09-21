#pragma once
#include <ros/ros.h>
#include "robot_info/robot_info_class.h"

//inherit the RobotInfo class

class AgvRobotInfo : public RobotInfo
{
    public:
        AgvRobotInfo();
        AgvRobotInfo(ros::NodeHandle *nh);
        
    protected:
        std::string maximun_payload="100 Kg";
        //overriding the virtual function
        void publish_data();
};