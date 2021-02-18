#include "RobotTimer.hpp"
#include "LowlayerHandel.hpp"
#include <stdio.h>
bool RobotTimer::intflag = false;
int main(int argc, char **argv)
{
    LowlayerHandelTypedef hlow;
    RobotTimer tim;
    //hlow.PS3.Begin();
    hlow.M1.begin();
    tim.Init(5);
    tim.Start();
    while (1)
    {
        if (RobotTimer::intflag)
        {
            /*********usercode begin***********/

            /***********usercode end******************/
            hlow.Ad1.SendRequest();
            hlow.Msw1.SendRequest();
            hlow.Msw2.SendRequest();
            hlow.loca->SendReqest();
            hlow.encoder1.Sendreqest();
            RobotTimer::intflag = false;
        }
    }

    return 0;
}