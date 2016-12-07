/** Input/Output sepecific functions
  *
  * @file io.h
  */

#ifndef __io__h
#define __io__h

#include <stdio.h>

ssize_t getline_remove_newline(char** lineptr, size_t* n, FILE* stream);

#endif
