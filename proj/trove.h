#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Trove header file containing required functions for all the other files */

// TODO:


// void index_file();


// IN PROGRESS
int find_file(char *filename);
void search_word(char word[]);
// DONE
void create_trovefile();
char** search_file(char *filename, int length);
void build_trovefile(int length);
void remove_trovefile();
void update_trovefile();