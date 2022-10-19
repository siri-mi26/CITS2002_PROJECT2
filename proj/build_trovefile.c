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
    FILE *fp;
    int i;
    int j;
    // trovefilename = get_trovefile();

    char pathname[100]; // TODO: change size
    char str2[100];     // the repeat
    char word[100];
    strcpy(pathname, "@");

    fp = fopen(trovefilename, "wt+");

    for (i = 0; i < str_ind; i++)
    {

        for (j = 0; strings_list[i][j] != NULL; j++)

        {
            if (strcmp(strings_list[i][0], str2) == 0) // Since we have many rows with the same pathname as the first item,
            // When it encounters the same pathname again, the words are copied while the pathname remains the same
            {
                strcpy(word, strings_list[i][j]);
                strcat(word, " ");
                printf("word %s\n", word);
                fwrite(word, 1, strlen(word), fp);
                continue;
            }
            // str2 is basically the pathname and it's copied into str2 so it can be compared in each loop (as shown above with strcmp)
            strcpy(str2, strings_list[i][0]);
            //pathname is "@" initially. to it, we copy the pathname e.g. /home/siri/PROJECT_2/proj/goofy/valo_noob.exe
            strcat(pathname, strings_list[i][0]);
            strcat(pathname, "\n"); //add new line
            printf("pathname %s\n", pathname); //looks like @/home/siri/PROJECT_2/proj/goofy/valo_noob.exe
            fwrite(pathname, 1, strlen(pathname), fp); //write to file

        }
        printf("outer loop\n");
    }

    fclose(fp);
}