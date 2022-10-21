#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <sys/wait.h>
#include "trove.h"
/* This function converts the given file into a .gz file
For building a new trovefile: option_type = 1, and fullindex parameter is provided.
For removing a trovefile: option_type = 2, trovefile_name is provided. 
Code adapted from: https://www.youtube.com/watch?v=6xbLgZpOBi8*/
int zip(int option_type, char ***fullindex, char *trovefile_name)
{

    // char ***fullindex = build_trovefile(trove_filename, strings_list, str_ind);
    // build_trovefile(trove_filename, strings_list, str_ind);

    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("Error in forking.\n");
        exit(EXIT_FAILURE);
    }

    int pid1 = fork();
    if (pid1 < 0)
    {
        printf("Process ID less than 0.\n");
        exit(EXIT_FAILURE);
    }

    if (pid1 == 0)
    {
        char temp[256]; // The filename with the .gz extension
        strcpy(temp, trovefile_name);
        strcat(temp, ".gz");

        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);

        if (option_type == 1)
        {
            write(1, fullindex, sizeof(fullindex));
        }

        if (option_type == 2)
        {
            execl("/usr/bin/zcat", "zcat", temp); //.gz file
        }
    }

    int pid2 = fork();
    if (pid2 < 0)
    {
        printf("Process ID less than 0.\n");
        exit(EXIT_FAILURE);
    }

    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);

        execl("/usr/bin/gzip", "gzip", "-f", "-k", trovefile_name, NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}