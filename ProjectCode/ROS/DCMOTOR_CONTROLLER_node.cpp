#include "ROS.h"
#include "DCMOTOR_CONTROLLER.h"
#include <unistd.h>
#include "std_msgs/String.h"

int main(int argc, char **argv)
{
  ros::init(argc,argv,"DCMOTOR_CONTROLLER_node"); // third argument is name of node
  ros::NodeHandle nh;
  ros::Publisher pub=nh.advertise<std_msgs::String>("control_signal",1000); // control_signal is to
  ros::Rate loop_rate(10);

  int count = 0;
  while(ros::ok()){
    std_msgs::String msg; // message object, which will be stuffed with data

    // put stuff that will go into msg here

    pub.publish(msg); // publishes msg to topic "control_signal"

    ros::spinOnce();

    loop_rate.sleep();
    ++count; // count doesnt really do anything for us in this script
  }
}
