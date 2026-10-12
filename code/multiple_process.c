#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TASK_CNT 3


// 一父多子架构
int main()
{
    int i;
    pid_t pid[TASK_CNT]; // 存放所有子进程的 PID

    for(i = 0; i < TASK_CNT; i++)
    {
        pid[i] = fork();

        if(pid[i] < 0)
        {
            perror("fork fail");
            exit(EXIT_FAILURE);
        }

        if(pid[i] == 0) break;
    }

    // 给父进程和子进程安排不同任务
    if(i == 0)
    {
        // 0 号子进程需要执行的任务
        sleep(1);

    }
    else if(i == 1)
    {
        // 1 号子进程执行的任务
        sleep(1);
    }
    // .....
    else if(i == TASK_CNT)
    {
        // 父进程不承担普通任务处理，专门负责管理所有子进程

        // 等待所有子进程结束，并统计时间
        time_t start_time, end_time;

        time(&start_time);

        while(i--) wait(NULL);

        time(&end_time);

        printf("共耗时：%ld秒\n", end_time - start_time);
    }


    return 0;
}


// 任务函数
void task0(void)
{

}

