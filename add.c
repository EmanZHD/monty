#include "monty.h"

/**
 * f_add - Adds the top two values of a stack_t linked list.
 * @stack: pointer to lists for monty stack
 * @line_number: number of line opcode occurs on
 */

void f_add(stack_t **stack, unsigned int line_number)
{
  stack_t *tmp = *stack;
  int sum = 0, i = 0;

  if (tmp == NULL)
    {
      fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }

  while (tmp)
    {
      tmp = tmp->next;
      i++;
    }

  if (stack == NULL || (*stack)->next == NULL || i <= 1)
    {
      fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
      exit(EXIT_FAILURE);
    }
  sum = (*stack)->next->n + (*stack)->n;
  m_pop(stack, line_number);

  (*stack)->n = sum;
}

