#include "trove.h"

/* Append to the filename all filenames and words needed */
void append_trovefile(char *trovefilename, char ***strings_list, int str_ind)
{
    FILE *fp = fopen(trovefilename, "a");

    // Loop over every word in the strings_list array, containing all filenames and words
    int i, j;
    for (i = 0; i < str_ind; i++) {
        for (j = 0; strings_list[i][j] != NULL; j++) {
            if (j == 0) {
                fprintf(fp, "@%s\n", strings_list[i][j]);
            }
            else{
                fprintf(fp, "%s ", strings_list[i][j]);
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}