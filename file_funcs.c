#include "monty.h"

/**
 * file_o - opens file
 * @file_n: file name
 */
void file_o(char *file_n)
{
	int check;
	FILE *fd;

	if (file_n == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_n);
		final_free();
		exit(EXIT_FAILURE);
	}
	check = access(file_n, R_OK);
	if (check == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_n);
		final_free();
		exit(EXIT_FAILURE);
	}
	fd = fopen(file_n, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_n);
		final_free();
		exit(EXIT_FAILURE);
	}
	file_r(fd);
	fclose(fd);
}
/**
 * file_r - reads file
 * @fd: pointer to file descriptor
 */
void file_r(FILE *fd)
{
	int file_l, lay;
	char *linesp;
	size_t n;

	linesp = NULL;
	n = 0;
	lay = 0;

	for (file_l = 1; getline(&linesp, &n, fd) != EOF; file_l++)
		lay = tokenator(linesp, file_l, lay);
	free(linesp);
}
/**
 * tokenator - tokenizes & determinnes funcs to call
 * @str: string
 * @line_num: line number
 * @lay: format specifier
 * Return: function to call
 */
int tokenator(char *str, int line_num, int lay)
{
	const char *delim;
	char *opcode;
	char *val;

	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		final_free();
		exit(EXIT_FAILURE);
	}
	delim = "\n ";
	opcode = strtok(str, delim);
	if (opcode == NULL)
		return (lay);
	val = strtok(NULL, delim);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	else if (strcmp(opcode, "stack") == 0)
		return (0);
	find_f(opcode, val, line_num, lay);
	return (lay);
}
/**
 * find_f - finds functions
 * @opcode: opcodei
 * @val: value for operation
 * @opline: line number for opcode
 * @lay: format specifier
 */
void find_f(char *opcode, char *val, int opline, int lay)
{
	int i, flag;

	instruction_t func_list[] = {
		{"push", stack_add},
		{"pall", stack_print},
		{"pint", top_print},
		{"pop", top_pop},
		{"swap", node_swap},
		{"add", node_add},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			func_call(func_list[i].f, opcode, val, opline, lay);
			flag = 0;
		}
	}
	if (flag == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", opline, opcode);
		final_free();
		exit(EXIT_FAILURE);
	}
}
/**
 * func_call - calls necessary function
 * @f: pointer to func being called
 * @op: string representing opcode
 * @strval: string representing numeric value
 * @ln_num: line number
 * @lay: format specifier
 */
void func_call(op_func f, char *op, char *strval, int ln_num, int lay)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (strval != NULL && strval[0] == '-')
		{
			strval++;
			flag = -1;
		}
		if (strval == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln_num);
			final_free();
			exit(EXIT_FAILURE);
		}
		for (i = 0; strval[i] != '\0'; i++)
		{
			if (isdigit(strval[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln_num);
				final_free();
				exit(EXIT_FAILURE);
			}
		}
		node = make_node(atoi(strval) * flag);
		if (lay == 0)
			f(&node, ln_num);
		if (lay == 1)
			add_queue(&node, ln_num);
	}
	else
		f(&head, ln_num);
}


