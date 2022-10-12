
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include "trove.h"
#define DT_DIR 4
/* Recursively goes through all files in current directory
to find if input file exists */
void listFiles(const char *dirname)
{
    DIR *dir = opendir(dirname);
    if (dir == NULL)
    {
        return;
    }

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        printf("%hhd %s\n", entity->d_type, entity->d_name);
        if (entity->d_type == DT_DIR && strcmp(entity->d_name,".") != 0 && strcmp(entity->d_name,"..") != 0) {
            char path[100] = {0};
            strcat(path,dirname);
            strcat(path,"/");
            strcat(path, entity->d_name);
            listFiles(path);
        }
        entity = readdir(dir);
    }
    
    
    closedir(dir);
}


/* Will index all the files recursively of the filelist that is provided to the function */
// find file in directory
// if no exist, return false
// must be word
// call search_word();
int find_file(int argc, char *argv[])
{
    listFiles(".");
    return 0;
}
