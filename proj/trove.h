#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
/* Trove header file containing required functions for all the other files */
int str_ind;
// TODO:
// Deal with empty files
// IN PROGRESS
int find_file(char **filelist, int filelist_num);
void build_trovefile(char *trovefilename, char ***strings_list, int str_ind);

void remove_trovefile();
void update_trovefile();
void another_func();

// DONE
// void create_trovefile();
void build_trovefile2(char *trovefilename, char ***strings_list, int str_ind);
void remove_trove(char *trovefilename, char **filelist, int filelist_num);
char** search_word(char *filename, int length);
// void make_filelist(int cmd_opts, int argc, int filelist_num, char **filelist, char *argv[]);

char *realpath(const char *__restrict__file_name, char *__restrict__resolved_name);