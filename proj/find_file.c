#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <sys/wait.h>
#include "trove.h"

#define DT_DIR 4
#define DT_REG 8

// Initialize strings_list to store all list of words
// The first "column" of each "row" will contain the filename
char ***strings_list;

/* Recursively goes through all files in named directory
   If readable files are observed, read them using the search_word() function*/
void list_file(char *dirname, char *trove_filename, int max_length)

{
    DIR *dir = opendir(dirname);
    FILE *single_file;

    // Check for error opening file
    if (dir == NULL)
    {
        // Will try to open assuming it's an existing file first
        if ((single_file = fopen(dirname, "r")) == 0) // If 0, some error occurred in opening file
        {
            fprintf(stderr, "Failed to open %s for reading (%d: %s)\n", dirname, errno, strerror(errno));
            // NO return statement here as one file might not be existing but others might be
        }

        // No error occured so it can be searched
        strings_list[str_ind] = search_word(dirname, max_length);
        str_ind++;
    }
    else
    {
        struct dirent *entity;
        entity = readdir(dir);
        while (entity != NULL)
        {
            char path[100] = {0};
            strcat(path, dirname);
            strcat(path, "/");
            strcat(path, entity->d_name);
            // If found entity is a subdirectory, explore subdirectory by calling list_file() recursively
            if (entity->d_type == DT_DIR && strcmp(entity->d_name, ".") != 0 && strcmp(entity->d_name, "..") != 0)
            {
                char path[100] = {0};
                strcat(path, dirname);
                strcat(path, "/");
                strcat(path, entity->d_name);
                list_file(path, trove_filename, max_length);
            }
            // If a file that can be read, read it
            if (entity->d_type == DT_REG)
            {
                strings_list[str_ind] = search_word(path, max_length);
                str_ind++;
            }
            entity = readdir(dir);
        }
    }
    closedir(dir);
}

/* Will index all the files recursively of the file that is provided to the function */
int find_file(char **filelist, int filelist_num, int option_type, char *trove_filename, int max_length)
{
    int i;
    strings_list = malloc(sizeof(char **) * 32);
    // Loop through each filename in the filelist, calling list_file()
    for (i = 0; i < filelist_num; i++)
    {
        list_file(filelist[i], trove_filename, max_length);
    }
    // -b was called
    
    if (option_type == 1)
    {
        
        char ***fullindex = build_trovefile(trove_filename, strings_list, str_ind);
        printf("b called\n");
        zip(option_type, fullindex, NULL);
        
        // build_trovefile(trove_filename, strings_list, str_ind);

        // int fd[2];
        // if (pipe(fd) == -1)
        // {
        //     return 1;
        // }

        // int pid1 = fork();
        // if (pid1 < 0)
        // {
        //     return 2;
        // }

        // if (pid1 == 0)
        // {
        //     dup2(fd[1], STDOUT_FILENO);
        //     close(fd[0]);
        //     close(fd[1]);
        //     write(1, fullindex, sizeof(fullindex));
        //     // execlp("ping", "ping", "-c", "5", "google.com", NULL);
        //     // since we use STDOUT it autocloses
        // }

        // int pid2 = fork();
        // if (pid2 < 0)
        // {
        //     printf("err\n");
        //     return 3;
        // }

        // if (pid2 == 0)
        // {
        //     dup2(fd[0], STDIN_FILENO);
        //     close(fd[0]);
        //     close(fd[1]);
        //     // execlp("grep", "grep", "rtt", NULL);
        //     execlp("/usr/bin/gzip", "gzip", "-f", "trovey.txt", NULL);
        // }

        // close(fd[0]);
        // close(fd[1]);

        // waitpid(pid1, NULL, 0);
        // waitpid(pid2, NULL, 0);
    }
    // -u was called
    if (option_type == 3)
    {

        append_trovefile(trove_filename, strings_list, str_ind);
    }

    return 0;
}