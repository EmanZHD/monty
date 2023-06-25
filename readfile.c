#include "monty.h"

/**
 * execute - executes the opcode
 * @stack: head linked list - stack
 * @counter: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: no return
 */

int exect(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
  int i;
  char *op;
  instruction_t instruct[] = {
			      {"push", m_push},
			      {"pall", m_pall},
			      {"pint", m_pint},
			      {"pop", m_pop},
			      {"swap", m_swap},
			      {"add", f_add},
			      {"nop", m_nop},
			      {"sub", f_sub},
			      {"mul", f_mul},
			      {"div", f_div},
			      {"mod", f_mod},
			      {"pchar", f_putchar},
			      {"pstr", f_putstr},
			      {"rotl", m_rotl},
			      {"rotr", m_rotr},
			      {NULL, NULL},
  };

  i = 0;

  op = strtok(content, " \n\t");
  if (op && op[0] == '#')
    return (0);
  var_global.arg = strtok(NULL, " \n\t");
  while (instruct[i].opcode && op)
    {
      if (strcmp(op, instruct[i].opcode) == 0)
	{instruct[i].f(stack, counter);
	  return (0);
	}
      i++;
    }
  if (op && instruct[i].opcode == NULL)
    { fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
      fclose(file);
      free(content);
      free_dlistint(*stack);
      exit(EXIT_FAILURE); }
  return (1);
}

/**
 * isnumber - checks if a string is a number
 * @str: string being passed
 * Return: returns 1 if string is a number, 0 otherwise
 */
int isnumber(char *str)
{
unsigned int i;

if (str == NULL)
return (0);

i = 0;
while (str[i])
{
if (str[0] == '-')
{
i++;
continue;
}
if (!isdigit(str[i]))
return (0);

i++;
}
return (1);
}

/**
 * parse_line - parses a line for an opcode and arguments
 * @line: the line to be parsed
 * @stack: pointer to the head of the stack
 * @line_number: the current line number
 * Return: returns the opcode or null on failure
 */
char *parse_line(char *line, stack_t **stack, unsigned int line_number)
{
char *op_code, *push, *arg;
(void)stack;

push = "push";
op_code = strtok(line, "\n ");
if (op_code == NULL)
return (NULL);

if (strcmp(op_code, push) == 0)
{
arg = strtok(NULL, "\n ");
if (isnumber(arg) == 1 && arg != NULL)
{
var_global.push_arg = atoi(arg);
}
else
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
exit(EXIT_FAILURE);
}
}
return (op_code);
}
