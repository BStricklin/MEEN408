#include <ros/ros.h>
//#include "DCMOTOR_CONTROLLER.h"
#include <unistd.h>
#include <std_msgs/String.h>

void eqep_Callback(const std_msgs::String::ConstPtr& msg){}

int main(int argc, char **argv)
{
  ros::init(argc,argv,"DCMOTOR_CONTROLLER_node"); // third argument is name of node
  ros::NodeHandle nh;
  ros::Publisher control_pub=nh.advertise<std_msgs::String>("control_signal",1000); // control_signal is to
  ros::Subscriber control_sub = nh.subscribe("control_signal", 1000, eqep_Callback);
  ros::Rate loop_rate(10);

  int count = 0;
  while(ros::ok()){
    std_msgs::String msg; // message object, which will be stuffed with data

    std::stringstream ss;
    ss << count;
    msg.data = ss.str();

    control_pub.publish(msg); // publishes msg to topic "control_signal"

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
    ++count;
  }
}
