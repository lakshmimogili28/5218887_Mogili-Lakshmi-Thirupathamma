#include <stdio.h>

int main() {
    char time12[11];
    int hour;

    
    scanf("%s", time12);

    sscanf(time12, "%2d", &hour);

    if (time12[8] == 'A' && hour == 12)
        hour = 0;
    else if (time12[8] == 'P' && hour != 12)
        hour += 12;

    printf("%02d:%c%c:%c%c\n", hour, time12[3], time12[4], time12[6], time12[7]);
    return 0;
}