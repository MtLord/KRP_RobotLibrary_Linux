#ifndef COMMUBASE_HPP_
#define COMMUBASE_HPP_
#include "RobotSerial.hpp"
class CommuBase : public RobotSerial
{
private:
protected:
    unsigned char *rxbuff;
    unsigned char txbuff[8];

public:
    CommuBase()
    {
        PortConfig(); //ポートの初期設定を行う
    }

    float data = 0;
    unsigned short data_s1 = 0;
    unsigned short data_s2 = 0;
    int actuid = 0;
    int orderid = 0;
    int SetSendData(int cmd, short comid, float data, unsigned char Len);
    int SetSendData(int cmd, short comid, short data, unsigned char Len);
    int SetReceevieData();
    int SetReceevieData16();
};

#endif