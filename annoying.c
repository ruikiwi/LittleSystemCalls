
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void alrm_handler() {
        time_t curr_time  = time(NULL);
        char* curr_time_str = ctime(&curr_time);
        printf("current time is %s", curr_time_str);

        alarm(3);
}

int main () {

        struct sigaction act;
        memset (&act, 0, sizeof(act));
        act.sa_handler = & alrm_handler;
        act.sa_flags = 0;
        if ( sigaction (SIGALRM, &act, NULL) != 0)
                exit(1);

        printf("Date will be printed every 3 seconds \n");
        printf("Enter ^C to end the program: \n");
        alarm(3);
        while (1) {
        }

}
