#pragma once
#include <ros/ros.h>
#include <std_srvs/SetBool.h>

class RobotInfo
{
public:
    RobotInfo();
    RobotInfo(ros::NodeHandle *nh);

protected:
    ros::NodeHandle *nh;
    void init_server();
    std::string robot_description="Mir100";
    std::string serial_number="567A359";
    std::string ip_address="169.254.5.180";
    std::string firmware_version="3.5.8";
    //my virtual function
    virtual void publish_data();

private:
    ros::Publisher robot_pub;
    ros::Subscriber robot_sub;
    ros::ServiceServer robot_server;
    bool server_callback(std_srvs::SetBool::Request &req, std_srvs::SetBool::Response &res);
};