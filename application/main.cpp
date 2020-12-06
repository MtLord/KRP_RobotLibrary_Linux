#include "RobotTimer.hpp"
#include "LowlayerHandel.hpp"
bool RobotTimer::intflag = false;
int main()
{
    LowlayerHandelTypedef hlow;
    RobotTimer tim;
    tim.Init(5);
    tim.Start();

    while (1)
    {
        if (RobotTimer::intflag)
        {
            /*********usercode begin***********/

            hlow.loca->SendReqest();
            /***********usercode end******************/
            RobotTimer::intflag = false;
        }
    }

    return 0;
}