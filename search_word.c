#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include "trove.h"

/* Searches through trovefile to find all files whose contents contain the provided word
These filenames are all printed (each filename will be printed only once)  */
void search_word(char word[]) {
    /* 
    If trovefile provided:
        
        For each line in trovefile (doesn't have to be a text file)
        Print absolute pathname of word

    Else if trovefile not given do:
        get_trovefile();
        index_file(filelist);
        search_trovefile(trovefile); //Filenames should print


     */
    printf("%s\n",word);
}