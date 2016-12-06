/** WOMP main function
  * 
  * @file main.c
  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "./operations_container.h"

/** Forward Declarations **/
void process_commandline_arguements(int argc, char** argv);


/** Constants **/
const char* command_line_options = "po:i:";


/* The commented out lines
are functions/operations that
are to be implemented at a later date.
They are more of a pseudocode than anything.
*/

int main(int argc, char** argv)
{

  process_commandline_arguements(argc, argv);


  /*while(!EOF)
  {
    readline

    operate

    print to output
  } */

  /*if(show_stats)
  {
    print_stats();
  }*/

  return 0;
}


void process_commandline_arguements(int argc, char** argv)
{
  int opt;

  while((opt = getopt(argc, argv, command_line_options)) != -1)
  {
    switch(opt)
    {
      case 'p':
        printf("P option present.\n");
        break;
      case 'o':
        printf("O option present with arguement %s.\n", optarg);
        if(!freopen(optarg, "w", stdout))
        {
          printf("Could not open file '%s'\nAborting.\n", optarg);
          exit(EXIT_FAILURE);
        }
        break;
      case 'i':
        printf("I option present with arguement %s.\n", optarg);
        if(!freopen(optarg, "r", stdin))
        {
          printf("Could not open file '%s'\nAborting.\n", optarg);
          exit(EXIT_FAILURE);
        }
        break;
      default:
        break;
    }
  }
}
