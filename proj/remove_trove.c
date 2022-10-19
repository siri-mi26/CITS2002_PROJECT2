#include "trove.h"
#include <stdbool.h>


#define FILENAME_SIZE 1024
#define MAX_LINE 2048

void remove_trove(char *trovefilename, char **filelist, int filelist_num)
{
    FILE *file;
    FILE *temp;

    char temp_filename[FILENAME_SIZE];

    char buffer[MAX_LINE];

    strcpy(temp_filename, "temp____");
    strcat(temp_filename, trovefilename);

    file = fopen(trovefilename, "r");
    temp = fopen(temp_filename, "w");

    if (file == NULL || temp == NULL) {
        exit(EXIT_FAILURE);
    }

    bool keep_reading = true;

    char *filename_path = realpath(filelist[0], NULL);
    bool skip = false;
    do
    {

        fgets(buffer, MAX_LINE, file);
        printf("buffer: %s\n", buffer);
        if (skip == true) {
            skip = false;
            continue;
        }
        if (feof(file)) {
            keep_reading = false;
        }
        else if (strstr(buffer, filename_path) == false) {
            fputs(buffer, temp);
        }
        else {
            printf("Removing 2 lines\n");
            skip = true;
        }
    }while (keep_reading);

    fclose(file);
    fclose(temp);

    remove(trovefilename);
    rename(temp_filename, trovefilename);


}