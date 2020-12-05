#ifndef ROBOTSERIAL_HPP_
#define ROBOTSERIAL_HPP_

#include <termios.h>

class RobotSerial
{
private:
    int fd;
    unsigned char getchar;
    int STB_RECIEVED = 0;
    unsigned char rxrbuf[8];
    struct termios tio;      // シリアル通信設定
    int baudRate = B2000000; //2Mbps
    unsigned char rxbuf[8] = {
        0,
    };
    unsigned char get_serial_char();

public:
    RobotSerial()
    {
    }
    virtual ~RobotSerial();
    int GetByte(int byte, unsigned char *buf);

protected:
    int PortConfig();

    int Send(unsigned char *buf, short size);
};

#endif