/** Defines a structure to hold
  * pointers to functions that operate
  * with two strings and the
  * functions to operate on the structure.
  *
  * @file operations_container.h
  */

#ifndef __operations_container__h
#define __operations_container__h

#include <stddef.h>
#include <stdio.h>

#define MAX_DEFINED_OPERATIONS 1

struct operations {
  int number_of_operations;
  void (*functions[MAX_DEFINED_OPERATIONS])
    (char** first_string, FILE* input);
};

void initialize_operations(struct operations* operations);

int add_operation(struct operations* container, void (*function)());

void (*get_function_at(struct operations* container, int position))();

#endif
