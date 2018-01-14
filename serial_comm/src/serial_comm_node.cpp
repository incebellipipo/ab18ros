#include <serial_comm/serial_comm.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "serial_comm");

  serial_comm::SerialComm serial_comm();

  return 0;
}
