/** The operations
  * performed on the strings
  * by the womp main program.

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

  * @file womp.c
  */

#include "./womp.h"


void permutate_all(char* string, struct running_config* config)
{ 
  long int orig_stdin_file_position;
  char* line_buffer;
  size_t length_of_line_buffer = 129; // 128 characters + '\0'
  char* new_string;


  if(!stdin)
  {
    fputs("input not a valid file descriptor.\nExiting function permutate_all\n", stderr);
    return;
  }

  line_buffer = malloc(length_of_line_buffer);
  memcheck(line_buffer);

  orig_stdin_file_position = ftell(stdin);

  if(fseek(stdin, 0, SEEK_SET) != 0)
  {
    fputs("Could not seek to beginnin of input.\nExiting function permutate_all\n", stderr);
    free(line_buffer);
    return;
  }

  while(getline_remove_newline(&line_buffer, &length_of_line_buffer, stdin) != -1)
  {
    new_string = concatenate(string, line_buffer);

    if(new_string)
    {
      puts(new_string);
      free(new_string);
    }
  }

  if(fseek(stdin, orig_stdin_file_position, SEEK_SET) != 0)
  {
    free(line_buffer);
    DIE("Could not seek to original input position.", EXIT_FAILURE);
  }

  free(line_buffer);
}
