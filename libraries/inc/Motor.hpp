#ifndef MOTOR_MOTOR_HPP_
#define MOTOR_MOTOR_HPP_
#include "CommuBase.hpp"

class Motor
{
    CommuBase *serial;
    unsigned short node_id;

public:
    Motor(CommuBase *_serial, unsigned short _node_id) : serial(_serial), node_id(_node_id)
    {
    }
    void SetDuty(float duty);
};

#endif /* MOTOR_MOTOR_HPP_ */