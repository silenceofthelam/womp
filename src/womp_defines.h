/** Defines to be used
  * throughout the project's
  * source files.
  */

#ifndef __womp_defines__h
#define __womp_defines__h

#define DIE(message, status) \
  fputs((message), stderr); exit((status))

#endif
