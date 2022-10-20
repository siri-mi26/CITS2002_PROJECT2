#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include "trove.h"
#include <errno.h>
#define DT_DIR 4
#define DT_REG 8
/* Recursively goes through all files in current directory
to find if input file exists */
// Initialize strings_list to store all list of words
char ***strings_list;
void list_file(char *dirname, char *trove_filename, int max_length)
{   
    printf("Will now list_file: %s\n", dirname);
    DIR *dir = opendir(dirname);
    FILE *single_file;
    if (dir == NULL)
    {
        // Will try to open assuming it's an existing file first
        if ((single_file = fopen(dirname, "r")) == 0) // If 0, some error occurred in opening file
        {
            fprintf(stderr, "Failed to open %s for reading (%d: %s)\n", dirname, errno, strerror(errno));
            // NO return statement here as one file might not be existing but others might be
        }

        // No error occured so it can be searched
        printf("Single file: %s\n", dirname);
        strings_list[str_ind] = search_word(dirname, max_length);
        str_ind++;
    }
    else {
        printf("Reading in: %s\n", dirname);
        struct dirent *entity;
        entity = readdir(dir);
        while (entity != NULL)
        {
            printf("%hhd  %s/%s\n",entity->d_type, dirname, entity->d_name);
            char path[100] = {0};
            strcat(path,dirname);
            strcat(path,"/");
            strcat(path,entity->d_name);
            if (entity-> d_type == DT_DIR && strcmp (entity->d_name,".") != 0 && strcmp (entity->d_name,"..") != 0) {
                char path[100] = {0};
                strcat(path,dirname);
                strcat(path,"/");
                strcat(path,entity->d_name);
                list_file(path, trove_filename, max_length);
            }
            // // If a file that can be read, read it
            if (entity-> d_type == DT_REG) {
                strings_list[str_ind] = search_word(path, max_length);
                str_ind++;
            }
            entity = readdir(dir);
        }

    }
    closedir(dir);
    printf("str_ind: %i\n", str_ind);
}

/* Will index all the files recursively of the file that is provided to the function */
int find_file(char **filelist, int filelist_num, int option_type, char *trove_filename, int max_length)
{
    int i;
    //int j;
    //printf("not sure yet: %li\n", sizeof(char**));
    strings_list = malloc(sizeof(char**) * 32);
    for (i = 0; i < filelist_num; i++) {
        printf("i now: %i\n", i);
        printf("LOOKING AT NEW FILELIST ITEM\n-----------------------\n");
        list_file(filelist[i], trove_filename, max_length);

    }
    if (option_type == 1) {
        build_trovefile(trove_filename, strings_list, str_ind);
    }
    if (option_type == 3) {
        append_trovefile(trove_filename, strings_list, str_ind);
    }

    return 0;
}