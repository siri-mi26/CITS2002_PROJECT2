#include "trove.h"
#include <stdbool.h>


#define FILENAME_SIZE 1024
#define MAX_LINE 2048

void remove_trove(char *trovefilename, char **filelist, int filelist_num)
{
    FILE *file;
    FILE *temp;

    //char filename[FILENAME_SIZE];
    char temp_filename[FILENAME_SIZE];

    char buffer[MAX_LINE];

    //int delete_line = 0;

    //printf("File: ");
    //scanf("%s", filename);

    strcpy(temp_filename, "temp____");
    strcat(temp_filename, trovefilename);


    //printf("Delete Line: ");
    //scanf("%d", &delete_line);

    file = fopen(trovefilename, "r");
    temp = fopen(temp_filename, "w");

    if (file == NULL || temp == NULL) {
        printf("Error opening files(s)\n");
        exit(EXIT_FAILURE);
    }

    bool keep_reading = true;

    char *filename_path = realpath(filelist[0], NULL);
    printf("path: %s\n", filename_path);
    bool skip = false;
    //int current_line = 1;
    do
    {

        fgets(buffer, MAX_LINE, file);
        printf("buffer: %s\n", buffer);
        if (feof(file)) {
            keep_reading = false;
        }
        if (skip == true) {
            skip = false;
            continue;
        }
        else if (strstr(buffer, filename_path) == false) {
            fputs(buffer, temp);
            //current_line++;
            printf("Adding line\n");
        }
        else {
            printf("Removing 2 lines\n");
            skip = true;

            //current_line++;
            //current_line++;
        }
    }while (keep_reading);

    fclose(file);
    fclose(temp);

    remove(trovefilename);
    rename(temp_filename, trovefilename);


}