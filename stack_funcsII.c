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
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln_num);
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
