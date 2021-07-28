#include "RobotTimer.hpp"
#include "LowlayerHandel.hpp"
#include <stdio.h>
bool RobotTimer::intflag = false;
int main(int argc, char **argv)
{
    LowlayerHandelTypedef hlow;
    RobotTimer tim;
    //hlow.PS3.Begin();

    tim.Init(5);
    tim.Start();
    hlow.Air1.open();
    hlow.M1.SetVelocity(20);
    hlow.M2.SetVelocity(20);
    hlow.Air2.close();
    hlow.M3.SetVelocity(40);
    hlow.M4.SetVelocity(30);
    while (1)
    {
        if (RobotTimer::intflag)
        {
            /*********usercode begin***********/
            //printf("x:%f y:%f yaw:%f count:%d\n", hlow.loca->GetX(), hlow.loca->GetY(), hlow.loca->GetYaw(), count);
            //printf("sw1:%d\n", hlow.Msw1.GetPush());
            /***********usercode end******************/
            // hlow.Ad1.SendRequest();
            // hlow.Msw1.SendRequest();
            //hlow.M1.SetVelocity(20);
            //hlow.loca->SendReqest();
            // hlow.encoder1.Sendreqest();

            RobotTimer::intflag = false;
        }
    }

    return 0;
}