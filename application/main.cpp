#include "RobotTimer.hpp"
#include "LowlayerHandel.hpp"
int main()
{
    LowlayerHandelTypedef hlow;
    RobotTimer tim;
    tim.Init(5);
    tim.Start();

    while (1)
    {
        /*********usercode begin***********/

        hlow.loca->SendReqest();
        /***********usercode end******************/
        pause();
    }

    return 0;
}