/** Functions to manipulate strings.
  * Each function returns a pointer
  * to a new string. This new pointer
  * must be freed by the client.

    Copyright (C) 2016 Dustin LaMIaux - SilenceOfTheLam 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

  * @file string_manipulations.c
  */

#include "string_manipulations.h"


char * concatenate(char *first_word, char *second_word)
{
	int new_string_length;
	char *concatenated_string;

	new_string_length = strlen(first_word) + strlen(second_word) + 1;

	concatenated_string = malloc(new_string_length);

  if(concatenated_string != NULL)
  {
    strcpy(concatenated_string, first_word);
    strcat(concatenated_string, second_word);
  }

	return concatenated_string;
}	

char * capitalize_nth_character(char *original_word, int character_to_capitalize)
{
	char *new_word;
	int i;
  
  new_word = malloc(strlen(original_word) + 1);
  
  if(new_word != NULL)
  {
    for(i = 0; i < strlen(original_word); i++)
    {
      new_word[i] = original_word[i];

      if(i == (character_to_capitalize - 1))
      {
        if(original_word[i] >= 'a' && original_word[i] <= 'z')
        {
          new_word[i] = original_word[i] - ('a' - 'A');
        }
      }
    }

    new_word[i] = '\0';
  }


	return new_word;
}
