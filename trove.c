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

// Add the command line argument options:
#define OPTLIST "f:brul:"

/* This file checks command line options to determine whether:
-A word is being searched for (when found, the filenames containing the word will be returned)
OR
-A list of files (given as "filelist") need to be indexed
*/
void commandline_checker()
{
    /*
    if "-b" provided:
    if "-f" provided:
    if "-l" provided:
    if "-r" provided:
    if "-u" provided:

    if b,r,u provided, assume arguments will be filelist
    else it's a word

    if "word" provided:
    if "filelist" provided:

     */
}
/* This file finds and gets the trovefile */
void get_trovefile()
{
}


void remove_trovefile() {

}
void update_trovefile() {

}
/* Invokes the necessary functions to search trovefile or modify it */
int main(int argc, char *argv[])

{
    build_trovefile();
    // search_word(argv[1]);

    // index_file();
    // Define variables to hold command line arguments
    int opt;
    char *trovefile_name = NULL;
    // int length;
    int option_type;

    // ^ PROB CHANGE THIS NAME LATER

    // Go through command line arguments
    while ((opt = getopt(argc, argv, OPTLIST)) != -1)
    {

        
        switch (opt)
        {

        case 'f':
            printf("u typed f\n");
            trovefile_name = optarg;
            printf("f option: %s\n", trovefile_name);
            
            // if -f and word: It searches for word, reading from the trove-file.
            if (argc == 4) {
                //could be filelist or word
                //check if word or filelist func();
                search_word(argv[3]);

                //if file exists, index_file();
                //if no file exists, search_word();

            }
            break;
        case 'b':
            printf("u typed b\n");
            option_type = 1;
            update_trovefile(option_type);
            break;
        case 'r':
            printf("u typed r\n");
            option_type = 2;
            remove_trovefile();
            break;
        case 'u':
            printf("u typed u\n");
            option_type = 3;
            update_trovefile();
            break;
        case 'l':
            printf("u typed l\n");
            // length = atoi(&optarg);
            break;
        }
        
    }

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