#include "ROS.h"
#include "DCMOTOR.h"
#include <unistd.h>

int main()
{
  ros::init(argc,argv,"DCMOTOR_node");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

}
