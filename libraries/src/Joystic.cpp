#include "Joystic.hpp"

short Joystic::Maskbyte(int matrixnum, int shiftnum)
{
    return (Data[matrixnum] >> shiftnum) & 0x1;
}

short Joystic::SELECT()
{
    return Maskbyte(0, 0);
}

short Joystic::L3()
{
    return Maskbyte(0, 1);
}

short Joystic::R3()
{
    return Maskbyte(0, 2);
}
short Joystic::START()
{
    return Maskbyte(0, 3);
}
short Joystic::UP()
{
    return Maskbyte(0, 4);
}

short Joystic::RIGHT()
{
    return Maskbyte(0, 5);
}
short Joystic::DOWN()
{
    return Maskbyte(0, 6);
}
short Joystic::LEFT()
{
    return Maskbyte(0, 7);
}

short Joystic::L1()
{
    return Maskbyte(1, 2);
}
short Joystic::R1()
{
    return Maskbyte(1, 3);
}
short Joystic::SANKAKU()
{
    return Maskbyte(1, 4);
}
short Joystic::MARU()
{
    return Maskbyte(1, 5);
}
short Joystic::BATSU()
{
    return Maskbyte(1, 6);
}
short Joystic::SHIKAKU()
{
    return Maskbyte(1, 7);
}
short Joystic::ANALOG_RIGHT_X()
{
    return Data[2];
}
short Joystic::ANALOG_RIGHT_Y()
{
    return Data[3];
}
short Joystic::ANALOG_LEFT_X()
{
    return Data[4];
}
short Joystic::ANALOG_LEFT_Y()
{
    return Data[5];
}

short Joystic::L2()
{
    return Data[6];
}
short Joystic::R2()
{
    return Data[7];
}