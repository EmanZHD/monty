#include "monty.h"

/**
 * m_pop - remove element a list
 *@stack: pointer to first node
 *@line_number: integer
 *Return: void
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
  stack_t *nodo = *stack;

  if (stack == NULL || *stack == NULL)
    {
      fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
      exit(EXIT_FAILURE);
    }
  *stack = nodo->next;
  if (*stack != NULL)
    (*stack)->prev = NULL;

  free(nodo);
}

/**
 * free_dlistint - free a list
 * @head: pointer to first node
 *
 */
void free_dlistint(stack_t *head)
{
  stack_t *tmp;

  while (head != NULL)
    {
      tmp = head->next;
      free(head);
      head = tmp;
    }
}
