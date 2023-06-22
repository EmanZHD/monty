#include "monty.h"

/**
 * f_putchar - Prints the character in the top value
 * node of a stack_t linked list.
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void f_putchar(stack_t **stack, unsigned int line_number)
{
int val;

if (stack == NULL || *stack == NULL)
{
fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
free(var_global.buffer);
fclose(var_global.file);
free_dlistint(*stack);
exit(EXIT_FAILURE);
}

val = (*stack)->n;
if (val > 127 || val < 0)
{
fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
free(var_global.buffer);
fclose(var_global.file);
free_dlistint(*stack);
exit(EXIT_FAILURE);
}

putchar(val);
putchar('\n');
}
