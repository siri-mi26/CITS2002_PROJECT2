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
// #include <trove.h>
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
    if "word" provided:
    if "filelist" provided:

     */
}
/* This file finds and gets the trovefile */
void get_trovefile()
{
}
/*Builds new trovefile/index from the given filelist
This will replace any existing trovefile with the same name

*/
void build_trovefile()
{
}
/* Searches through trovefile to find all files whose contents contain the provided word
These filenames are all printed (each filename will be printed only once)  */
void search_trovefile()
{
    /* 
    If trovefile provided:
        
        For each line in trovefile (doesn't have to be a text file)
        Print absolute pathname of word

    Else if trovefile not given do:
        get_trovefile();
        index_file(filelist);
        search_trovefile(trovefile); //Filenames should print


     */
}
/*Will index all the files recursively of the filelist that is provided to function */
void index_file(filelist)
{
}

/* Invokes the necessary functions to search trovefile or modify it */
int main(int argc, char *argv[])
{

    commandline_checker();
    find_trovefile();
    build_trovefile();
    search_trovefile();
    index_file();

    exit(EXIT_SUCCESS);
}