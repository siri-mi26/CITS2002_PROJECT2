#include "trove.h"

#define MAX_LINE 2048
void print_stripped(char *word) {
    //Strip the '@' from the filepath, and print
    word = word + 1;
    printf("%s", word);
}

int search_trove(char *trove_filename, char *word)
{
    printf("important word: %s\n", word);
    FILE *file;

    char buffer[MAX_LINE];
    int success = 0;


    file = fopen(trove_filename, "r");

    if (file == NULL) {
        printf("Could not open file: %s\n", trove_filename);
        exit(EXIT_FAILURE);
    }

    bool keep_reading = true;
    char *trove_word;
    int line_counter = 0;
    char c;

    // Get number of lines
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            line_counter++;
        }
    }
    int word_arr[line_counter];
    int counter = 0;
    int i = 0;
    for (i = 0; i < line_counter; i++) {
        word_arr[i] = 0;
    }
    rewind(file);
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    do
    {
        fgets(buffer, MAX_LINE, file);
        if (feof(file)) {
            keep_reading = false;
            break;
        }
        if (buffer[0] == '@') {
            counter++;
            continue;
        }
        else {
            trove_word = strtok(buffer, " ");
            while (trove_word != NULL)
            {
                if (strcmp(trove_word, word) == 0) {
                    word_arr[counter] = 1;
                    success = 1;
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
        fgets(buffer, MAX_LINE, file);
        if (feof(file)) {
            keep_reading = false;
            break;
        }
        if (word_arr[counter] == 1) {
            print_stripped(buffer);
        }
        counter++;
    }while (keep_reading);

    fclose(file);

    return success;
}