#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./debug.h"

#define MAX_BUFFER_SIZE 512

int print_to_stdout()
{
	DEBUG("START");
	int total_output_words = 0;
	char *character_buffer;

	DEBUG("malloc");
	character_buffer = (char *)malloc(MAX_BUFFER_SIZE);

	while(fgets(character_buffer, MAX_BUFFER_SIZE, stdin) != NULL)
	{

		DEBUG("fgets");
		DEBUG("puts");
		fputs(character_buffer, stdout);

		total_output_words++;
	}

	return total_output_words;
}

char * permutate(char *first_word, char *second_word)
{
	int new_string_length;
	char *permutated_string;

	new_string_length = strlen(first_word) + strlen(second_word) - 1;

	permutated_string = (char *)malloc(new_string_length);

	strcpy(permutated_string, first_word);
	strcat(permutated_string, second_word);

	return permutated_string;
}	
