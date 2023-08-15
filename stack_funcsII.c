#include "monty.h"

/**
 * node_swap - swaps top two elements of stack
 * @stack: top of stack
 * @ln_num: line number of opcode
 */
void node_swap(stack_t **stack, unsigned int ln_num)
{
	stack_t *temp;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap an empty stack\n", ln_num);
		final_free();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

void node_add(stack_t **stack, unsigned int ln_num)
{
	int total;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, " L%d: can't add, stack too short\n", ln_num);
		final_free();
		exit(EXIT_FAILURE);
	}

	(*stack) = (*stack)->next;
	total = (*stack)->prev->n + (*stack)->n;
	(*stack)->n = total;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
/**
 * nop - does nothing
 * @stack: start of stack
 * @ln_num: line number of opcode
 */
void nop(stack_t **stack, unsigned int ln_num)
{
	(void)stack;
	(void)ln_num;
}
