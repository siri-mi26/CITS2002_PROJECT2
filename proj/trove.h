#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Trove header file containing required functions for all the other files */

// TODO:


// void index_file();


// IN PROGRESS
int find_file(char *filename);

// DONE
void create_trovefile();
char** search_word(char *filename, int length);
void build_trovefile(char *trovefile_name, int length);
void remove_trovefile();
void update_trovefile();