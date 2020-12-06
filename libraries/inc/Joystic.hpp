#ifndef _JOYSTIC_HPP_
#define _JOYSTIC_HPP_

class Joystic
{
private:
    short Data[8] = {
        0,
    };
    short Maskbyte(int matrixnum, int shiftnum);

public:
    void SetconData();
    void SendRequest();
    void begin();
    short SELECT();
    short L3();
    short R3();
    short START();
    short UP();
    short RIGHT();
    short DOWN();
    short LEFT();
    short L2();
    short R2();
    short L1();
    short R1();
    short SANKAKU();
    short MARU();
    short BATSU();
    short SHIKAKU();
    short ANALOG_RIGHT_X();
    short ANALOG_RIGHT_Y();
    short ANALOG_LEFT_X();
    short ANALOG_LEFT_Y();
};

#endif