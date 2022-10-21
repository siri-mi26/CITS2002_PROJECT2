#include "trove.h"

#define FILENAME_SIZE 1024
#define MAX_LINE 2048

/* Remove filenames listen in the given filelist, and all corresponding words
   Create a temporary file, adding data we want from the trovefile
   After adding all wanted data, delete the old trovefile and rename the temporary to the original trovefile*/
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
        perror("Error");
        exit(EXIT_FAILURE);
    }

    bool keep_reading = true;
    char *filename_path;
    bool skip = false;
    bool keep;
    int i;
    // Loop over lines in the trovefile
    do
    {
        keep = false;
        fgets(buffer, MAX_LINE, file);
        if (skip == true) {     // If the pathname was to be removed, ignore corresponding words
            skip = false;
            continue;
        }
        if (feof(file)) {       // End of file
            keep_reading = false;
            break;
        }
        for (i = 0; i < filelist_num; i++) {
            filename_path = realpath(filelist[i], NULL);
            if (strstr(buffer, filename_path) == false) {   // Check if filename is in given filelist
                keep = true;
            }
        }
        if (keep == true) {
            fputs(buffer, temp);
        }
        else {
            skip = true;
        }
    }while (keep_reading);

    fclose(file);
    fclose(temp);

    remove(trovefilename);
    rename(temp_filename, trovefilename);
    
}