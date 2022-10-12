#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include "trove.h"

int listFiles(const char *dirname)
{
    DIR *dir = opendir(dirname);
    if (dir == NULL)
    {
        return 1;
    }

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        printf("Filename inside directory: %s\n", entity->d_name);
        entity = readdir(dir);
    }
    closedir(dir);
    return 0;
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
