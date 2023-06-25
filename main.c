#include "monty.h"

global_var var_global;

/**
 * main - driver function for monty program
 * @argc: int num of arguments
 * @argv: opcode file
 * Return: 0
 */
int main(int argc, char **argv)
{
  char *content;
  FILE *file;
  size_t size = 0;
  ssize_t read_line = 1;
  stack_t *stack = NULL;
  unsigned int counter = 0;

  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }
  file = fopen(argv[1], "r");
 var_global.file = file;
  if (!file)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  while ((read_line = getline(&content, &size, file) =! -1)
    {
      content = NULL;
      var_global.buffer = content;
      counter++;
      if (read_line > 0)
	{
	  exect(content, &stack, counter, file);
	}
      free(content);
    }
  free_dlistint(stack);
  fclose(file);
  return (0);
}
