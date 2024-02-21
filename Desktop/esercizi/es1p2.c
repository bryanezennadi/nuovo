#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FIFO_NAME "myfifo"
#define NUM_NUMERI 5

void main() {
    int fd;
    int numeri[NUM_NUMERI];
    int somma = 0;
   
    int i;
    
    // Apri la FIFO in lettura
    fd = open("myfifo",O_RDONLY );
    if (fd == -1) {
        perror("Errore nell'apertura della FIFO");
        exit(EXIT_FAILURE);
    }
    
    // Leggi i numeri dalla FIFO
    read(fd, numeri, sizeof(numeri));
  
    
    // Chiudi la FIFO
    close(fd);
    
    // Somma i numeri letti
    for (i = 0; i < NUM_NUMERI; i++) {
        somma += numeri[i];
    }
    
    // Stampa la somma
    printf("Somma dei numeri: %d\n", somma);
    
   
}
