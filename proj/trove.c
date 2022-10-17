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
// This is a comment

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "trove.h"
#include <getopt.h>

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
        printf("filelist[i] %s\n", filelist[i - cmd_opts - 1]);
    }
}

int commandline_error(char *argument) {
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
    int option_type = 0; //b r u = 1,2,3 respectively. if 0 => prompt 1
    int cmd_opts = 0;

    char ***strings_list = malloc(8);
    int str_ind = 0;
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
            printf("u typed f\n");
            trovefile_name = optarg;
            printf("file given with f option: %s\n", trovefile_name);

            // if -f and word: It searches for word, reading from the trove-file.
            if (argc == 4)
            {
                // could be filelist or word
                // check if word or filelist func();
                search_word(argv[3], length);

                // if file exists, index_file();
                // if no file exists, search_word();
            }
            break;
        case 'b':
            if (option_type != 0) {
                commandline_error("-b");
            }
            cmd_opts += 1;
            option_type = 1;

            
            // build_trovefile(trovefile_name, filelist);
            // l is inside search_word()
            break;
        case 'r':
            if (option_type != 0) {
                commandline_error("-r");
            }
            cmd_opts += 1;
            option_type = 2;
            remove_trovefile();
            break;
        case 'u':
            if (option_type != 0) {
                commandline_error("-u");
            }
            cmd_opts += 1;
            option_type = 3;
            update_trovefile();
            break;
        case 'l':
            cmd_opts += 2;
            printf("u typed l\n");
            length = atoi(optarg);
            printf("l %i\n", length);
            break;
        }
    }
    // TODO: if option_type == etc


    // TODO: how do we do multiple command line arguments
    // Get additional command line arguments
    // These are filelist names (I think)

    // TODO: usage function?
    //printf("cmd_opts %i\n", cmd_opts);

    filelist_num = argc - cmd_opts - 1; //cmdopts = 4
    filelist = malloc(filelist_num * sizeof(char *));
    make_filelist(cmd_opts, argc, filelist_num, filelist, argv);
    for (int i = (cmd_opts + 1); i < argc; i++)
    {
        printf("Filelist name %i: %s\n", (i - cmd_opts), argv[i]);
        find_file(argv[i]);

        // filelist[i - cmd_opts - 1] = malloc((256 + 1) * sizeof(char)); // 256 is max filename length
        // strcpy(filelist[i - cmd_opts - 1], argv[i]);                   // different indices, as the for loop starts at 4, whereas this loop should start at 0 to get first element of filelist
        // printf("filelist[i] %s\n", filelist[i - cmd_opts - 1]);
    }

    

    // The search_file function should prob go in the find_file function, as it's searching through
    printf("FOR NOW, IGNORE PAST THIS PART:\n");
    strings_list[str_ind] = search_word("./testdir/watermelon.txt", length);
    str_ind++;
    //printf("word: %s\n", strings_list[0][0]);

    // find_file(".");

    /* When extra arguments are passed */
    // for(; optind < argc; optind++) {
    //     printf("Unknown argument given: %s\n", argv[optind]);
    // }

    /*
    commandline_checker();
    get_trovefile();
    build_trovefile();

    index_file();
    */

    exit(EXIT_SUCCESS);
}