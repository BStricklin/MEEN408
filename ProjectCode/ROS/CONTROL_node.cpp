#include <ros/ros.h>
//#include "DCMOTOR_CONTROLLER.h"  <-- shouldnt actually need this
#include <unistd.h>
#include <std_msgs/String.h>

void q1_Callback(const std_msgs::String::ConstPtr& msg){};

int main(int argc, char **argv)
{
  ros::init(argc,argv,"DCMOTOR_CONTROLLER_node"); // third argument is name of node
  ros::NodeHandle nh;
  ros::Publisher u1_pub=nh.advertise<std_msgs::String>("u1",1000); // control_signal to motor 1
  ros::Subscriber q1_sub = nh.subscribe("q1", 1000, q1_Callback);
  ros::Publisher u2_pub=nh.advertise<std_msgs::String>("u2",1000); // control_signal to motor 2
  ros::Subscriber q2_sub = nh.subscribe("q2", 1000, q1_Callback);
  ros::Rate loop_rate(10);

  int count = 0;
  while(ros::ok()){
    std_msgs::String msg; // message object, which will be stuffed with data

    std::stringstream ss;
    ss << count % 100;
    msg.data = ss.str();

    u1_pub.publish(msg); // publishes msg to topic "control_signal"

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
    ++count;
  }
}
