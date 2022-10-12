#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "trove.h"
/*Builds new trovefile/index from the given filelist
This will replace any existing trovefile with the same name (??)

Creates trovefile
Overwrites existing trovefile of same name
*/
void create_trovefile()
{
    /* TODO: need to check if we are looking at input trovefile or /tmp/trove */
    FILE *fp;
    
    /* NOTE: File gets overwritten every time it's opened 
    so if issues occur, try changing the mode (w+) */

    /* NOTE: when reading line by line and using fgets(),
    we need to allocate buffer for each line size 
    https://stackoverflow.com/questions/3081289/how-to-read-a-line-from-a-text-file-in-c-c
    look at post by sje397

    */
    // fp = fopen("/tmp/trove", "w+");

    fp = fopen("trovefile.txt", "w+");
    // if(fp == NULL) {
    //     perror("Error opening file");
        
    // }
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp)) {
        //
    }
    fputs("heyy", fp);
    fclose(fp);
   
    printf("create_trovefile\n");
}