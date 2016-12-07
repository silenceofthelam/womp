#ifndef __io__h
#define __io__h

#include <stdio.h>
#include <stdlib.h>

ssize_t getline_remove_newline(char** lineptr, size_t* n, FILE* stream);

/*
char * get_next_word();

void print_to_stdout(char *string_to_print[]);

long get_total_input_words();

long get_total_output_words();
*/
#endif
