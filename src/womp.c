#include "./womp.h"


void permutate_all(char* string, struct running_config* config)
{ 
  long int orig_stdin_file_position;
  char* line_buffer;
  size_t length_of_line_buffer = 129; // 128 characters + '\0'
  char* new_string;


  if(!stdin)
  {
    fputs("input not a valid file descriptor.\nExiting function permutate_all\n", stderr);
    return;
  }

  line_buffer = malloc(length_of_line_buffer);
  memcheck(line_buffer);

  orig_stdin_file_position = ftell(stdin);

  if(fseek(stdin, 0, SEEK_SET) != 0)
  {
    fputs("Could not seek to beginnin of input.\nExiting function permutate_all\n", stderr);
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
    DIE("Could not seek to original input position.", EXIT_FAILURE);
  }

  if(line_buffer)
  {
    free(line_buffer);
  }
}
