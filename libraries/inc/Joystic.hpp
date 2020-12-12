#ifndef _JOYSTIC_HPP_
#define _JOYSTIC_HPP_
#include <linux/joystick.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define BUTTON_DATA_MAX 17
#define STICK_DATA_MAX 7

class Joystic
{
private:
        static int fd;
    static struct js_event event;
    static pthread_mutex_t hmutex; //mutex hunder
    static pthread_t hthread;

public:
    static short ButtonData[BUTTON_DATA_MAX];
    static short StickData[STICK_DATA_MAX];
    ~Joystic()
    {
        close(fd);
    }
    int Begin();
    static void SetconData();
    short SELECT();
    short L3();
    short R3();
    short START();
    short PS();
    short UP();
    short RIGHT();
    short DOWN();
    short LEFT();
    short L2();
    short R2();
    short L1();
    short R1();
    short SANKAKU();
    short MARU();
    short BATSU();
    short SHIKAKU();
    short ANALOG_RIGHT_X();
    short ANALOG_RIGHT_Y();
    short ANALOG_LEFT_X();
    short ANALOG_LEFT_Y();
};

#endif