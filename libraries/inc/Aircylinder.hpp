#ifndef AIRCYLINDER_AIRCYLINDER_HPP_
#define AIRCYLINDER_AIRCYLINDER_HPP_
#include "CommuBase.hpp"

class Aircylinder
{
    CommuBase *serial;
    short nodeID;
    short senddata = 0;
    unsigned char len = 4;

public:
    void open();
    void close();
    Aircylinder(CommuBase *_serial, short ID) : serial(_serial), nodeID(ID)
    {
    }
    void SetOrder(int order);
};

#endif