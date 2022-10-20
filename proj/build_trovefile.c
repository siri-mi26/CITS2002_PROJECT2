#include <stdio.h>
#include "trove.h"

char *** build_trovefile(char *trovefilename, char ***strings_list, int str_ind)
{
    FILE *fp = fopen(trovefilename, "w");

    int i, j;
    for (i = 0; i < str_ind; i++) {
        for (j = 0; strings_list[i][j] != NULL; j++) {
            printf("i: %i       j: %i\n", i, j);
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
    return strings_list;
}