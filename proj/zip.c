#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include <sys/wait.h>
#include "trove.h"
int zip(int option_type, char ***fullindex, char *trovefile_name)
{
    // char ***fullindex = build_trovefile(trove_filename, strings_list, str_ind);
    // build_trovefile(trove_filename, strings_list, str_ind);

    int fd[2];
    if (pipe(fd) == -1)
    {
        return 1;
    }

    int pid1 = fork();
    if (pid1 < 0)
    {
        return 2;
    }

    if (pid1 == 0)
    {
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        if (option_type == 1)
        {
            write(1, fullindex, sizeof(fullindex));
        }
        if (option_type == 2)
        {
            FILE * fp;
            fp = fopen(trovefile_name, "r");
            fseek(fp, 0L, SEEK_END);
            int size = ftell(fp);
            write(1, trovefile_name, size);
        }

        // execlp("ping", "ping", "-c", "5", "google.com", NULL);
        // since we use STDOUT it autocloses
    }

    int pid2 = fork();
    if (pid2 < 0)
    {
        printf("err\n");
        return 3;
    }

    if (pid2 == 0)
    {
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        // execlp("grep", "grep", "rtt", NULL);
        printf("tmp %s\n", trovefile_name);
        execlp("/usr/bin/gzip", "gzip", "-f", "-k", trovefile_name, NULL);
    }

    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return 0;
}