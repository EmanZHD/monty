#include "monty.h"

/**
 * m_push - Pushes a value to a stack_t linked list.
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void m_push(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
stack_t *top;
(void)line_number;

top = malloc(sizeof(stack_t));
if (top == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

top->n = var_global.push_arg;
top->next = *stack;
top->prev = NULL;
if (*stack != NULL)
(*stack)->prev = top;
*stack = top;
}

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

/**
 * m_pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
stack_t *runner;

runner = *stack;
if (runner == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
exit(EXIT_FAILURE);
}
printf("%d\n", runner->n);
}
