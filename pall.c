#include "monty.h"

/**
 * m_pall - Prints the values of a stack_t linked list.
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void m_pall(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *runner;

runner = *stack;
while (runner != NULL)
{
printf("%d\n", runner->n);
runner = runner->next;
}
}
