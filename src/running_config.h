/** Defines a structure to hold
  * the configuration for the program
  * as it is running.

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
