#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

int main(int argc,char **argc)
{
    ros::init(argc,argv,"robot_info_node");
    ros::NodeHandle nh;
    RobotInfo agv=RobotInfo(&nh);
}
