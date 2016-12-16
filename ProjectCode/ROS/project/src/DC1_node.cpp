#include <project/DCMOTOR.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <unistd.h>

// void DC1_Callback(const std_msgs::String::ConstPtr& msg){
// ROS_INFO("I heard: [%s]", msg->data.c_str());
//}

class DC1 {
private:
  DCMOTOR myDCMOTOR1;
  int offset;
public:
  DC1(int PWMChipNumberr, int PWMNumberr, int EQEPNumberr, int GPIONumberHigh,
      int GPIONumberLow)
      : myDCMOTOR1(PWMChipNumberr, PWMNumberr, EQEPNumberr, GPIONumberHigh,
              GPIONumberLow) {
                offset = myDCMOTOR1.getAngle();
              }
  void DC1_Callback(const std_msgs::String::ConstPtr& msg) {
    std::stringstream ss;
    ss.str(msg->data.c_str());
    int temp = 0;
    ss >> temp;
    std::cout << "Setting to " << temp << std::endl;
    myDCMOTOR1.setPWMDutyCycle(temp);
  }
  void enable(){
    myDCMOTOR1.enable(1);
  }
  int getAngle(){
      return myDCMOTOR1.getAngle() - offset;
  }
};

int main(int argc, char **argv) {
  ros::init(argc, argv, "DC1_node");
  DC1 myDC1(0, 0, 0, 30, 60); // INPUTS IN PROGRESS
  myDC1.enable();
  ros::NodeHandle nh;
  ros::Rate loop_rate(60);

  ros::Publisher pub = nh.advertise<std_msgs::String>("q1", 1000);
  ros::Subscriber sub = nh.subscribe("u1", 1000, &DC1::DC1_Callback, &myDC1);

  while (ros::ok()) {

    std_msgs::String msg;

    std::stringstream ss;

    ss << myDC1.getAngle();
    msg.data = ss.str();

    pub.publish(msg);

    ros::spinOnce();
    loop_rate.sleep();
  }
}
