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
    char *trove_word;
    //int success = 0;
    int line_counter = 0;
    char c;

    // Get number of lines
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            line_counter++;
        }
    }
    printf("Number of lines: %i\n", line_counter);
    //int file_p[line_counter];
    int test[line_counter];
    int counter = 0;
    int i = 0;
    for (i = 0; i < line_counter; i++) {
        test[i] = 0;
    }
    rewind(file);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    do
    {
        printf("counter: %i\n", counter);
        fgets(buffer, MAX_LINE, file);
        printf("buffer: %s\n", buffer);
        if (feof(file)) {
            keep_reading = false;
            break;
        }
        if (buffer[0] == '@') {
            printf("^@\n");
            // file_p[i] = ftell(file);
            // printf("file_p[%i] = %i\n", i, file_p[i]);
            counter++;
            continue;
        }
        else {
            printf("in else\n");
            trove_word = strtok(buffer, " ");
            while (trove_word != NULL)
            {
                if (strcmp(trove_word, word) == 0) {
                    printf("This one has the word\n");
                    test[counter] = 1;
                    break;
                }
                trove_word = strtok(NULL, " ");
            }
            counter++;
        }
    }while (keep_reading);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    rewind(file);
    counter = 1;
    keep_reading = true;
    do
    {
        //printf("counter: %i\n", counter);
        fgets(buffer, MAX_LINE, file);
        //printf("buffer: %s\n", buffer);
        if (feof(file)) {
            keep_reading = false;
            break;
        }
        if (test[counter] == 1) {
            printf("%s\n", buffer);
        }
        counter++;
    }while (keep_reading);

    fclose(file);
}