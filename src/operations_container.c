/** Defines a structure to hold
  * pointers to functions that operate
  * with two strings and the
  * functions to operate on the structure.
  *
  * @file operations_container.c
  */

#include "./operations_container.h"


int add_operation(struct operations* container, int (*function)())
{
  int number_of_operations = container->number_of_operations;

  if(number_of_operations < MAX_DEFINED_OPERATIONS)
  {
    container->functions[number_of_operations] = function;
    container->number_of_operations++;
    return 1; // True;
  }

  return 0; // False;
}

int (*get_function_at(struct operations* container, int position))()
{
  if((position < container->number_of_operations) && (position > 0))
  {
    return container->functions[position];
  }

  return NULL;
}
