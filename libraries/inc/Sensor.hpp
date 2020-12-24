#ifndef SENSOR_SENSOR_HPP_
#define SENSOR_SENSOR_HPP_
#include "CommuBase.hpp"
class Sensor
{
    CommuBase *serial;
    int num;
    short requestdata = 0;
    unsigned char requestlen = 4;

public:
    Sensor(CommuBase *_serial, int _num) : serial(_serial), num(_num)
    {
    }
    void SendRequest();
    void SetData();
    static unsigned short sensordata[6];
    unsigned short GetValue();
};

class MicroSw
{
    CommuBase *serial;
    int conenum;
    int boardnum;
    unsigned char rxbuff[8];
    short requestdata = 0;
    unsigned char requestlen = 4;

public:
    MicroSw(CommuBase *_serial, int _conenum, int brnum) : serial(_serial), conenum(_conenum), boardnum(brnum) //(CAN handle,connection number,board number)
    {
    }
    static unsigned char Data[4];
    void SetData();
    void SendRequest();
    int GetPush();
};

#endif /* SENSOR_SENSOR_HPP_ */