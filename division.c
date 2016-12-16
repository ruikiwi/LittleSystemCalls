#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define BUFFERSIZE 100

int main() {
        int first;
        int second;
        int counter;
        char buffer[BUFFERSIZE];
        printf("Enter first integer: ");
        while (1) {
                if (fgets(buffer, BUFFERSIZE , stdin) != NULL) {
                        first = atoi(buffer);
                        printf("%d", first);
                }
        }
        return 0;

}
