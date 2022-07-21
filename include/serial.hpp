/**
 * \author Prakarn Jaroonsorn (PrakarnJ@arv.co.th)
 * \copyright Copyright (c) 2020, AI and Robotics Ventures Co., Ltd.
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of AI and Robotics Ventures Co., Ltd. and its suppliers, if any.
 */
#ifndef CPP_SERIAL_COMMUNICATION_HPP_
#define CPP_SERIAL_COMMUNICATION_HPP_

// C library headers
#include <stdio.h>
#include <string.h>
#include <iostream>

// Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

namespace serial_communication{
    /// \brief      Represents the state of the serial port.
    enum class State {
        CLOSED,
        OPEN,
    };

    class SerialCommunication
    {
    private:
        std::string port_name; 
        int serial_port;
        char read_buf[256];
        State state_;
    public:
        SerialCommunication();
        ~SerialCommunication();
        void get_portname(std::string name);
        void uart_open();
        void uart_close();
        void uart_write(const std::string& data);
        void uart_read();
    };
    
}

#endif /* CPP_SERIAL_COMMUNICATION_HPP_ */
