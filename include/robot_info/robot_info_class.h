#pragma once
#include <ros/ros.h>
#include <std_srvs/SetBool.h>
#include <robotinfo_msgs/RobotInfo10Fields.h>

class RobotInfo
{
public:
    RobotInfo();
    RobotInfo(ros::NodeHandle *nh);
    //my virtual function
    virtual void publish_data();

protected:
    ros::NodeHandle *nh;
    void init_publisher();
    std::string robot_description="Mir100";
    std::string serial_number="567A359";
    std::string ip_address="169.254.5.180";
    std::string firmware_version="3.5.8";
    

protected:
    ros::Publisher robot_pub;
    robotinfo_msgs::RobotInfo10Fields robot_msg;
};

/* looks of the imported message
string data_field_01
string data_field_02
string data_field_03
string data_field_04
string data_field_05
string data_field_06
string data_field_07
string data_field_08
string data_field_09
string data_field_10
*/