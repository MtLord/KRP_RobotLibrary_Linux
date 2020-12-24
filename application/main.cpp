#include "RobotTimer.hpp"
#include "LowlayerHandel.hpp"
#include <stdio.h>
bool RobotTimer::intflag = false;
int main()
{
    LowlayerHandelTypedef hlow;
    RobotTimer tim;
    //hlow.PS3.Begin();
    tim.Init(5);
    tim.Start();
    while (1)
    {
        if (RobotTimer::intflag)
        {
            /*********usercode begin***********/
            // hlow.M1.SetVelocity(17.4);
            // hlow.M2.SetVelocity(0.34);
            //hlow.Air1.close();
            //hlow.Ad1.SendRequest();
            //hlow.M1.SetDuty(30.2);
            //hlow.BR1.SetDuty(35.6);
            //hlow.Msw1.SendRequest();
            //printf("sw1:%d sw6:%d\n", hlow.Msw1.GetPush(), hlow.Msw6.GetPush());

            /***********usercode end******************/
            RobotTimer::intflag = false;
        }
    }

    return 0;
}