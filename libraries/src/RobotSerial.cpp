
#include "RobotSerial.hpp"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <unistd.h>
#include <signal.h>
#include <iostream>
#include <string>
#include <ctime>
#include <sys/time.h>
#include "cstring"

/***************定義変数群**********************/
#define SERIAL_PORT "/dev/ttyACM0"
#define STB 0x9E
#define ENB 0xFF
/***********************************************/

/**************private*******************************/
unsigned char RobotSerial::get_serial_char()
{
    unsigned char c;
    int les;
    les = read(fd, (char *)&c, 1);
    return c;
}
/*************************************************/

RobotSerial::~RobotSerial()
{
    close(fd); // デバイスのクローズ
    perror("device closed..\n");
}

int RobotSerial::PortConfig()
{
    fd = open(SERIAL_PORT, O_RDWR); // デバイスをオープンする
    if (fd < 0)
    {
        printf("serial port open error\n");
        return -1;
    }
    else
    {
        printf("%s opned\n", SERIAL_PORT);
    }
    memset(&tio, 0, sizeof(tio));
    tio.c_cflag += CREAD;  // 受信有効
    tio.c_cflag += CLOCAL; // ローカルライン（モデム制御なし）
    tio.c_cflag += CS8;    // データビット:8bit
    tio.c_cflag += 0;      // ストップビット:1bit
    tio.c_cflag += 0;      // パリティ:None

    cfsetispeed(&tio, baudRate);
    cfsetospeed(&tio, baudRate);
    cfmakeraw(&tio); // RAWモード

    tcsetattr(fd, TCSANOW, &tio); // デバイスに設定を行う
    ioctl(fd, TCSETS, &tio);      // ポートの設定を有効にする
    printf("port config success\n");
}

int RobotSerial::GetByte()
{
    int i = 0;
    while (1)
    {
        getchar = get_serial_char();
        if (getchar == STB)
        {
            STB_RECIEVED = 1;
        }
        if (STB_RECIEVED == 1)
        {
            rxbuf[i] = getchar;
            i++;
        }
        if (i > 7)
        {
            //buf = rxbuf;
            STB_RECIEVED = 0;
            i = 0;
            break;
        }
    }
    return 0;
}

int RobotSerial::Send(unsigned char *buf, short size)
{
    int s_size = 0;
    s_size = write(fd, buf, size);
    if (s_size == size)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}