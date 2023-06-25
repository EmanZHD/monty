#include "monty.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1;

/**
 * f_push - ...
 * @arg: ...
 * @line_number: ...
 */

void f_push(const char *arg, int line_number)
{
  char *endptr;
  int value = strtol(arg, &endptr, 10);

  if (arg == NULL || *arg == '\0')
      {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }


    if (*endptr != '\0')
      {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (top == STACK_SIZE - 1)
      {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack[++top] = value;
}

/**
 * f_pull - ...
 */

void f_pall()
{
  int i;
  if (top != -1)
      {
        for (i = top; i >= 0; i--)
	  {
            printf("%d\n", stack[i]);
        }
    }
}
