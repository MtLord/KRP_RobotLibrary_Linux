#include "Localization.hpp"
#include "DefineOrder.h"

/****************localization*****************************************/

void OddmePose::SendReqest()
{
    serial->SetSendData(GET_LOCA, id_x, requestdata, requestlen); //x send request
    serial->SetReceevieData();
    if ((serial->orderid == GET_LOCA) && serial->actuid == id_x)
    {
        this->currentX = serial->data;
    }

    serial->SetSendData(GET_LOCA, id_y, requestdata, requestlen); //y send request
    serial->SetReceevieData();
    if ((serial->orderid == GET_LOCA) && serial->actuid == id_y)
    {
        this->currentY = serial->data;
    }

    serial->SetSendData(GET_LOCA, id_yaw, requestdata, requestlen); //yaw send request
    serial->SetReceevieData();
    if ((serial->orderid == GET_LOCA) && serial->actuid == id_yaw)
    {
        this->currentyaw = serial->data;
    }
}

void OddmePose::SetEncoderModef(float x_of_y, float y_of_x)
{
    serial->SetSendData(SET_ENCO_POSE, 0x1, x_of_y, 4);
    serial->SetSendData(SET_ENCO_POSE, 0x2, y_of_x, 4);
}

void OddmePose::SetDiameter(float d)
{
    serial->SetSendData(SET_ENC_DIAMTER, 0, d, 4);
}

void OddmePose::SetEncPulse(float p)
{
    serial->SetSendData(SET_ENCO_PULSE, 0, p, 4);
}

float OddmePose::GetX()
{
    return currentX;
}

float OddmePose::GetY()
{

    return currentY;
}

float OddmePose::GetYaw()
{

    return currentyaw;
}