/** WOMP main function
  * 
  * @file main.c
  */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "./womp_defines.h"
#include "./running_config.h"
#include "./operations_container.h"
#include "./io.h"
#include "./womp.h"

/** Forward Declarations **/
void process_commandline_arguements(int argc, char** argv, struct operations* operations, 
                                    struct running_config* config);
FILE* createTemporaryFile(char** line_buffer, size_t* length_of_line_buffer);
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


  initialize_operations(&operations);
  default_config(&config);

  process_commandline_arguements(argc, argv, &operations, &config);

  line_buffer = malloc(length_of_line_buffer);
  memcheck(line_buffer);
    
  // Need a file if using permutation to seek in file
  if(config.performing_permutation && config.using_input_stream)
  {
    stdin = createTemporaryFile(&line_buffer, &length_of_line_buffer);
  }

  while(getline_remove_newline(&line_buffer, &length_of_line_buffer, stdin) != -1)
  {
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
        if(!add_operation(operations, permutate_all))
        {
          DIE("Could not add permutation function to operations.", EXIT_FAILURE);
        }
        config->performing_permutation = 1; // True
        break;
      case 'o':
        if(!freopen(optarg, "w", stdout))
        {
          DIE("Could not open file specified by -o option.", EXIT_FAILURE);
        }
        break;
      case 'i':
        if(!freopen(optarg, "r", stdin))
        {
          DIE("Could not open file specified by -i option.", EXIT_FAILURE);
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

FILE* createTemporaryFile(char** line_buffer, size_t* length_of_line_buffer)
{
  FILE* temporaryFile;

  temporaryFile = tmpfile();
  while(getline(line_buffer, length_of_line_buffer, stdin) != -1)
  {
    fprintf(temporaryFile, "%s", *line_buffer);
  }
    
  fseek(temporaryFile, 0, SEEK_SET);
  
  return temporaryFile;
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
