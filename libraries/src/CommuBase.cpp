#include "CommuBase.hpp"

int CommuBase::SetReceevieData() //現在値の返却があるまでループ
{
    GetByte(7, rxbuff);
    orderid = (rxbuff[1] >> 4) & 0xf;
    actuid = (rxbuff[1]) & 0xf;
    ((unsigned char *)&data)[0] = rxbuff[2];
    ((unsigned char *)&data)[1] = rxbuff[3];
    ((unsigned char *)&data)[2] = rxbuff[4];
    ((unsigned char *)&data)[3] = rxbuff[5];
    return 0;
}

int CommuBase::SetReceevieData16()
{
    GetByte(7, rxbuff);
    orderid = (rxbuff[1] >> 4) & 0xf;
    actuid = (rxbuff[1]) & 0xf;
    ((unsigned char *)&data_s1)[0] = rxbuff[2];
    ((unsigned char *)&data_s1)[1] = rxbuff[3];
    ((unsigned char *)&data_s2)[0] = rxbuff[4];
    ((unsigned char *)&data_s2)[1] = rxbuff[5];
    return 0;
}

int CommuBase::SetSendData(int cmd, short comid, float data, unsigned char Len)
{
    txbuff[0] = cmd << 4 | comid; //命令パケット
    for (int i = 0; i < Len; i++)
    {
        txbuff[i + 1] = ((unsigned char *)&data)[i];
    }
    if (Len == 0)
    {
        Send(&txbuff[0], 1);
    }
    else
    {
        Send(txbuff, Len + 1);
    }
    return 0;
}

int CommuBase::SetSendData(int cmd, short comid, short data, unsigned char Len)
{
    txbuff[0] = cmd << 4 | comid; //命令パケット
    for (int i = 0; i < Len; i++)
    {
        txbuff[i + 1] = ((unsigned char *)&data)[i];
    }
    if (Len == 0)
    {
        Send(&txbuff[0], 1);
    }
    else
    {
        Send(txbuff, Len + 1);
    }
    return 0;
}