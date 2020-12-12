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

            /***********usercode end******************/
            RobotTimer::intflag = false;
        }
    }

    return 0;
}