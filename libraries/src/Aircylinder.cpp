#include "Aircylinder.hpp"
#include "DefineOrder.h"

void Aircylinder::open()
{
    serial->SetSendData(AIR_OPEN, nodeID, this->senddata, this->len);
}

void Aircylinder::close()
{

    serial->SetSendData(AIR_CLOSE, nodeID, this->senddata, this->len);
}
