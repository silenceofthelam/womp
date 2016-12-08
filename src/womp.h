/** The operations
  * performed on the strings
  * by the womp main program.
  *
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
