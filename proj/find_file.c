
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include "trove.h"
#define DT_DIR 4
#define DT_REG 8
/* Recursively goes through all files in current directory
to find if input file exists */
void list_file(const char *dirname)
{    
    DIR *dir = opendir(dirname);
    if (dir == NULL)
    {
        return;
    }
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
            // char path[100] = {0};
            // strcat(path,dirname);
            // strcat(path,"/");
            // strcat(path,entity->d_name);
            list_file(path);
        }
        // If a file that can be read, read it
        if (entity-> d_type == DT_REG) {
            search_word(path, 4);
        }
        entity = readdir(dir);
    }

    closedir(dir);
}
/* Will index all the files recursively of the file that is provided to the function */
// find file in directory
// if no exist, return false
// must be word
// call search_word();
int find_file(char* filename)
{
    list_file(filename);
    return 0;
}