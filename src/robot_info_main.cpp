#include "robot_info/robot_info_class.h"
#include <ros/ros.h>

int main(int argc,char **argv)
{
    ros::init(argc,argv,"robot_info_node");
    ros::NodeHandle nh;
    RobotInfo agv=RobotInfo(&nh);
    //a loop for publishing the data
    ros::Rate loop_rate(2);
    while(ros::ok())
    {
        agv.publish_data();
        ros::spinOnce();
        loop_rate.sleep();
    }
}
