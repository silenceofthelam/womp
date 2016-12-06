/** Defines a structure to hold
  * pointers to functions that operate
  * with two strings and the
  * functions to operate on the structure.
  *
  * @file operations_container.h
  */

#define MAX_DEFINED_OPERATIONS 1
#define NULL 0;

struct operations {
  int number_of_operations;
  int(*functions[MAX_DEFINED_OPERATIONS])
    (char** first_string, char** second_string);
};


int add_operation(struct operations* container, int (*function)());

int (*get_function_at(struct operations* container, int position))();
