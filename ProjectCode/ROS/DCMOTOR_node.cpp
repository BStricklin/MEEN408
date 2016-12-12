#include "ROS.h"
#include "DCMOTOR.h"
#include <unistd.h>

int main(int argc, char **argv)
{
  ros::init(argc,argv,"DCMOTOR_node");
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  ros::Subscriber sub = n.subscribe();

}
