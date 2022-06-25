#include "termcolor.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SEARCH_SIZE 10000

char ZEROARRAY[SEARCH_SIZE] = {0};

void ray_detected() {
    time_t mytime = time(NULL);
    char *time_str = ctime(&mytime);
    time_str[strlen(time_str) - 1] = '\0';

    cprint("A cosmic ray has been detected! ", FG_GREEN);
    printf("%s\n", time_str);
}

void start() {
    time_t mytime = time(NULL);
    char *time_str = ctime(&mytime);
    time_str[strlen(time_str) - 1] = '\0';

    printf("Cosmic Ray Detector... %s\n", time_str);
}

int main() {
    start();

    while (1) {
        for (int i = 0; i < SEARCH_SIZE; i++) {
            if (ZEROARRAY[i]) {
                ray_detected();
            }
        }
    }

    // somehow the while loop got broken
    ray_detected();

    return 0;
}
