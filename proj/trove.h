#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
/* Trove header file containing required functions for all the other files */
int str_ind;
// TODO:
// IN PROGRESS
int find_file(char **filelist, int filelist_num, int option_type);
void append_trovefile(char *trovefilename, char ***strings_list, int str_ind);
void search_trove(char *trove_filename, char *word);

// DONE
void build_trovefile(char *trovefilename, char ***strings_list, int str_ind);
void remove_trove(char *trovefilename, char **filelist, int filelist_num);
char** search_word(char *filename, int length);

char *realpath(const char *__restrict__file_name, char *__restrict__resolved_name);