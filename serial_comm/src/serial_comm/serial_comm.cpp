#include <serial_comm/serial_comm.h>

namespace serial_comm {

  SerialComm::SerialComm(){
    // default constructor
  }

  SerialComm::SerialComm(std::string port, uint32_t baudrate)
  {
    serial_.setBaudrate(baudrate);
    serial_.setPort(port);
    init();
  }

  SerialComm::~SerialComm(){
    serial_.close();
    serial_.~Serial();
  }

  void SerialComm::setBaudrate(uint32_t baudrate){
    serial_.setBaudrate(baudrate);
  }

  uint32_t SerialComm::getBaudrate(){
    return serial_.getBaudrate();
  }

  void SerialComm::setPort(std::string port){
    serial_.setPort(port);
  }

  std::string SerialComm::getPort(){
    return serial_.getPort();
  }

  void SerialComm::init(){
    serial_.setBaudrate(baudrate_);
    serial_.setPort(port_);

    try{
      serial_.open();
    } catch (serial::SerialException e){
      ROS_ERROR_STREAM(e.what());
      return;
    } catch (serial::IOException e){
      ROS_ERROR_STREAM(e.what());
      return;
    }
    is_initialized_ = true;
  }

  std::string SerialComm::read(){
    if( serial_.available() ){
      return serial_.readline();
    }
  }

  bool SerialComm::write(std::string data){
    return serial_.write(data) == data.size();
  }

}
