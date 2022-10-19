#include "trove.h"

#define MAX_LINE 2048

void search_trove(char *trove_filename, char *word)
{
    printf("important word: %s\n", word);
    FILE *file;

    char buffer[MAX_LINE];


    file = fopen(trove_filename, "r");

    if (file == NULL) {
        printf("Could not open file: %s\n", trove_filename);
        exit(EXIT_FAILURE);
    }

    bool keep_reading = true;
    char *pathname = "";
    char *trove_word;
    //int success = 0;

    do
    {
        fgets(buffer, MAX_LINE, file);
        if (feof(file)) {
            keep_reading = false;
            break;
        }
        if (buffer[0] == '@') {
            strcpy(pathname, buffer);
            continue;
        }
        else {
            trove_word = strtok(buffer, " ");
            while (trove_word != NULL)
            {
                if (strcmp(trove_word, word) == 0) {
                    printf("%s\n", pathname);
                    continue;
                }
            }
        }
    }while (keep_reading);

    fclose(file);
}