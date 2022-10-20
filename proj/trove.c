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
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "trove.h"
#include <getopt.h>
// char *realpath(const char *__restrict__file_name, char *__restrict__resolved_name);
// Add the command line argument options:
#define OPTLIST "f:brul:"
/* This file checks command line options to determine whether:
-A word is being searched for (when found, the filenames containing the word will be returned)
OR
-A list of files (given as "filelist") need to be indexed
*/
/* This file finds and gets the trovefile */
void get_trovefile()
{
}
void make_filelist(int cmd_opts, int argc, int filelist_num, char **filelist, char *argv[])
{
    for (int i = (cmd_opts + 1); i < argc; i++)
    {
        filelist[i - cmd_opts - 1] = malloc((256 + 1) * sizeof(char)); // 256 is max filename length
        strcpy(filelist[i - cmd_opts - 1], argv[i]);                   // different indices, as the for loop starts at 4, whereas this loop should start at 0 to get first element of filelist
    }
}
int commandline_error(char *argument)
{
    printf("Error: Additional argument in command line: '%s'\n", argument);
    exit(EXIT_FAILURE);
}
/* Invokes the necessary functions to search trovefile or modify it */
int main(int argc, char *argv[])
{
    // find_file(argc,argv);
    // create_trovefile();
    // search_word(argv[1]);
    // index_file();
    // Define variables to hold command line arguments
    int opt;
    char *trovefile_name = "/tmp/trove";
    // char *trovefile_name = NULL;
    int length = 4;
    int option_type = 0; // b r u = 1,2,3 respectively. if 0 => prompt 1
    int cmd_opts = 0;
    int filelist_num = 0;
    char **filelist;
    // char filelist[20][256+1]; //256 because that is max length of filename
    // TODO: how many command line arguments are we going to have max??
    // ^ PROB CHANGE THIS NAME LATER
    // Go through command line arguments
    /* -b,r,u = prompt2 */
    while ((opt = getopt(argc, argv, OPTLIST)) != -1)
    {
        // for (int i = (cmd_opts + 1); i < argc; i++)
        // {
        //     // printf("Filelist name %i: %s\n", (i - cmd_opts), argv[i]);
        //     filelist[i - cmd_opts - 1] = malloc((256 + 1) * sizeof(char)); // 256 is max filename length
        //     strcpy(filelist[i - cmd_opts - 1], argv[i]);                   // different indices, as the for loop starts at 4, whereas this loop should start at 0 to get first element of filelist
        //     printf("filelist[i] %s\n", filelist[i - cmd_opts - 1]);
        //     // find_file(argv[i]);
        // }
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
            // printf("cmd_opts %i\n", cmd_opts);

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
    int success;

    if (option_type == 0) {
        // Search trovefile
        success = search_trove(trovefile_name, filelist[0]);
        printf("Searched for a word!\nexitting...\n");
        if (success == 0) {
            printf("Could not find word\n");
            exit(EXIT_FAILURE);
        }
    }
    if (option_type == 1) {
        // -b called
        find_file(filelist, filelist_num, option_type);
        printf("Built a trove file!\nexitting...\n");
    }
    if (option_type == 2) {
        // -r called
        remove_trove(trovefile_name, filelist, filelist_num);
        printf("Removed some files from trovefile\nexitting...\n");
    }
    if (option_type == 3) {
        // -u called
        remove_trove(trovefile_name, filelist, filelist_num);
        find_file(filelist, filelist_num, option_type);
        printf("Updated the trovfile!\nexitting...\n");
    }
    
    exit(EXIT_SUCCESS);
}