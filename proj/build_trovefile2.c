#include <stdio.h>
#include "trove.h"

void build_trovefile2(char *trovefilename, char ***strings_list, int str_ind)
{
    FILE *fp = fopen("test.txt", "w");

    int i, j;
    //char word[100];
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