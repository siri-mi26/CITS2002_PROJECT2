#include "trove.h"


/* Write the filename, and the list of words in the file
   Written in the format
   @filename1
   word1 word2 word3...
   @filename2
   word1 word2 word3...
   */
char *** build_trovefile(char *trovefilename, char ***strings_list, int str_ind)
{
    FILE *fp = fopen(trovefilename, "w");

    // Loop over every word in the strings_list array, containing all filenames and words
    int i, j;
    for (i = 0; i < str_ind; i++) {
        for (j = 0; strings_list[i][j] != NULL; j++) {
            if (j == 0) {    // If the filename, add an @ to the beginning and newline at the end
                fprintf(fp, "@%s\n", strings_list[i][j]);
            }
            else{     
                fprintf(fp, "%s ", strings_list[i][j]);
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    return strings_list;
}