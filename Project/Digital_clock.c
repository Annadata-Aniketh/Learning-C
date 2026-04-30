#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#include<time.h>
int main()
{
    time_t rawtime = 0; //Epoch format
    struct tm *pTime = NULL;
    bool running = true;
    printf("\n--------Digital Clock--------\n");
    time(&rawtime);
    pTime = localtime(&rawtime);
    printf("Date: %02d|%02d|%d\n", (*pTime).tm_mday, (*pTime).tm_mon, (*pTime).tm_year+1900);
    switch(pTime -> tm_wday)
    {
        case 0:
            printf("Day: Sunday\n");
            break;
        case 1:
            printf("Day: Monday\n");
            break;
        case 2:
            printf("Day: Tuesday\n");
            break;
        case 3:
            printf("Day: Wednesday\n");
            break;
        case 4:
            printf("Day: Thursday\n");
            break;
        case 5:
            printf("Day: Friday\n");
            break;
        case 6:
            printf("Day: Saturday\n");
            break;
    }
    printf("Time Zone: %s\n", (*pTime).tm_zone);
    while(running)
    {
        time(&rawtime); 
        //printf("%ld\n", rawtime);
        pTime = localtime(&rawtime);
        printf("\rTime: %02d:%02d:%02d", (*pTime).tm_hour, pTime -> tm_min, (*pTime).tm_sec);
        fflush(stdout); // Flush the output buffer to display immediately
        sleep(1);
    }

    return 0;
}