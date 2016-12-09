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

  * @file operations_container.h
  */

#ifndef __operations_container__h
#define __operations_container__h

#include <stddef.h>
#include <stdio.h>
#include "./running_config.h"

#define MAX_DEFINED_OPERATIONS 1

struct operations {
  int number_of_operations;
  int (*functions[MAX_DEFINED_OPERATIONS]) // Array of pointers to functions
      (char*, struct running_config*);
};

void initialize_operations(struct operations* operations);

int add_operation(struct operations* container, int (*function)());

int (*get_function_at(struct operations* container, int position))
    (char*, struct running_config*);

#endif
