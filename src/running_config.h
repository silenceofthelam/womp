/** Defines a structure to hold
  * the configuration for the program
  * as it is running.
  *
  * @file operations_container.c
  */

#ifndef __running_config__h
#define __running_config__h



struct running_config {
  int performing_permutation;
}

void default_config(struct running_config* config);
