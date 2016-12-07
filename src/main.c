/** WOMP main function
  * 
  * @file main.c
  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "./running_config.h"
#include "./operations_container.h"
#include "./womp.h"

/** Forward Declarations **/
void process_commandline_arguements(int argc, char** argv, struct operations* operations, 
                                    struct running_config* config);
void operate_on_string(char* operable_string, struct operations* operations,
                       struct running_config* config);
void print_usage();


/** Constants **/
const char* command_line_options = "po:i:h";
const char* usage =
"Usage: womp <options>\n"
"<options>:\n"
"-p             permutate all words in input file with every other word in file.\n"
"-i <filename>  choose which file to read input from.\n"
"-o <filename>  choose which file to output words to.\n"
"Default behavior is to read from stdin and write to stdout.\n"
"womp does not perform any manipulations unless specified.\n";


int main(int argc, char** argv)
{
  struct operations operations;
  struct running_config config;
  char* line_buffer;
  size_t length_of_line_buffer = 129; // 128 characters + '\0'
  ssize_t num_characters_read;
  FILE* temporaryFile;

  operations.number_of_operations = 0;

  process_commandline_arguements(argc, argv, &operations, &config);

  line_buffer = malloc(length_of_line_buffer);

  if(!line_buffer)
  {
    printf("Could allocate memory for line buffer.\n");
    printf("Aborting...\n");
    exit(EXIT_FAILURE);
  }
    
  // Need a file if using permutation to seek in file
  if(config.performing_permutation && config.using_input_stream)
  {
    temporaryFile = tmpfile();
    while((num_characters_read = 
           getline(&line_buffer, &length_of_line_buffer, stdin)) != -1)
    {
      fprintf(temporaryFile, "%s", line_buffer);
    }
      
    stdin = temporaryFile;
    fseek(stdin, 0, SEEK_SET);
  }

  while((num_characters_read = 
         getline(&line_buffer, &length_of_line_buffer, stdin)) != -1)
  {
    // Get rid of trailing newline
    if(line_buffer[num_characters_read - 1] == '\n')
    {
      line_buffer[num_characters_read - 1] = '\0';
    }

    operate_on_string(line_buffer, &operations, &config);
  }


  /*if(show_stats)
  {
    print_stats();
  }*/

  free(line_buffer);

  return 0;
}


void process_commandline_arguements(int argc, char** argv, struct operations* operations,
                                    struct running_config* config)
{
  int opt;

  while((opt = getopt(argc, argv, command_line_options)) != -1)
  {
    switch(opt)
    {
      case 'p':
  //      printf("P option present.\n");
        if(!add_operation(operations, permutate_all))
        {
          printf("could not add permutation function to operations\nAborting...\n");
          exit(EXIT_FAILURE);
        }
        config->performing_permutation = 1; // True
        break;
      case 'o':
 //       printf("O option present with arguement %s.\n", optarg);
        if(!freopen(optarg, "w", stdout))
        {
          printf("Could not open file '%s'\nAborting.\n", optarg);
          exit(EXIT_FAILURE);
        }
        break;
      case 'i':
//        printf("I option present with arguement %s.\n", optarg);
        if(!freopen(optarg, "r", stdin))
        {
          printf("Could not open file '%s'\nAborting.\n", optarg);
          exit(EXIT_FAILURE);
        }
        config->using_input_stream = 0; // False
        break;
      case 'h':
      default:
        print_usage();
        exit(EXIT_SUCCESS);
        break;
    }
  }
}


void operate_on_string(char* operable_string, struct operations* operations,
                       struct running_config* config)
{
  for(int i = 0; i < operations->number_of_operations; i++)
  {
    void (*operation)() = get_function_at(operations, i);

    if(operation != NULL)
    {
      operation(operable_string, config);
    }
    else
    {
      printf("Could not get the operation function.\nAborting...\n");
      exit(EXIT_FAILURE);
    }
  }
}

void print_usage()
{
  puts(usage);
}
