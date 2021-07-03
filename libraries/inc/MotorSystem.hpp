#ifndef MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_
#define MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_
#include "CommuBase.hpp"

class MotorSystem
{
private:
    unsigned short commuincationID;
    CommuBase *serial;
    unsigned char datanum = 4;

    short reqestdata = 0;
    unsigned char requestlen = 4;

public:
    MotorSystem(CommuBase *_serial, unsigned short ID) : commuincationID(ID), serial(_serial)
    {
    }
    void SetVGAIN_K(float vk);  //速度制御のゲイン
    void SetVGAIN_TI(float ti); //速度制御の積分時間
    void SetVGAIN_TD(float td); //速度制御の微分時間
    void SetCGAIN_K(float ck);  //電流制御のゲイン
    void SetCGAIN_TI(float ti); //電流制御の積分時間
    void SerCGAIN_TD(float td); //電流制御の微分時間

    void SetVelocity(float v); //rad/s
    void SetTorque(float q);   //mNm
    void SetDuty(float d);     //-100%~100%
    void begin();
    void Set_KT(float T); //トルク定数の設定
    void SetVcc(float c);
    void SetPPR(float p); //エンコーダーのパルス数の設定 ppR

    float GetVelocity(); //速度の取得
    float GetTorque();   //トルクの取得
    float GetDuty();     //デューティーの取得
    float GetCurrent();  //電流の取得
    float GetState();    //状態の取得
};

#endif /* MOTORSYSTEM_MOTORSYSTEMCLASS_HPP_ */