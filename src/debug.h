/* Defines several debug macros */

#ifndef __debug__h
#define __debug__h

#ifdef VDEBUG

#define DEBUG(S) printf("[DEBUG]\tRunning test on %s in function %s on line %d\n", S, __func__, __LINE__)

#else

#define DEBUG(S) 
#endif
#endif
