#include<sys/types.h>
#include<stdio.h>
#ifndef _UNISTD_H

#define _UNISTD_H
#include <io.h>
#include <process.h>
#endif /* _UNISTD_H */
int data = 0;
int uEntry(void)
{
    int ret = fork();
    int i = 8;
    if (ret == 0)
    {
        data = 2;
        while (i != 0)
        {
            i--;
            printf("Child Process: Pong %d, %d;\n", data, i);
            sleep(128);
        }
        exit(2);
    }
    else if(ret != -1)
    {
        data = 1;
        while (i != 0)
        {
            i--;
            printf("Father Process: Ping %d, %d;\n", data, i);
            sleep(128);
        }
        exec("/usr/print\0", 0);
        exit(1);
    }
    while (1)
        ;
    return 0;
}
