#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#define BUFFERSIZE 100

int counter;

//set up the handler for SIGFPE
void handler () {
	printf("Error: a division by 0 operation was attempted.\n"
			"Total number of operations completed: %d\n"
			"The program will be stopped.\n", counter);
	exit(0);
}

//main function starts
int main() {
	int first, second;
	int ans, remainder;
	char buffer[BUFFERSIZE];
	//install SIGFPE handler
	struct sigaction act;
	memset ( &act, 0, sizeof(act) );
	act.sa_handler = &handler;
	act.sa_flags = 0;
	if ( sigaction (SIGFPE, &act, NULL) != 0 )
		exit(1);
	while (1) {
		//get the first int
		printf("Enter first integer: ");
		if (fgets(buffer, BUFFERSIZE , stdin) != NULL)
			first = atoi(buffer);
		else
			exit(1);
		//get the second int
		printf("Enter second integer: ");
		if (fgets(buffer, BUFFERSIZE , stdin) != NULL)
			second = atoi(buffer);
		else
			exit(1);
		//perform the calculation
		ans = first / second;
		remainder = first % second;
		counter++;
		printf("%d / %d is %d with a remainder of %d \n", first, second, ans, remainder);
	}
	return 0;
}
