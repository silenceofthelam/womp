/** Input/Output sepecific functions

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
    
  * @file io.h
  */

#include "./io.h"

ssize_t getline_remove_newline(char** lineptr, size_t* n, FILE* stream)
{
  ssize_t num_characters_read;

  num_characters_read = getline(lineptr, n, stream);

  if(num_characters_read != -1)
  {
    if((*lineptr)[num_characters_read - 1] == '\n')
    {
      (*lineptr)[num_characters_read - 1] = '\0';
    }
  }

  return num_characters_read;
}
