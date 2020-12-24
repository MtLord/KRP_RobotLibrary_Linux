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
    while (1)
    {
        if (RobotTimer::intflag)
        {
            /*********usercode begin***********/
            //hlow.Ad1.SendRequest();
            //hlow.Msw1.SendRequest();
            //hlow.loca->SendReqest();
            //hlow.encoder1.Sendreqest();
            /***********usercode end******************/
            RobotTimer::intflag = false;
        }
    }

    return 0;
}