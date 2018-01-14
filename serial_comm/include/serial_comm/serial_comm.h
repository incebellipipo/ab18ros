#ifndef SERIAL_COMM_H_
#define SERIAL_COMM_H_

#include <ros/ros.h>
#include <serial/serial.h>
#include <iostream>
#include <vector>

namespace serial_comm {

  class SerialComm{
    public:
      SerialComm();
      SerialComm(std::string port, uint32_t baudrate);
      ~SerialComm();

      void init();

      void setBaudrate(uint32_t baudrate);
      uint32_t getBaudrate();

      void setPort(std::string port);
      std::string getPort();

      std::string read();
      bool write(std::string data);

    private:
      std::string       port_;
      uint32_t          baudrate_;
      bool              is_initialized_;
      serial::Serial    serial_;
  };
}

#endif
