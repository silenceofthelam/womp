#include <stdlib.h>
#include <string.h>
#include "./debug.h"

char * permutate(char *first_word, char *second_word)
{
	int new_string_length;
	char *permutated_string;

	new_string_length = strlen(first_word) + strlen(second_word) + 1;

	permutated_string = (char *)malloc(new_string_length);

	strcpy(permutated_string, first_word);
	strcat(permutated_string, second_word);

	return permutated_string;
}	
