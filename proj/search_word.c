#include "trove.h"
/* 
TODO: change comment from "returned" to ?? after its done (mebe)
This function searches a given filename and returns all the words (once per word)
If length parameter is supplied, only words less than or equal to that length will be returned
@filename 
@length 
 */
char** search_word(char* filename, int length)
{
    //printf("%s\n", filename);
    // Open file
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {                             // Error checking
        printf("Couldn't open file\n");
        exit(EXIT_FAILURE);
    }
    // Get length (number of characters) in file
    fseek(file, 0, SEEK_END);
    int file_length = ftell(file);
    fseek(file, 0, SEEK_SET);
    // Initialize string for size of length
    char *string = malloc(sizeof(char) * (file_length + 1));
    //char *string = malloc(strlen(file_length) + 1);
    // Initialize characters/indexes
    char c;
    int i = 0;
    int k = 0;
    int j = 0;
    int limit = 2;
    // Initialize array to hold strings
    char ** strings = malloc(limit * sizeof(char*));
    // Set the first value of the array to the name of the file
    char *full_pathname = realpath(filename, NULL);
    strings[j] = malloc(strlen(full_pathname) * sizeof(char) + 1);
    strcpy(strings[j], full_pathname);
    j++;
    // Loop over file getting each character, and adding it to the string
    while((c = fgetc(file)) != EOF) 
    {
        string[i] = c;                  // Add our character to our current string word
        i++;
        // Detect non-alphanumeric character
        if (isalnum(c) == 0) {
            string[i - 1] = '\0';
            if (strlen(string) != 0 && strlen(string) >= length) {
                // If words reaches word limit, reallocate more memory
                if (j == limit) {
                    limit = limit * 2;
                    strings = realloc(strings, limit * sizeof(char*));
                    printf("limit: %i\n", limit);
                    printf("reallocing: %li\n", limit * sizeof(char*));
                }
                strings[j] = malloc(strlen(string) * sizeof(char) + 1);
                strcpy(strings[j], string);
                j++;
            }
            // "Reset string"
            for (k = 0; k < (i + 1); k++) {
                string[k] = '\0';
            }
            i = 0;
        }
    }
    // Add last word before \0, if valid
    if (isalnum(string[0]) != 0 && length <= 1) {
        strings[j] = malloc(strlen(string) * sizeof(char));
        strcpy(strings[j], string);
    }
    else {
        j--;
    }
    fclose(file);

     
    // for (i = 0; i < (j + 1); i++) {
    //     printf("strings[%i], %s\n", i, strings[i]);
    // }


    return strings;
}