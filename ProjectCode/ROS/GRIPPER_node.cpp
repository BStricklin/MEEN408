// Author: Blake Leiker, Augustus Ellis
#include <project/SERVOMOTOR.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <unistd.h>

class GRIPPER {
 private:
  SERVOMOTOR mySERVO;

 public:
  GRIPPER(int PWMNumberr) : mySERVO(PWMNumberr) { mySERVO.gripperClose(); }
  void GRIPPER_Callback(const std_msgs::String::ConstPtr &msg) {
    mySERVO.gripperOpen();
    Position = 1;
  }
  int Position;
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "GRIPPER_node");
  GRIPPER myGRIPPER(0);
  myGRIPPER.Position = 0;
  ros::NodeHandle nh;
  ros::Rate loop_rate(10);

  ros::Publisher pub = nh.advertise<std_msgs::String>("grip_position", 1000);
  ros::Subscriber sub = nh.subscribe("grip_release", 1000,
                                     &GRIPPER::GRIPPER_Callback, &myGRIPPER);

  while (ros::ok()) {
    std_msgs::String msg;

    std::stringstream ss;
    ss << myGRIPPER.Position;
    msg.data = ss.str();

    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
}
