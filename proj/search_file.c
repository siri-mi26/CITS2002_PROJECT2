#include "trove.h"


void search_file(char* filename)
{
    printf("%s\n", filename);
    // Open file
    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL) {                             // Error checking
        printf("Couldn't open file\n");
        return;
    }
    // Get length (number of characters) in file
    fseek(file, 0, SEEK_END);
    int file_length = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Initialize string for size of length
    char *string = malloc(sizeof(char) * (file_length + 1));

    // Initialize characters/indexes
    char c;
    int i = 0;
    int k = 0;
    int j = 0;
    int limit = 8;
    // Initialize array to hold strings
    char ** strings = malloc(limit * sizeof(char*));
    // Loop over file getting each character, and adding it to the string
    while((c = fgetc(file)) != EOF) 
    {
        string[i] = c;                  // Add our character to our current string word
        i++;
        // Detect non-alphanumeric character
        if (isalnum(c) == 0) {
            string[i - 1] = '\0';
            if (strlen(string) != 0) {
                // If words reaches word limit, reallocate more memory
                if (j == limit) {
                    limit = limit * 2;
                    strings = realloc(strings, limit * sizeof(char*));
                }
                strings[j] = malloc(strlen(string) * sizeof(char));
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
    if (isalnum(string[0]) != 0) {
        strings[j] = malloc(strlen(string) * sizeof(char));
        strcpy(strings[j], string);
    }
    else {
        j--;
    }

    fclose(file);                   // Close file
    
    // Print words
    for (i = 0; i < (j + 1); i++) {
        printf("%s\n", strings[i]);
    }
    return;
}