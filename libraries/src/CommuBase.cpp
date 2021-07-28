#include "CommuBase.hpp"

int CommuBase::SetReceevieData() //現在値の返却があるまでループ
{
    GetByte();
    orderid = rxbuf[1];
    actuid = rxbuf[2];
    ((unsigned char *)&data)[0] = rxbuf[3];
    ((unsigned char *)&data)[1] = rxbuf[4];
    ((unsigned char *)&data)[2] = rxbuf[5];
    ((unsigned char *)&data)[3] = rxbuf[6];
    return 0;
}

int CommuBase::SetReceevieData16()
{
    GetByte();
    orderid = rxbuf[1];
    actuid = rxbuf[2];
    ((unsigned char *)&data_s1)[0] = rxbuf[3];
    ((unsigned char *)&data_s1)[1] = rxbuf[4];
    ((unsigned char *)&data_s2)[0] = rxbuf[5];
    ((unsigned char *)&data_s2)[1] = rxbuf[6];
    return 0;
}

int CommuBase::SetSendData(int cmd, short comid, float data, unsigned char Len)
{
    txbuff[0] = cmd;   //命令パケット
    txbuff[1] = comid; //アクチュエータid
    for (int i = 0; i < Len; i++)
    {
        txbuff[i + 2] = ((unsigned char *)&data)[i];
    }

    size = Send(txbuff, Len + 2);

    return 0;
}

int CommuBase::SetSendData(int cmd, short comid, short data, unsigned char Len)
{
    txbuff[0] = cmd;   //命令パケット
    txbuff[1] = comid; //アクチュエータid
    for (int i = 0; i < Len; i++)
    {
        txbuff[i + 2] = ((unsigned char *)&data)[i];
    }

    Send(txbuff, Len + 2);

    return 0;
}