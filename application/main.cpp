#include "RobotTimer.hpp"

int main()
{
    RobotTimer tim;
    tim.Init(5);
    tim.Start();

    while (1)
    {
        /*********usercode begin***********/

        /***********usercode end******************/
        pause();
    }

    return 0;
}