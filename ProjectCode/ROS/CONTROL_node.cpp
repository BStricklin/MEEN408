#include <ros/ros.h>
//#include "DCMOTOR_CONTROLLER.h"  <-- shouldnt actually need this
#include <unistd.h>
#include <std_msgs/String.h>

Class CONTROLLER {
private:

public:
  void q1_Callback(const std_msgs::String::ConstPtr& msg){};
  void q2_Callback(const std_msgs::String::ConstPtr& msg){};
  void grip_Callback(const std_msgs::String::ConstPtr& msg){};
  void mode_Callback(const std_msgs::String::ConstPtr& msg){};
  void trajectory_Callback(const std_msgs::String::ConstPtr& msg){};

}

int main(int argc, char **argv)
{
  ros::init(argc,argv,"DCMOTOR_CONTROLLER_node"); // third argument is name of node
  ros::NodeHandle nh;
  ros::Publisher u1_pub=nh.advertise<std_msgs::String>("u1",1000); // control_signal to motor 1
  ros::Subscriber q1_sub = nh.subscribe("q1", 1000, &CONTROLLER::q1_Callback, &myCONTROLLER);
  ros::Publisher u2_pub=nh.advertise<std_msgs::String>("u2",1000); // control_signal to motor 2
  ros::Subscriber q2_sub = nh.subscribe("q2", 1000, &CONTROLLER::q2_Callback, &myCONTROLLER);
  ros::Publisher gripper_pub=nh.advertise<std_msgs::String>("grip_release",1000); // control_signal to motor 1
  ros::Subscriber gripper_sub = nh.subscribe("grip_position", 1000, &CONTROLLER::grip_Callback, &myCONTROLLER);
  ros::Subscriber mode_sub = nh.subscribe("mode", 1000, &CONTROLLER::mode_Callback, &myCONTROLLER);
  ros::Subscriber trajectory_sub = nh.subscribe("trajectory", 1000, &CONTROLLER::trajectory_Callback, &myCONTROLLER);

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
