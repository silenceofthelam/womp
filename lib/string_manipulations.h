/** Functions to manipulate strings.
  * Each function returns a pointer
  * to a new string. This new pointer
  * must be freed by the client.

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

  * @file string_manipulations.h
  */

#ifndef __word__h
#define __word__h

#include <stdlib.h>
#include <string.h>

#define prepend_string(string_to_prepend_to, string_to_prepend) \
          concatenate((string_to_prepend), (string_to_prepend_to))

#define append_string(string_to_append_to, string_to_append) \
          concatenate((string_to_append_to), (string_to_append))

char * concatenate(char *first_word, char *second_word);

char * capitalize_nth_character(char *original_word, int character_to_capitalize);

#endif
