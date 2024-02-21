#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>
#include<sys/wait.h>
#include <fcntl.h>
#include<math.h>




void main()
{
    int fd;
        
  
    printf("Cinque numeri casuali tra 0 e 99:\n");
    int numeri [5];
  
    for (int i = 0; i<5; i++) {
        numeri[i]= rand() % 100; // genera un numero casuale compreso tra 0 e 99
        printf("%d\n", numeri[i]);
        
        
    }
         fd = open("myfifo", O_WRONLY);
        write(fd, numeri, sizeof(numeri));
        close(fd);
}