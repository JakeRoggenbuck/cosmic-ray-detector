#include "termcolor.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

#define SEARCH_SIZE 1000

char ZEROARRAY[SEARCH_SIZE] = {0};

void ray_detected() {
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    char *time_str = asctime(timeinfo);
    time_str[strlen(time_str) - 1] = '\0';

    printf("%s - ", time_str);
    cprint("A cosmic ray has been detected!\n", FG_GREEN);
}

int main() {
    printf("Cosmic Ray Detector...\n");

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
