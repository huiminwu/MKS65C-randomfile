#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



int genRand() {
    int fd = open("/dev/random", O_RDONLY);
    int * buffer = malloc(sizeof(*buffer));
    int bytes_read = read(fd, buffer, 4);
    printf("Random Num: %i\n", *buffer);
    int randNum = *buffer;
    free(buffer);
    close(fd);
    return randNum;

}

int main() {
    //populate
    int ary[10];
    int index;
    for (index = 0; index < 10; index++) {
        ary[index] = genRand();

    }
    
    int * buffer = malloc(sizeof(*buffer));
    int fd = open("a.txt", O_RDWR);
    int bytes_written = write(fd, ary, 40);
    free(buffer); 
    close(fd);
    
    return 0;
}
