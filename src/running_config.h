/** Defines a structure to hold
  * the configuration for the program
  * as it is running.
  *
  * @file operations_container.c
  */

#ifndef __running_config__h
#define __running_config__h

#include <stdio.h>

struct running_config {
  int performing_permutation;
  int using_input_stream;
  FILE* original_stdin;
  FILE* original_stdout;
  FILE* temp_file;
};

void default_config(struct running_config* config);

#endif
