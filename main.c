#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>



void genRand(int * array) {
    int fd = open("/dev/random", O_RDONLY);
    int index;
    for(index = 0; index < 10; index++) {
        read(fd, &array[index], sizeof(int));
    }
    close(fd);

    //return randNum;

}

int main() {
    //populate
    int * ary1 = malloc(10 * sizeof(int));
    int index;
    printf("Generating random numbers: \n");
    genRand(ary1);
    for (index = 0; index < 10; index++) {
        printf("\trandom %i: %i\n", index, ary1[index]);
    }
    
    printf("Writing numbers to file...\n");
    int fd = open("a.txt", O_WRONLY);
    int bytes_written = write(fd, ary1, 10 * sizeof(int));
    close(fd);

    printf("Reading numbers from file...\n");
    int fd2 = open("a.txt", O_RDONLY);
    int * ary2 = malloc(10 * sizeof(int));
    int bytes_read = read(fd2, ary2, 10 * sizeof(int));
    close(fd2);

    printf("Verification that written values were the same:\n");
    int i;
    for(; i < 10; i++) {
        printf("\t random %i: %i\n", i, ary2[i]);
    }

    free(ary1);
    free(ary2);
    return 0;
}
