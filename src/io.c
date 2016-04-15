#include <stdio.h>
#include <stdlib.h>
#include "./debug.h"

#define MAX_BUFFER_SIZE 512

static long total_output_words = 0;

void print_to_stdout(char *string_to_print)
{
	DEBUG("START");

	DEBUG("puts");
	puts(string_to_print);

	total_output_words++;
}
