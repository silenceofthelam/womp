/** Defines to be used
  * throughout the project's
  * source files.
  */

#ifndef __womp_defines__h
#define __womp_defines__h

#define DIE(message, status) \
  fputs((message "\nAborting\n"), stderr); exit((status))

#define memcheck(mem) if(!mem) { DIE("Could not allocate memory.", EXIT_FAILURE); }

#endif
