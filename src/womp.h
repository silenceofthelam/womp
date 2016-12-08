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

  * @file womp.h
  */

#ifndef __womp__h
#define __womp__h

#include <stdio.h>
#include <stdlib.h>
#include "./womp_defines.h"
#include "./running_config.h"
#include "../lib/io.h"
#include "../lib/string_manipulations.h"

void permutate_all(char* string, struct running_config* config);

#endif
