#include "Joystic.hpp"
short Joystic::ButtonData[BUTTON_DATA_MAX] = {
    0,
};

short Joystic::StickData[STICK_DATA_MAX] = {
    0,
};

int Joystic::fd = 0;
struct js_event Joystic::event;
pthread_mutex_t Joystic::hmutex;
pthread_t Joystic::hthread;

void *ReadConData(void *arg)
{
    while (1)
    {
        Joystic::SetconData();
    }
}

int Joystic::Begin()
{
    fd = open("/dev/input/js0", O_RDONLY);
    if (fd < 3)
    {
        fprintf(stderr, "joystic can not opened\n");
    }
    pthread_mutex_init(&hmutex, NULL);
    if (pthread_create(&hthread, NULL, ReadConData, NULL) != 0)
    {
        return -1;
    }
    return 0;
}

void Joystic::SetconData()
{
    if (read(fd, &event, sizeof(struct js_event)) >= sizeof(struct js_event))
    {
        switch (event.type & 0x7f)
        {
        case JS_EVENT_BUTTON:
            if (event.number < BUTTON_DATA_MAX)
            {
                pthread_mutex_lock(&hmutex);
                ButtonData[event.number] = event.value;
                pthread_mutex_unlock(&hmutex);
            }
            break;
        case JS_EVENT_AXIS:
            if (event.number < STICK_DATA_MAX)
            {
                pthread_mutex_lock(&hmutex);
                StickData[(int)event.number] = (int16_t)(event.value / 128);
                //("stic event num%d\n", event.number);
                pthread_mutex_unlock(&hmutex);
            }
            break;
        }
    }
}

short Joystic::SELECT()
{
    return ButtonData[8];
}

short Joystic::L3()
{
    return ButtonData[11];
}

short Joystic::R3()
{
    return ButtonData[12];
}
short Joystic::START()
{
    return ButtonData[9];
}

short Joystic::PS()
{
    return ButtonData[10];
}

short Joystic::UP()
{
    return ButtonData[13];
}

short Joystic::RIGHT()
{
    return ButtonData[16];
}
short Joystic::DOWN()
{
    return ButtonData[14];
}
short Joystic::LEFT()
{
    return ButtonData[15];
}

short Joystic::L1()
{
    return ButtonData[4];
}
short Joystic::R1()
{
    return ButtonData[5];
}
short Joystic::SANKAKU()
{
    return ButtonData[2];
}
short Joystic::MARU()
{
    return ButtonData[1];
}
short Joystic::BATSU()
{
    return ButtonData[0];
}
short Joystic::SHIKAKU()
{
    return ButtonData[3];
}
short Joystic::ANALOG_RIGHT_X()
{
    return StickData[3];
}
short Joystic::ANALOG_RIGHT_Y()
{
    return StickData[4];
}
short Joystic::ANALOG_LEFT_X()
{
    return StickData[0];
}
short Joystic::ANALOG_LEFT_Y()
{
    return StickData[1];
}

short Joystic::L2()
{
    return StickData[2];
}
short Joystic::R2()
{
    return StickData[5];
}