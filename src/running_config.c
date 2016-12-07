/** Defines a structure to hold
  * the configuration for the program
  * as it is running.
  *
  * @file operations_container.c
  */

#include "./running_config.h"

void default_config(struct running_config* config)
{
  config->performing_permutation = 0; // False
  config->original_stdout = stdout;
  config->using_input_stream = 1; // True
}
