/** Functions to manipulate strings.
  * Each function returns a pointer
  * to a new string. This new pointer
  * must be freed by the client.
  *
  * @file string_manipulations.h
  */

#ifndef __word__h
#define __word__h

#include <stdlib.h>
#include <string.h>

char * concatenate(char *first_word, char *second_word);

char * capitalize_nth_character(char *original_word, int character_to_capitalize);

#endif
