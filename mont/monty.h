#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/*Definitions*/
extern int push_arg;

/* STRUCT FUNCTIONS */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
  int n;
  struct stack_s *prev;
  struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
  char *opcode;
  void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_variable - opcoode and its function
 * @file: the opcode
 * @push_arg: function to handle the opcode
 * @buffer: pointer to
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct global_variable
{
  FILE *file;
  int push_arg;
  char *buffer;
} global_var;

extern global_var var_global;

/*****************FUNCTIONS*******************/

/* RUN FUNCTION */
void run_cmd(char *filename, stack_t **stack);
char *parse_line(char *line, stack_t **stack, unsigned int line_number);
typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
instruct_func get_op_func(char *str);

/* MONTY FUNCTIONS */
void m_pall(stack_t **stack, unsigned int line_number);
void m_push(stack_t **stack, unsigned int line_number);
void m_pint(stack_t **stack, unsigned int line_number);
void m_pop(stack_t **stack, unsigned int line_number);
void m_swap(stack_t **stack, unsigned int line_number);
void m_nop(stack_t **stack, unsigned int line_number);
void m_rotl(stack_t **stack, unsigned int line_number);
void m_rotr(stack_t **stack, unsigned int line_number);

/* ASCCI STRING */
void f_putchar(stack_t **stack, unsigned int line_number);
void f_putstr(stack_t **stack, unsigned int line_number);

/* MATHS FUNCTIONS */
void f_sub(stack_t **stack, unsigned int line_number);
void f_add(stack_t **stack, unsigned int line_number);
void f_mul(stack_t **stack, unsigned int line_number);
void f_div(stack_t **stack, unsigned int line_number);
void f_mod(stack_t **stack, unsigned int line_number);

/* WORKABILITY FUNCTIONS */
void free_dlistint(stack_t *head);
void _free(stack_t **stack);
void _free_(stack_t **stack);
int _isalpha(int c);


#endif /******MONTY_H********/
