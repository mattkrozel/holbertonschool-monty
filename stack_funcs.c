#include "monty.h"
/**
 * stack_add - adds node to stack
 * @n_node: pointer to new node
 * @ln: line number of opcode
 */
void stack_add(stack_t **n_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	temp = head;
	head = *n_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * stack_print - adds node to stack
 * @stack: pointer to top of stack
 * @ln_num: line number of opcode
 */
void stack_print(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;

	(void) ln_num;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * add_queue - adds node to queue
 * @n_node: pointer to node
 * @ln:  line number of opcode
 */
void add_queue(stack_t **n_node, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (n_node == NULL || *n_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *n_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *n_node;
	(*n_node)->prev = temp;
}

/**
 * top_print - prints top pof stack
 * @stack: pointer to top of stack
 * @line_num: line number of opcode
 */
void top_print(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		final_free();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * top_pop - removes node from top of stack
 * @stack: start of stack
 * @ln_num: line number
 */
void top_pop(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_num);
		final_free();
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
