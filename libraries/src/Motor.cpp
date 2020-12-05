#include "Motor.hpp"
#include "DefineOrder.h"

void Motor::SetDuty(float duty)
{
    serial->SetSendData(MOTORE_SET_DUTY, node_id, duty, 4);
}