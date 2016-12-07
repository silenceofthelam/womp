/** Input/Output sepecific functions
  *
  * @file io.h
  */

#include "./io.h"

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
