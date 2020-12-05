#ifndef ROBOT_HPP_
#define ROBOT_HPP_
/*******include heders*******************/
#include "Libraries/Serial/CommuBase.hpp"
#include "Libraries/MotorSystem.hpp"
#include "Libraries/Localization.hpp"
#include "Libraries/Aircylinder.hpp"
#include "Libraries/Sensor.hpp"
#include "Libraries/RotaryEncoder.hpp"
#include "Libraries/Motor.hpp"

struct LowlayerHandelTypedef
{
public:
    CommuBase serial;
    MotorSystem M0, M1, M2, M3, M4, M5, M6, M7, M8;
    Motor SM1, SM2, SM3, BR1, BR2, BR3;
    Aircylinder Air1, Air2, Air3, Air4, Air5, Air6, Air7, Air8;
    OddmePose *loca;
    OddmePose oddm;
    Encoder encoder1, encoder2, encoder3, encoder4;
    PS3controller PS3;
    Sensor Ad1, Ad2, Ad3, Ad4, Ad5, Ad6;
    MicroSw Msw1, Msw2, Msw3, Msw4, Msw5, Msw6;
    LowlayerHandelTypedef() : M1(&serial, 1), M2(&serial, 2), M3(&serial, 3), M4(&serial, 4), M5(&serial, 5), M6(&serial, 6), M7(&serial, 7), M8(&serial, 8),
                              SM1(&serial, 1), SM2(&serial, 2), SM3(&serial, 3), BR1(&serial, 5), BR2(&serial, 6), BR3(&serial, 7),
                              Air1(&serial, 1), Air2(&serial, 2), Air3(&serial 3), Air4(&serial, 4), Air5(&serial, 5), Air6(&serial, 6), Air7(&serial, 7), Air8(&serial, 8),
                              oddm(&serial), loca(&oddm), encoder1(&serial, 0, 1), encoder2(&serial, 1, 1), encoder3(&serial, 2, 1), encoder4(&serial, 3, 1), PS3(),
                              Ad1(&serial, 0), Ad2(&serial, 1), Ad3(&serial, 2), Ad4(&serial, 3), Ad5(&serial, 4), Ad6(&serial, 5),
                              Msw1(&serial, 0, 1), Msw2(&serial, 1, 1), Msw3(&serial, 2, 1), Msw4(&serial, 3, 1), Msw5(&serial, 4, 1), Msw6(&serial, 5, 1)
    {
    }
};

#endif /* ROBOT_HPP_ */