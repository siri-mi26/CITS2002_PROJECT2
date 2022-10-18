#include "trove.h"
/*
TODO: create new function signature
void build_trovefile(char *trovefile, char *filelist)


This function creates a new trovefile given a filelist
@trovefile
@filelist

@length is temporary!!
// TODO: write full_index to trovefile/creates trovefile initially
 */
void build_trovefile(char *trovefilename, char ***strings_list, int str_ind)
{
    printf("build_trovefile\n");
    // FILE * fp;
    int i;
    int j;
    trovefilename = get_trovefile();

    // char str[100]; // TODO: change size
    // strcpy(str, "@");
    // fp = fopen(trovefilename, "w");

    for (i = 0; i < str_ind; i++)
    {
        // copy over filename

        // fwrite(str, 1, sizeof(str), fp);
        for (j = 0; strings_list[i][j] != NULL; j++)
        // copy over words PER filename
        {
            // strcat(str, strings_list[i][0]);
            printf("strings_list[i] %s\n", strings_list[i][0]);
            // printf("i: %i   j: %i\n", i, j);
            // printf("word: %s\n", strings_list[i][j]);
            // fwrite(strings_list[i][j], 1, sizeof(strings_list[i][j]), fp);
        }
    }

    // fclose(fp);

    // printf("here\n");

    // for each file
    // search_file()
    // returns strings
}