#include "trove.h"

#define DT_DIR 4
#define DT_REG 8

// Initialize strings_list to store all list of words
// The first "column" of each "row" will contain the filename
char ***strings_list;

/* Recursively goes through all files in named directory
   If readable files are observed, read them using the search_word() function*/
void list_file(char *dirname, char *trove_filename, int max_length)
{   
    DIR *dir = opendir(dirname);
    FILE *single_file;

    // Check for error opening file
    if (dir == NULL)
    {
        // Will try to open assuming it's an existing file first
        if ((single_file = fopen(dirname, "r")) == 0) // If 0, some error occurred in opening file
        {
            fprintf(stderr, "Failed to open %s for reading (%d: %s)\n", dirname, errno, strerror(errno));
            // NO return statement here as one file might not be existing but others might be
        }

        // No error occured so it can be searched
        strings_list[str_ind] = search_word(dirname, max_length);
        str_ind++;
    }
    else {
        struct dirent *entity;
        entity = readdir(dir);
        while (entity != NULL)
        {
            char path[100] = {0};
            strcat(path,dirname);
            strcat(path,"/");
            strcat(path,entity->d_name);
            // If found entity is a subdirectory, explore subdirectory by calling list_file() recursively
            if (entity-> d_type == DT_DIR && strcmp (entity->d_name,".") != 0 && strcmp (entity->d_name,"..") != 0) {
                char path[100] = {0};
                strcat(path,dirname);
                strcat(path,"/");
                strcat(path,entity->d_name);
                list_file(path, trove_filename, max_length);
            }
            // If a file that can be read, read it
            if (entity-> d_type == DT_REG) {
                strings_list[str_ind] = search_word(path, max_length);
                str_ind++;
            }
            entity = readdir(dir);
        }

    }
    closedir(dir);
}

/* Will index all the files recursively of the file that is provided to the function */
int find_file(char **filelist, int filelist_num, int option_type, char *trove_filename, int max_length)
{
    int i;
    strings_list = malloc(sizeof(char**) * 32);
    // Loop through each filename in the filelist, calling list_file()
    for (i = 0; i < filelist_num; i++) {
        list_file(filelist[i], trove_filename, max_length);

    }
    // -b was called
    if (option_type == 1) {
        build_trovefile(trove_filename, strings_list, str_ind);
    }
    // -u was called
    if (option_type == 3) {
        append_trovefile(trove_filename, strings_list, str_ind);
    }

    return 0;
}