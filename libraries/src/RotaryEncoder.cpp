#include "RotaryEncoder.hpp"
#include "DefineOrder.h"
long Encoder::countdata[8] = {
    0,
};

void Encoder::Sendreqest()
{
    serial->SetSendData(GRT_ENCODER_COUNT, 0x1, requestdata, requestlen);
    serial->SetReceevieData16();
    if ((serial->orderid == GRT_ENCODER_COUNT) && (serial->actuid == 0x1))
    {
        countdata[0] = serial->data_s1;
        countdata[1] = serial->data_s2;
    }

    serial->SetSendData(GRT_ENCODER_COUNT, 0x2, requestdata, requestlen);
    serial->SetReceevieData16();
    if ((serial->orderid == GRT_ENCODER_COUNT) && (serial->actuid == 0x2))
    {
        countdata[2] = serial->data_s1;
        countdata[3] = serial->data_s2;
    }
}

float Encoder::GetDistance(float d, float count)
{
    dist = countdata[enco_num] * d / count;
    return dist;
}

long Encoder ::GetCount()
{
    return countdata[enco_num];
}
