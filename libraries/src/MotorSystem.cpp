#include "MotorSystem.hpp"
#include "MotorSystemDefintion.hpp"
#include <stdio.h>
void MotorSystem::SetDuty(float d)
{
    serial->SetSendData(SET_DUTY, this->commuincationID, d, datanum);
}

void MotorSystem::SetVelocity(float v)
{
    serial->SetSendData(SET_VELOCITY, this->commuincationID, v, datanum);
}

void MotorSystem::SetTorque(float q)
{
    serial->SetSendData(SET_TORQUE, this->commuincationID, q, datanum);
}

void MotorSystem::begin()
{
    printf("Motor%d Intialize Start!\n", this->commuincationID);
    serial->SetSendData(BEGIN, this->commuincationID, reqestdata, requestlen);
    serial->SetReceevieData();

    if (serial->orderid == BEGIN && serial->actuid == commuincationID)
    {
        printf("Motor%d Intialize Finish!\n", commuincationID);
    }
    else
    {
        printf("Motor%d Intialize False!\n", commuincationID);
    }
}

void MotorSystem::SetVGAIN_K(float vk)
{
    serial->SetSendData(SET_VGAIN_K, this->commuincationID, vk, datanum);
}

void MotorSystem::SetVGAIN_TI(float ti)
{
    serial->SetSendData(SET_VGAIN_TI, this->commuincationID, ti, datanum);
}

void MotorSystem::SetVGAIN_TD(float td)
{
    serial->SetSendData(SET_VGAIN_TD, this->commuincationID, td, datanum);
}

void MotorSystem::SetPPR(float p)
{
    serial->SetSendData(SET_PPR, this->commuincationID, p, datanum);
}

void MotorSystem::Set_KT(float T)
{
    serial->SetSendData(SET_KT, this->commuincationID, T, datanum);
}

void MotorSystem::SetCGAIN_K(float ck)
{
    serial->SetSendData(SET_CGAIN_K, this->commuincationID, ck, datanum);
}

void MotorSystem::SetCGAIN_TI(float ti)
{
    serial->SetSendData(SET_CGAIN_TI, this->commuincationID, ti, datanum);
}

void MotorSystem::SerCGAIN_TD(float td)
{
    serial->SetSendData(SET_CGAIN_TD, this->commuincationID, td, datanum);
}

float MotorSystem::GetVelocity()
{

    serial->SetSendData(GET_VELOCITY, this->commuincationID, reqestdata, requestlen);
    serial->SetReceevieData();
    if (serial->orderid == GET_VELOCITY && serial->actuid == commuincationID)
    {
        return serial->data;
    }
    else
    {
        return -1;
    }
}

float MotorSystem::GetDuty()
{
    serial->SetSendData(GET_DUTY, this->commuincationID, reqestdata, requestlen);
    serial->SetReceevieData();
    if (serial->orderid == GET_DUTY && serial->actuid == commuincationID)
    {
        return serial->data;
    }
    else
    {
        return -1;
    }
}

float MotorSystem::GetCurrent()
{
    serial->SetSendData(GET_CURRENT, this->commuincationID, reqestdata, requestlen);
    serial->SetReceevieData();
    if (serial->orderid == GET_CURRENT && serial->actuid == commuincationID)
    {
        return serial->data;
    }
    else
    {
        return -1;
    }
}

float MotorSystem::GetTorque()
{
    serial->SetSendData(GET_TORQUE, this->commuincationID, reqestdata, requestlen);
    serial->SetReceevieData();
    if (serial->orderid == GET_TORQUE && serial->actuid == commuincationID)
    {
        return serial->data;
    }
    else
    {
        return -1;
    }
}

void MotorSystem::SetVcc(float c)
{
    serial->SetSendData(SET_VCC, this->commuincationID, c, datanum);
}
