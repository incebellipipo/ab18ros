#include <iostream>
#include <ros/ros.h>

int main(int argc, char** argv){

  ros::init( argc, argv,"my_launch_file_example");
  ros::NodeHandle nh("~");


  if(argc < 1){
    std::cout << "you didn't enter any values" << std::endl;
    return 1;
  } else {
    ROS_WARN_STREAM(std::string(argv[1]));
    ROS_WARN_STREAM("name_space: " << ros::this_node::getNamespace());
  }
  
  return 0;
}
