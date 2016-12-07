#include "./io.h"

//static long total_input_words = 0;
//static long total_output_words = 0;

ssize_t getline_remove_newline(char** lineptr, size_t* n, FILE* stream)
{
  ssize_t num_characters_read;

  num_characters_read = getline(lineptr, n, stream);

  if(num_characters_read != -1)
  {
    if((*lineptr)[num_characters_read - 1] == '\n')
    {
      (*lineptr)[num_characters_read - 1] = '\0';
    }
  }

  return num_characters_read;
}

/*
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
*/
