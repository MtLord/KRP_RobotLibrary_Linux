#ifndef ROBOTTIMRE_HPP_
#define ROBOTTIMRE_HPP_
#include <signal.h>
#include <memory.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <stdio.h>

class RobotTimer
{
private:
    struct sigaction act;
    struct sigaction oldact;
    timer_t tid;
    struct itimerspec itval;

public:
    static bool intflag;
    RobotTimer()
    {
        memset(&act, 0, sizeof(struct sigaction));
    }
    virtual ~RobotTimer()
    {
        timer_delete(tid);
        sigaction(SIGALRM, &oldact, NULL); //シグナルハンドラを元に戻す
    }

    static void timer_handler(int signum)
    {
        intflag = true;
    }
    int Init(int period_ms)
    {
        act.sa_handler = timer_handler; //関数へのポインタを入れておく
        act.sa_flags = SA_RESTART;

        if (sigaction(SIGALRM, &act, &oldact) < 0) //SIGALRM:タイマーシグナル
        {
            perror("sigaction error!\n");
            return -1;
        }
        if (timer_create(CLOCK_REALTIME, NULL, &tid) < 0) //タイマーの作成
        {
            perror("timer_create error!\n");
            return -1;
        }
        itval.it_value.tv_sec = 0; //初回は1秒後
        itval.it_value.tv_nsec = 10;
        //インターバルタイマー
        itval.it_interval.tv_sec = 0;
        itval.it_interval.tv_nsec = period_ms * 1000000; //制御周期ms
        return 0;
        //タイマーをtidに設定してタイマーをセット
    }
    int Start()
    {
        if (timer_settime(tid, 0, &itval, NULL) < 0)
        {
            perror("timer_settime");
            return -1;
        }
        return 0;
    }
};

#endif