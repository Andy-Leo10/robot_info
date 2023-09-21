#include <ros/ros.h>
#include "robot_info/robot_info_class.h"
#include "robot_info/agv_robot_info_class.h"

int main(int argc,char **argv)
{
    ros::init(argc,argv,"agv_robot_info_node");
    ros::NodeHandle nh;
    AGVRobotInfo agv2=AGVRobotInfo(&nh);
    //a loop for publishing the data
    ros::Rate loop_rate(2);
    while(ros::ok())
    {
        agv2.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }
}