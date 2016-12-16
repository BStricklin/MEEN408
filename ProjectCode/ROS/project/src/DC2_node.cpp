#include <project/DCMOTOR.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <unistd.h>

// void DC1_Callback(const std_msgs::String::ConstPtr& msg){
// ROS_INFO("I heard: [%s]", msg->data.c_str());
//}

class DC2 {
private:
  DCMOTOR myDCMOTOR2;
  int offset;
public:
  DC2(int PWMChipNumberr, int PWMNumberr, int EQEPNumberr, int GPIONumberHigh,
      int GPIONumberLow)
      : myDCMOTOR2(PWMChipNumberr, PWMNumberr, EQEPNumberr, GPIONumberHigh,
              GPIONumberLow) {
                offset = myDCMOTOR2.getAngle();
              }
  void DC2_Callback(const std_msgs::String::ConstPtr& msg) {
    std::stringstream ss;
    ss.str(msg->data.c_str());
    int temp = 0;
    ss >> temp;
    std::cout << "Setting to " << temp << std::endl;
    myDCMOTOR2.setPWMDutyCycle(temp);
  }
  void enable(){
    myDCMOTOR2.enable(1);
  }
  int getAngle(){
      return (myDCMOTOR2.getAngle() - offset);
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "DC2_node");
  DC2 myDC2(0, 0, 0, 30, 60); // INPUTS IN PROGRESS
  myDC2.enable();
  ros::NodeHandle nh;
  ros::Rate loop_rate(60);

  ros::Publisher pub = nh.advertise<std_msgs::String>("q2", 1000);
  ros::Subscriber sub = nh.subscribe("u2", 1000, &DC2::DC2_Callback, &myDC2);

  while (ros::ok()) {

    std_msgs::String msg;

    std::stringstream ss;

    ss << myDC2.getAngle();
    msg.data = ss.str();

    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
}
