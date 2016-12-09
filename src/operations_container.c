/** Defines a structure to hold
  * pointers to functions that operate
  * with two strings and the
  * functions to operate on the structure.

    Copyright (C) 2016 Dustin LaMIaux - SilenceOfTheLam 

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

  * @file operations_container.c
  */

#include "./operations_container.h"

void initialize_operations(struct operations* operations)
{
  operations->number_of_operations = 0;
}

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

int (*get_function_at(struct operations* container, int position))
    (char*, struct running_config*)
{
  if((position < container->number_of_operations) && (position >= 0))
  {
    return container->functions[position];
  }

  return NULL;
}
