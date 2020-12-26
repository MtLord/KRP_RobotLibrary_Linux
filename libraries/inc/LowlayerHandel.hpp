#ifndef ROBOT_HPP_
#define ROBOT_HPP_
/*******include heders*******************/
#include "CommuBase.hpp"
#include "MotorSystem.hpp"
#include "Localization.hpp"
#include "Aircylinder.hpp"
#include "Sensor.hpp"
#include "RotaryEncoder.hpp"
#include "Motor.hpp"
#include "Joystic.hpp"
#include "TcpLib.hpp"
struct LowlayerHandelTypedef
{
private:
    CommuBase serial;
    OddmePose oddm;

public:
    OddmePose *loca;
    MotorSystem M1, M2, M3, M4, M5, M6, M7, M8;
    Motor SM1, SM2, SM3, SM4, SM5, SM6, SM7, SM8, BR1, BR2;
    Aircylinder Air1, Air2, Air3, Air4, Air5, Air6, Air7, Air8;

    Encoder encoder1, encoder2, encoder3, encoder4;
    Joystic PS3;
    Sensor Ad1, Ad2, Ad3, Ad4, Ad5, Ad6;
    MicroSw Msw1, Msw2, Msw3, Msw4, Msw5, Msw6, Msw7;
    LowlayerHandelTypedef() : oddm(&serial), loca(&oddm), M1(&serial, 1), M2(&serial, 2), M3(&serial, 3), M4(&serial, 4), M5(&serial, 5), M6(&serial, 6), M7(&serial, 7), M8(&serial, 8),
                              SM1(&serial, 1), SM2(&serial, 2), SM3(&serial, 3), SM4(&serial, 4), SM5(&serial, 5), SM6(&serial, 6), SM7(&serial, 7), SM8(&serial, 8), BR1(&serial, 17), BR2(&serial, 18),
                              Air1(&serial, 1), Air2(&serial, 2), Air3(&serial, 3), Air4(&serial, 4), Air5(&serial, 5), Air6(&serial, 6), Air7(&serial, 7), Air8(&serial, 8),
                              encoder1(&serial, 0, 1), encoder2(&serial, 1, 1), encoder3(&serial, 2, 1), encoder4(&serial, 3, 1), PS3(),
                              Ad1(&serial, 0), Ad2(&serial, 1), Ad3(&serial, 2), Ad4(&serial, 3), Ad5(&serial, 4), Ad6(&serial, 5),
                              Msw1(&serial, 0, 1), Msw2(&serial, 1, 1), Msw3(&serial, 2, 1), Msw4(&serial, 3, 1), Msw5(&serial, 4, 1), Msw6(&serial, 5, 1), Msw7(&serial, 6, 1)
    {
    }
};

#endif /* ROBOT_HPP_ */