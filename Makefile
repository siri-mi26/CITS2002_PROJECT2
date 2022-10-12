all:
	cc -std=c11 -Wall -Werror trove.c search_word.c find_file.c build_trovefile.c -o trove