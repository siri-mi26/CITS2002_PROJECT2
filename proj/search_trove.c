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
    int number_of_lines = 0;
    char c;

    // Get number of lines
    for (c = getc(file); c != EOF; c = getc(file)) {
        if (c == '\n') {
            number_of_lines++;
        }
    }
    printf("Number of lines: %i\n", number_of_lines);
    int file_p[number_of_lines];
    int test[number_of_lines];
    int i = 0;
    for (i = 0; i < number_of_lines; i++) {
        file_p[i] = -2;
        test[i] = 0;
    }
    i = 0;
    // Set file position back to beginning
    rewind(file);
    // Check for instances of the word
    // file_p[i] = ftell(file);
    // printf("file_p[%i] = %i\n", i, file_p[i]);
    // i++;

    do
    {
        file_p[i] = ftell(file);
        i++;
        //printf("file_p[%i] = %i\n", i, file_p[i]);
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
            continue;
        }
        else {
            printf("in else\n");
            trove_word = strtok(buffer, " ");
            while (trove_word != NULL)
            {
                if (strcmp(trove_word, word) == 0) {
                    printf("This one has the word\n");
                    test[i] = 1;
                    //i++;
                    // file_p[i] = ftell(file);
                    // i++;
                    break;
                }
                trove_word = strtok(NULL, " ");
            }
        }
    }while (keep_reading);
    file_p[i] = -2;
    
    char g;
    printf("Starting loop\n");
    i = 0;

    for (i = 0; i < number_of_lines; i++) {
        printf("filep thing: %i\n",file_p[i]);
        printf("test thing: %i\n", test[i]);
    }
    //char str[50];
    for (i = 0; file_p[i] != -2; i++) {
        printf("i: %i   file_p[i]:  %i\n", i, file_p[i]);
        if (i % 2 == 0) {
            fseek(file, file_p[i], SEEK_SET);
            g = fgetc(file);
            while (g != EOF) {
                printf("%c", g);
                g = fgetc(file);
                if (ftell(file) == file_p[i+1]) {
                    break;
                }
            }
            
        }
    }
    

    fclose(file);
}