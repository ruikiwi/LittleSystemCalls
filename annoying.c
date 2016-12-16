#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int counter = 0; //count for how many ^C has been hit

//hander for SIGALRM
void alrm_handler() {
        time_t curr_time  = time(NULL);
        char* curr_time_str = ctime(&curr_time);
        printf("current time is %s", curr_time_str);

        alarm(3);
}

//handler for SIGINT
void ter_handler() {
        //update the counter
        counter++;
        //calculate how many more times need to ^C
        int dif = 5 - counter;
        if (counter == 5) {
                printf("\nFinal control-c caught. Exiting.\n");
                exit(0);
        } else{
                printf("\nControl-c caught. %d more before program ends.\n", dif);
        }
}
int main () {
        //act for SIGALRM, ter_act for SIGINT
        struct sigaction act;
        struct sigaction ter_act;
        memset ( &act, 0, sizeof(act) );
        memset ( &ter_act, 0, sizeof(ter_act));
        //set up
        act.sa_handler = &alrm_handler;
        act.sa_flags = 0;
        if ( sigaction (SIGALRM, &act, NULL) != 0 )
                exit(1);
        ter_act.sa_handler = &ter_handler;
        ter_act.sa_flags = 0;
        if (sigaction(SIGINT, &ter_act, NULL) != 0)
                exit(1);
        printf("Date will be printed every 3 seconds \n");
        printf("Enter ^C 5 times to end the program: \n");
        alarm(3);
        while (1) {
        }

}
~
~
~
~
~
~
~                    
