all:
	cc -std=c11 -Wall -Werror trove.c search_word.c find_file.c hash_table.c create_trovefile.c -o trove