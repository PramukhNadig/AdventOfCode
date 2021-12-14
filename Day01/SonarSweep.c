#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
* count the number of times a depth measurement increases from the previous measurement. 
* (There is no measurement before the first measurement.) 
 */

int main(int argc, char **argv) {

    if(argc < 2) {
        printf("usage ./SonarSweep [path]\n");
        exit(1);
    }
    
    //Open path and file
    char *path = argv[1];
    FILE *fp = fopen(path, "r");

//Could not open the file, print message and exit.
if(fp == NULL) {
    printf("Could not open file \"%s\"\n", argv[1]);
    fclose(fp);
    exit(1);
    }

    int count = 0, curr;
    char line[1024];
    fgets(line, 1024, fp);
    sscanf(line, "%d", &curr);
    while(fgets(line, 1024, fp) != NULL){
        int i;
        sscanf(line, "%d", &i);
        if(i > curr) {
            count++;
        }
        curr = i;
    }

    fclose(fp);
    printf("%d\n", count);
    return 0;
}