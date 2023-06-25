#include "monty.h"

#define STACK_SIZE 100

int stack[STACK_SIZE];
int top = -1; // Initialize top of stack

/**
 * push_op - ...
 * @arg: ...
 * @line_number: ...
 */

void push_op(const char *arg, int line_number) {
    if (arg == NULL || *arg == '\0') {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    char *endptr;
    int value = strtol(arg, &endptr, 10); // Convert argument to integer

    if (*endptr != '\0') {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    if (top == STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }

    stack[++top] = value; // Push the integer onto the stack
}

/**
 * pall_op - ...
 */

void pall_op() {
    if (top != -1) {
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}
