#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include "trove.h"
#define DT_DIR 4
#define DT_REG 8

/* Recursively goes through all files in current directory
to find if input file exists */

// Initialize strings_list to store all list of words
// TODO: input as pathnames need to be taken in
char ***strings_list;
int str_ind = 0;
int array_size = 10;
void list_file(char *dirname)
{
    DIR *dir = opendir(dirname); // tries to open assuming it's a directory
    FILE *single_file;

    if (dir == NULL) // It could be a single file or non-existent file
    {
        
        // Will try to open assuming it's an existing file first
        if ((single_file = fopen(dirname, "r")) == 0) // If 0, some error occurred in opening file
        {
            fprintf(stderr, "Failed to open %s for reading (%d: %s)\n", dirname, errno, strerror(errno));
            // NO return statement here as one file might not be existing but others might be
        }
        // No error occurred so it's a single file that can be searched
        printf("---------------------------------------THIS IS WHERE IT\'S GOING IN\n");

        // search_word(dirname, 4);

        printf("sizeof %ld\n", sizeof(strings_list));
        strings_list[str_ind] = search_word(dirname, 4);
        printf("[str_ind]  %i\n", str_ind);
        // search_word(path, 4);
        // str_ind++;
        if (str_ind == array_size)
        {
            array_size *= 2;
            strings_list = realloc(strings_list, array_size);
        }
        printf("sizeof %ld\n", sizeof(strings_list));

        return;
    }

    printf("Reading in: %s\n", dirname);
    struct dirent *entity;
    entity = readdir(dir);

    while (entity != NULL)
    {
        printf("%hhd  %s/%s\n", entity->d_type, dirname, entity->d_name);
        char path[100] = {0};
        strcat(path, dirname);
        strcat(path, "/");
        strcat(path, entity->d_name);
        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0)
        // If the files are not "." and ".."
        {

            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            // char path[100] = {0};
            // strcat(path,dirname);
            // strcat(path,"/");
            // strcat(path,entity->d_name);
            list_file(path);
        }
        // If a file that can be read, read it
        if (entity->d_type == DT_REG)
        {
            printf("sizeof %ld\n", sizeof(strings_list));
            printf("-------------here\n");
            strings_list[str_ind] = search_word(path, 4);
            printf("-------------here\n");
            printf("[str_ind]  %i\n", str_ind);
            // search_word(path, 4);
            str_ind++;
            if (str_ind == array_size)
            {
                array_size *= 2;                
                strings_list = realloc(strings_list, array_size);
                
            }
            printf("sizeof %ld\n", sizeof(strings_list));
            printf("array_size %i\n", array_size);
        }
        entity = readdir(dir);
    }

    closedir(dir);
    printf("str_ind: %i\n", str_ind);
}

/* Will index all the files recursively of the file that are provided to the function.
This function is called for every item in filelist, so it returns all of the indexed words for that file/directory only.*/
int find_file(char *filename)
{
    strings_list = malloc(sizeof(char **) * array_size);

    list_file(filename);

    int i;
    int j;
    printf("second strind %i\n", str_ind);
    for (i = 0; i < str_ind; i++) {
        printf("HELLO %i\n", i);

        for (j = 0; strings_list[i][j] != NULL; j++) {
            printf("BYEEE\n");
            printf("i: %i   j: %i\n", i, j);
            printf("word: %s\n", strings_list[i][j]);
        }
    }

    // if strings
    // if strings_list
    // read strings list
    // build_trovefile("trovey", strings_list, str_ind);

    free(strings_list);
    return 0;
}
