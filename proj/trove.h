#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
/* Trove header file containing required functions for all the other files */

// TODO:
// IN PROGRESS
int find_file(char *filename);
void build_trovefile(char *filename, char **filelist, int length);

void remove_trovefile();
void update_trovefile();
void another_func();

// DONE
// void create_trovefile();
char** search_word(char *filename, int length);
// void make_filelist(int cmd_opts, int argc, int filelist_num, char **filelist, char *argv[]);

char *realpath(const char *__restrict__file_name, char *__restrict__resolved_name);
