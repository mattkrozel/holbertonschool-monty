#include "monty.h"


int main (int argc, char **argv)
{
	if (argc < 2 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_o(argv[1]);
	final_free();
	return (0);
}


void final_free(void)
{
	stack_t *temp;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}


stack_t *make_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf("Error: malloc failed\n");
		final_free();
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
