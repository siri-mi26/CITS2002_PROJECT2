//  CITS2002 Project 2 2022
//  Student1:   23073177        TAKEDA      RYAN    50
//  Student2:   23003267        MISSULA     SIRI    50
/*
This program builds and searches a compressed index of files' contents
It can be used to:
-Find a word in those contents
-Create a new index
-Remove information from such an index
-Update an existing index

\bug: If file is blank, the word is undefined. The file will also keep getting added to trovefile if -u is used repeatedly.
\bug: If -f [trovefilename] is not specified, -u will not work
\bug: Does not work with .exe or .jpg files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "trove.h"
#include <getopt.h>

#define OPTLIST "f:brul:"

/* A function that fills an array called filelist with names in the filelist */
void make_filelist(int cmd_opts, int argc, int filelist_num, char **filelist, char *argv[])
{
    for (int i = (cmd_opts + 1); i < argc; i++)
    {
        filelist[i - cmd_opts - 1] = malloc((256 + 1) * sizeof(char)); // 256 is max filename length
        strcpy(filelist[i - cmd_opts - 1], argv[i]);                   
    }
}

/* Function to report error */
int commandline_error(char *argument)
{
    printf("Error: Additional argument in command line: '%s'\n", argument);
    exit(EXIT_FAILURE);
}

/* Invokes the necessary functions to search trovefile or modify it */
int main(int argc, char *argv[])
{
    // Define variables to hold command line arguments
    int opt;
    char *trovefile_name = "/tmp/trove"; // Set default trovefile name
    int length = 4;
    int option_type = 0; // -b -r -u = 1, 2, 3 respectively. If 0, it is invocation/prompt 1.
    int cmd_opts = 0;
    int filelist_num = 0;
    char **filelist;
    int success;
    // Read command line options
    while ((opt = getopt(argc, argv, OPTLIST)) != -1)
    {
        switch (opt)
        {
        case 'f':
            cmd_opts += 2;
            trovefile_name = optarg;

            break;
        case 'b':
            if (option_type != 0)
            {
                commandline_error("-b");
            }
            cmd_opts += 1;
            option_type = 1;
            break;
        case 'r':
            if (option_type != 0)
            {
                commandline_error("-r");
            }
            cmd_opts += 1;
            option_type = 2;
            break;
        case 'u':
            if (option_type != 0)
            {
                commandline_error("-u");
            }
            cmd_opts += 1;
            option_type = 3;
            break;
        case 'l':
            cmd_opts += 2;
            length = atoi(optarg);
            break;
        }
    }

    filelist_num = argc - cmd_opts - 1; // cmdopts = 4
    filelist = malloc(filelist_num * sizeof(char *));
    make_filelist(cmd_opts, argc, filelist_num, filelist, argv);

    str_ind = 0;

    if (option_type == 0)
    { // Search trovefile
        success = search_trove(trovefile_name, filelist[0]);
        printf("    Searched for a word!\n    exitting...\n");
        if (success == 0)
        {
            printf("Could not find word\n");
            exit(EXIT_FAILURE);
        }
    }
    if (option_type == 1)
    { // -b called
        find_file(filelist, filelist_num, option_type, trovefile_name, length);
        printf("    Built a trove file!\n    exitting...\n");
    }
    if (option_type == 2)
    { // -r called
        remove_trove(trovefile_name, filelist, filelist_num);
        zip(option_type, NULL, trovefile_name);
        printf("    Removed some files from trovefile\n    exitting...\n");
    }
    if (option_type == 3)
    { // -u called
        remove_trove(trovefile_name, filelist, filelist_num);
        find_file(filelist, filelist_num, option_type, trovefile_name, length);

        printf("    Updated the trovfile!\n    exitting...\n");
    }

    exit(EXIT_SUCCESS);
}