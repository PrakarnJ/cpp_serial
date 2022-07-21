/**
 * \author Prakarn Jaroonsorn (PrakarnJ@arv.co.th)
 * \copyright Copyright (c) 2020, AI and Robotics Ventures Co., Ltd.
 * All Rights Reserved.
 *
 * NOTICE:  All information contained herein is, and remains
 * the property of AI and Robotics Ventures Co., Ltd. and its suppliers, if any.
 */
#include <serial.hpp>

using namespace serial_communication;

int main()
{
    SerialCommunication s;
    while (1)
    {
        s.uart_read();
        sleep(1);
    }
}