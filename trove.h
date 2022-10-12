/* Trove header file containing required functions for all the other files */

void commandline_checker();
void get_trovefile();

void search_trovefile();
void index_file();
void find_word();

void search_word(char word[]);

// DONE
int hash_table();
void create_trovefile();

int find_file(int argc, char* argv[]);