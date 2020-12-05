#ifndef APPLICATION_LOCALIZATON_HPP_
#define APPLICATION_LOCALIZATON_HPP_
#include "math.h"
#include "CommuBase.hpp"
class OddmePose
{
private:
    short requestdata = 0;
    unsigned char requestlen = 0;

protected:
    CommuBase *serial;
    float diameter = 0.048;
    unsigned short pulse = 2048;
    float ShiftY = 0.26;
    float ShiftX = 0.26;
    float initX = 0;
    float initY = 0;
    const int id_x = 0x1;
    const int id_y = 0x2;
    const int id_yaw = 0x3;
    float currentX = 0;
    float currentY = 0;
    float currentyaw = 0;

public:
    OddmePose(CommuBase *_serial) : serial(_serial)
    {
    }
    void SendReqest(); //send reqest localization
    void Setloca();    //dataset

    virtual float GetX();
    virtual float GetY();
    virtual float GetYaw();
    void SetEncoderModef(float x_of_y, float y_of_x); //エンコーダの機体中心からのズレを記述
    void SetDiameter(float d);
    void SetEncPulse(short p);
};

#endif