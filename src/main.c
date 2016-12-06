/** WOMP main function
  * 
  * @file main.c
  */

#include <unistd.h>
#include <stdio.h>

/** Forward Declarations **/
void process_commandline_arguements(int argc, char** argv);


/** Constants **/
const char* command_line_options = "poi";


/* The commented out lines
are functions/operations that
are to be implemented at a later date.
They are more of a pseudocode than anything.
*/

int main(int argc, char** argv)
{

  process_commandline_arguements(argc, argv);

  // open(output);

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
        printf("O option present.\n");
        break;
      case 'i':
        printf("I option present.\n");
        break;
      default:
        break;
    }
  }
}