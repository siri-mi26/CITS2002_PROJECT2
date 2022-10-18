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
    FILE *fp;
    int i;
    int j;
    // trovefilename = get_trovefile();
    printf("trovefilenametrovefilenametrovefilenametrovefilenametrovefilename %s\n", trovefilename);

    char pathname[100]; // TODO: change size
    char str2[100];     // the repeat
    char str3[100];
    strcpy(pathname, "@");

    fp = fopen(trovefilename, "wt+");

    for (i = 0; i < str_ind; i++)
    {
        // copy over filename

        for (j = 0; strings_list[i][j] != NULL; j++)
        // copy over words PER filename
        {
            if (strcmp(strings_list[i][0], str2) == 0)
            {
                // also add code here
                strcpy(str3, strings_list[i][j]);
                strcat(str3, " ");
                printf("str3 %s\n", str3);
                fwrite(str3, 1, strlen(str3), fp);
                
                continue;
            }

            strcpy(str2, strings_list[i][0]);
            
            strcat(pathname, strings_list[i][0]);
            
            strcat(pathname, "\n");
            printf("pathname %s\n", pathname);

            fwrite(pathname, 1, strlen(pathname), fp);

            printf("i %i\n", i);
            printf("j %i\n", j);

            // words

            printf("strings_list[%i] %s\n", i, strings_list[i][0]);

            // strcat(str, strings_list[i][0]);

            // printf("i: %i   j: %i\n", i, j);
            // printf("word: %s\n", strings_list[i][j]);
            // fwrite(strings_list[i][j], 1, sizeof(strings_list[i][j]), fp);
        }
        printf("outer loop\n");
    }

    // fclose(fp);

    // printf("here\n");

    // for each file
    // search_file()
    // returns strings
}