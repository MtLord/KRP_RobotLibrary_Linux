#ifndef ENCODER_ROTARYENCODER_HPP_
#define ENCODER_ROTARYENCODER_HPP_

#include "CommuBase.hpp"

class Encoder
{
    CommuBase *serial;
    unsigned short board_ID;
    int enco_num;
    static long countdata[8];
    float dist = 0;
    short requestdata = 0;
    unsigned char requestlen = 0;

public:
    Encoder(CommuBase *_serial, int num, unsigned char ID) : serial(_serial), board_ID(ID), enco_num(num)
    {
    }
    void Sendreqest();
    float GetDistance(float d, float count); //(ギアのピッチ円直径,一周あたりのカウント量)
    long GetCount();
};

#endif /* ENCODER_ROTARYENCODER_HPP_ */