#include "./womp.h"


void permutate_all(char* string, struct running_config* config)
{ 
  long int orig_stdin_file_position;
  char* line_buffer;
  size_t length_of_line_buffer = 129; // 128 characters + '\0'
  char* new_string;


  if(!stdin)
  {
    printf("input not a valid file descriptor.\nExiting function permutate_all");
    return;
  }

  line_buffer = malloc(length_of_line_buffer);

  if(!line_buffer)
  {
    free(line_buffer);
    printf("Could allocate memory for line buffer.\n");
    printf("Aborting...\n");
    exit(EXIT_FAILURE);
  }

  orig_stdin_file_position = ftell(stdin);

  if(fseek(stdin, 0, SEEK_SET) != 0)
  {
    printf("Could not seek to beginnin of input.\nExiting function permutate_all");
    if(line_buffer)
    {
      free(line_buffer);
    }
    return;
  }


  while(getline_remove_newline(&line_buffer, &length_of_line_buffer, stdin) != -1)
  {
    new_string = permutate(string, line_buffer);

    if(new_string)
    {
      puts(new_string);
      free(new_string);
    }
  }

  if(fseek(stdin, orig_stdin_file_position, SEEK_SET) != 0)
  {
    printf("Could not seek to original input position.\nAborting...\n");
    exit(EXIT_FAILURE);
  }

  free(line_buffer);
}
