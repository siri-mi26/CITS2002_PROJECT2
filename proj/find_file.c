
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
to find if input file exists

return of 0 means it is a single file
1 means it is a directory
-1 means some error */
int list_file(const char *dirname, int length)
{

    DIR *dir = opendir(dirname);
    char *subfiles = malloc(1 * sizeof(char));

    // for (int i = 0; i < strlen(subfiles); i++)
    // {
    //     /* code */
    // }

    int subfile_count = 0;
    // int size = 1;
    // int mem_used = 0;
    // int mem_used2 = 0;
    // int size2 = 1;

    if (dir == NULL)
    {
        printf("single file\n");
        return -1;
    }

    // printf("Reading in: %s\n", dirname);

    struct dirent *entity;
    entity = readdir(dir);
    while (entity != NULL)
    {
        // printf("mem_used %i\n", mem_used);

        // printf("%hhd  %s/%s\n",entity->d_type, dirname, entity->d_name);
        // printf("%s\n", entity->d_name);
        // if (mem_used == size)
        // {
        //     size *= 2;
        //     subfiles = realloc(subfiles, size * sizeof(char));
        // }
        // if (mem_used2 = size2)
        // {
        //     mem_used2 *= 2;
        // }
        /* if (strcmp(entity->d_name, ".") == 0 || strcmp(entity->d_name, "..") == 0)
        {
            // do nothing
        }
        else
        {
            // ok name here
            mem_used++;
            printf("%i %s\n", subfile_count, entity->d_name);
            printf("subfile_coun22t %i\n", subfile_count);
            strcpy(&subfiles[subfile_count], entity->d_name);
            // subfiles[mem_used++] = entity->d_name;

            printf("subfiles here %s\n", &subfiles[mem_used]);
            // for (int j = 0; j < subfile_count +2 ; j++)
            // {
            //     printf("subfiles here %s\n", &subfiles[j]);
            // }

            subfile_count++;
        } */

        if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0)
        {
            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            list_file(path, length);
        }

        // Will list filename

        if (strcmp(entity->d_name, ".") == 0 || strcmp(entity->d_name, "..") == 0)
        {
            // do nothing
        }
        else
        {
            // ok name here
            // mem_used++;
            // printf("%i %s\n", subfile_count, entity->d_name);
            // printf("subfile_coun22t %i\n", subfile_count);
            printf("filename %s\n", entity->d_name);
            // strcpy(&subfiles[subfile_count], entity->d_name);
            // subfiles[mem_used++] = entity->d_name;

            // printf("subfiles here %s\n", &subfiles[mem_used]);
            // printf("subfiles here %s\n", &subfiles[subfile_count]);
            // for (int j = 0; j < subfile_count +2 ; j++)
            // {
            //     printf("subfiles here %s\n", &subfiles[j]);
            // }

            // if file return as file
            // char thefile;
            // char *tf2;
            if (entity->d_type != DT_DIR)
            { // It's a file
              
              // printf("tmp %s\n", (char *) &entity->d_type);
              // strcpy(thefile, &entity->d_name);
              // printf("thefile %s\n", thefile);
                /* thefile = (char)entity->d_type;
                tf2 = &thefile;
                printf("tf2 %s\n",tf2);
                search_word("watermelon.txt", length); */
            }
            // buildtrove will call searchword on it
            // if dir
            // call findfile on it until you get file

            subfile_count++;
        }

        entity = readdir(dir);
    }

    // printf("subfile_count %i\n", subfile_count);

    // for (int j = 0; j < subfile_count; j++)
    // {
    //     printf("subfiles %s\n", &subfiles[j]);
    // }

    closedir(dir);
    free(subfiles);
    return 0;
}

/* Will index all the files recursively of the file that is provided to the function */
// find file in directory
// if no exist, return false
// must be word
// call search_word();
int find_file(char *filename, int length)
{
    // char *tmp = list_file(filename, length);
    // printf("tmp %s\n", tmp);
    if (list_file(filename, length) == 0)
    {
        return 0;
    }
    // else it will return 1 meaning it's a directory
    return 1;
}
