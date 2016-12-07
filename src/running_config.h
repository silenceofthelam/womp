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
  FILE* original_stdout;
  int using_input_stream;
};

void default_config(struct running_config* config);

#endif
