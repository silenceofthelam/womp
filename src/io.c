#include <stdio.h>
#include <stdlib.h>
#include "./debug.h"

static long total_input_words = 0;
static long total_output_words = 0;

char * get_next_word()
{
	char * word;

	word = gets();

	if(word != NULL)
	{
		total_input_words++;
	}

	return word;
}

void print_to_stdout(char *string_to_print)
{
	DEBUG("START");

	DEBUG("puts");
	puts(string_to_print);

	total_output_words++;
}

long get_total_input_words()
{
	return total_input_words;
}

long get_total_output_words()
{
	return total_output_words;
}
