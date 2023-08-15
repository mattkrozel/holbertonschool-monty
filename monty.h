#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
int main(int argc, char **argv);
stack_t *make_node(int n);
void final_free(void);
void file_o(char *file_n);
void file_r(FILE *fd);
int tokenator(char *str, int line_num, int lay);
void find_f(char *opcode, char *val, int opline, int lay);
void func_call(op_func f, char *op, char *strval, int ln_num, int lay);
void stack_add(stack_t **n_node, __attribute__((unused))unsigned int ln);
void stack_print(stack_t **stack, unsigned int ln_num);
void add_queue(stack_t **n_node, __attribute__((unused))unsigned int ln);

#endif
