#ifndef ROBOTSERIAL_HPP_
#define ROBOTSERIAL_HPP_

#include <termios.h>

class RobotSerial
{
private:
    int fd;
    unsigned char getchar;
    int STB_RECIEVED = 0;
    struct termios tio;      // シリアル通信設定
    int baudRate = B1000000; //1Mbps

    unsigned char get_serial_char();

public:
    RobotSerial()
    {
    }
    virtual ~RobotSerial();
    int GetByte();
    unsigned char rxbuf[8] = {
        0,
    };

protected:
    int PortConfig();

    int Send(unsigned char *buf, short size);
};

#endif