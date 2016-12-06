/** WOMP main function
  * 
  * @file main.c
  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "./operations_container.h"
#include "../lib/word.h"

/** Forward Declarations **/
void process_commandline_arguements(int argc, char** argv, struct operations* operations);
void operate_on_string(char* operable_string, struct operations* operations);


/** Constants **/
const char* command_line_options = "po:i:";


/* The commented out lines
are functions/operations that
are to be implemented at a later date.
They are more of a pseudocode than anything.
*/

int main(int argc, char** argv)
{
  struct operations operations;
  operations.number_of_operations = 0;
  char *line_buffer;
  size_t length_of_line_buffer = 129; // 128 characters + '\0'
  ssize_t num_characters_read;

  process_commandline_arguements(argc, argv, &operations);

  line_buffer = malloc(length_of_line_buffer);

  if(!line_buffer)
  {
    free(line_buffer);
    printf("Could allocate memory for line buffer.\n");
    printf("Aborting...\n");
    exit(EXIT_FAILURE);
  }
    

  while((num_characters_read = 
         getline(&line_buffer, &length_of_line_buffer, stdin)) != -1)
  {
    // Get rid of trailing newline
    if(line_buffer[num_characters_read - 1] == '\n')
    {
      line_buffer[num_characters_read - 1] = '\0';
    }

    operate_on_string(line_buffer, &operations);
  }

  /*if(show_stats)
  {
    print_stats();
  }*/

  free(line_buffer);

  return 0;
}


void process_commandline_arguements(int argc, char** argv, struct operations* operations)
{
  int opt;

  while((opt = getopt(argc, argv, command_line_options)) != -1)
  {
    switch(opt)
    {
      case 'p':
        printf("P option present.\n");
        if(!add_operation(operations, permutate))
        {
          printf("could not add permutation function to operations\nAborting...\n");
          exit(EXIT_FAILURE);
        }
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


void operate_on_string(char* operable_string, struct operations* operations)
{
  for(int i = 0; i < operations->number_of_operations; i++)
  {
    char* new_string;

    char* (*operation)() = get_function_at(operations, i);

    if(operation != NULL)
    {
      new_string = operation(operable_string, "con");
    }
    else
    {
      printf("Could not get the operation function.\nAborting...\n");
      exit(EXIT_FAILURE);
    }


    if(new_string)
    {
      puts(new_string);
      free(new_string);
    }
  }
}
