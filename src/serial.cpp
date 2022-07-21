/**
 * \author Prakarn Jaroonsorn (PrakarnJ@arv.co.th)
 * \copyright Copyright (c) 2020, AI and Robotics Ventures Co., Ltd.
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of AI and Robotics Ventures Co., Ltd. and its suppliers, if any.
 */
#include<serial.hpp>

namespace serial_communication{
    SerialCommunication::SerialCommunication()
    {
        port_name = "/dev/ttyUSB0";
        uart_open();
    }
    SerialCommunication::~SerialCommunication()
    {
        uart_close();
    }
    void SerialCommunication::get_portname(std::string name)
    {
        port_name = name;
    }
    void SerialCommunication::uart_open()
    {
		if(port_name.empty()) {
			printf("Attempted to open file when file path has not been assigned to.");
		}

        serial_port = open(port_name.c_str(), O_RDWR);
        if (serial_port < 0) 
        {
            printf("Error %i from open: %s\n", errno, strerror(errno));
        }
        else{
            printf("Connect Success\n");
        }

        state_ = State::OPEN;
    }
    void SerialCommunication::uart_close()
    {
        if(serial_port != -1) {
            auto ret = close(serial_port);
            if(ret != 0)
                printf("Tried to close serial port %s but close() failed.", port_name);

            serial_port = -1;
        }

        state_ = State::CLOSED;
    }
    void SerialCommunication::uart_write(const std::string& data)
    {
        if(state_ != State::OPEN)
            printf("Please call Open() first.");

		if(serial_port < 0) {
            printf("called but file descriptor < 0, indicating file has not been opened.");
		}

		int writeResult = write(serial_port, data.c_str(), data.size());

		// Check status
		if (writeResult == -1) {
			printf("Write error");
		}        
    }
    void SerialCommunication::uart_read()
    {
        printf("uart_read\n");
		if(serial_port == 0) {
			printf("Read() was called but file descriptor (fileDesc) was 0, indicating file has not been opened.");
		}
		int n = read(serial_port, &read_buf, sizeof(read_buf));

		if(n < 0) {
            printf("Cannot read data");
		}

        printf("data: %s\n", read_buf);

    }
}