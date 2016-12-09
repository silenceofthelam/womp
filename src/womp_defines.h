/** Defines to be used
  * throughout the project's
  * source files.

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

  * @file womp_defines.h
  */

#ifndef __womp_defines__h
#define __womp_defines__h


#define DIE(message, status) \
  fputs((message "\nAborting\n"), stderr); exit((status))

#define memcheck(mem) if(!mem) { DIE("Could not allocate memory.", EXIT_FAILURE); }

enum WOMP_STATUS { WOMP_OK = 0, WOMP_NOT_OK = 1 };

#endif
