#include "trove.h"
/*
TODO: create new function signature
void build_trovefile(char *trovefile, char *filelist)


This function creates a new trovefile given a filelist
@trovefile
@filelist

@length is temporary!!
// TODO: write full_index to trovefile/creates trovefile initially
 */
void build_trovefile(char *filename, char **filelist, int length)
{
    printf("build_trovefile\n");
    
    
    
    find_file(filename, length);

    // find_file(filename);

    /* FILE *fp;
    char line[256]; // not sure how long one line will be    
    int exists = 1;
    exists = access(filename, W_OK);
    printf("exists %i\n", exists);

    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("exit\n");
        printf("Error message");
        exit(EXIT_FAILURE);
    }

    printf("sizeof(line) %ld\n", sizeof(line));
    while (fgets(line, sizeof(line), fp) != NULL) // TODO: check size of file line is 100
    {
        printf("line %s\n", line);
    }
    fclose(fp); */



    
    // for each file
    // search_file()
    // returns strings
}