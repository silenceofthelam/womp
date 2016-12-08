#include "string_manipulations.h"

char * concatenate(char *first_word, char *second_word)
{
	int new_string_length;
	char *permutated_string;

	new_string_length = strlen(first_word) + strlen(second_word) + 1;

	permutated_string = (char *)malloc(new_string_length);

	strcpy(permutated_string, first_word);
	strcat(permutated_string, second_word);

	return permutated_string;
}	

char * capitalize_nth_character(char *original_word, int character_to_capitalize)
{
	char *new_word = (char *)malloc(strlen(original_word) + 1);
	int i;

	for(i = 0; i < strlen(original_word); i++)
	{
		new_word[i] = original_word[i];

		if(i == (character_to_capitalize - 1))
		{
			new_word[i] = new_word[i] >= 'a' ? 
				(new_word[i] - ('a' - 'A')) : new_word[i];
		}
	}

	new_word[i] = '\0';

	return new_word;
}
