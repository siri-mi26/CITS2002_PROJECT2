#include "trove.h"

/*
TODO: add params
This function removes any files in the given trovefile
if they are listed in filelist

@trovefile
@filelist */

void remove_trovefile(char *trovefilename, char **filelist, int filelist_num, int argc)
{
    // if any of the files from the filelist appear in the trove-file, remove all of their information from the trove-file.

    char pathname[100] = ""; // TODO: change size
    char *ret;
    // FILE *fp;
    // fp = fopen("rm.txt", "r+"); // TODO:
    for (int i = 0; i < filelist_num; i++)
    {
        if (filelist_num == 1 && i == 1)
        { // since segmentation fault happens when i == 1 cuz for loop is weird like dat
            break;
        }
        printf("filelist[i] %s\n", filelist[i]); // trying to print all the values in filelist
    }

    for (int i = 0; i < filelist_num; i++)
    {
        if (filelist_num == 1 && i == 1)
        { // since segmentation fault happens when i == 1 cuz for loop is weird like dat
            break;
        }

        strcpy(pathname, "@");                    // pathname initially has @ in it
        char *real = realpath(filelist[i], NULL); // trying to get the realpath of file in filelist
        strcat(pathname, real);                   // need to copy the !!realpath!! name of filelist into pathname
        printf("pathname %s\n", pathname);
        ret = strstr(trovefilename, pathname); // TODO: need to read trovefile without opening it
        if (ret == NULL)
        {
            printf("File pathname not found in trovefile/some error idk\n");
        }
        printf("ret %s\n", ret);

        //  if found, remove from trovefile
        //  remove all information in trovefile for that file
    }
    return;
}