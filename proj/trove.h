#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/* Trove header file containing required functions for all the other files */

// TODO:


// void index_file();


// IN PROGRESS
int find_file(char *filename);
void build_trovefile(char **filename, char **filelist);

void remove_trovefile();
void update_trovefile();

// DONE
void create_trovefile();
char** search_word(char *filename, int length);
// void make_filelist(int cmd_opts, int argc, int filelist_num, char **filelist, char *argv[]);
