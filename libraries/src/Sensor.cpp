#include "Sensor.hpp"
#include "DefineOrder.h"
unsigned short Sensor::sensordata[6] = {
    0,
};
unsigned char MicroSw::Data[4] = {
    0,
};

void Sensor::SendRequest()
{
    serial->SetSendData(Get_SENSOR, 0x1, requestdata, requestlen);
    serial->SetReceevieData16();
    if ((serial->orderid == Get_SENSOR) && serial->actuid == 0x1)
    {
        sensordata[0] = serial->data_s1;
        sensordata[1] = serial->data_s2;
    }

    serial->SetSendData(Get_SENSOR, 0x2, requestdata, requestlen);
    serial->SetReceevieData16();
    if ((serial->orderid == Get_SENSOR) && serial->actuid == 0x2)
    {
        sensordata[2] = serial->data_s1;
        sensordata[3] = serial->data_s2;
    }

    serial->SetSendData(Get_SENSOR, 0x3, requestdata, requestlen);
    serial->SetReceevieData16();
    if ((serial->orderid == Get_SENSOR) && serial->actuid == 0x3)
    {
        sensordata[4] = serial->data_s1;
        sensordata[5] = serial->data_s2;
    }
}

unsigned short Sensor::GetValue()
{
    return sensordata[num];
}

void MicroSw::SendRequest()
{

    serial->SetSendData(GET_MICROSWITCH, boardnum, requestdata, requestlen);

    this->SetData();
}

void MicroSw::SetData()
{
    serial->GetByte();
    if (serial->rxbuf[2] == 1)
    {
        Data[0] = serial->rxbuf[3];
    }
    else if (serial->rxbuf[2] == 2)
    {
        Data[1] = serial->rxbuf[4];
    }
}

int MicroSw::GetPush()
{
    if (boardnum == 1)
    {
        return (Data[0] >> conenum) & 1;
    }
    else if (boardnum == 2)
    {
        return (Data[1] >> conenum) & 1;
    }
}