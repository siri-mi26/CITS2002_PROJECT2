// Headerfiles used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <dirent.h>

// Declare global variable
int str_ind;

// Declare Functions
int find_file(char **filelist, int filelist_num, int option_type, char *trove_filename, int max_length);
void append_trovefile(char *trovefilename, char ***strings_list, int str_ind);
int search_trove(char *trove_filename, char *word);
int zip(int option_type, char ***fullindex, char *trovefile_name);
int zcat(char ***fullindex);

char ***build_trovefile(char *trovefilename, char ***strings_list, int str_ind);
void remove_trove(char *trovefilename, char **filelist, int filelist_num);
char **search_word(char *filename, int length);
char *realpath(const char *__restrict__file_name, char *__restrict__resolved_name);
