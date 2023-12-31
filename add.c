#include "monty.h"
/**
 * add_node - add a node to list.
 * @stack: pointer to a node.
 * @con_int: line count.
 * Return: a poiter to a node.
 */
	stack_t *add_node(stack_t **stack, const int con_int)
	{
		stack_t *new;

		if (stack == NULL)
			return (NULL);

		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_s();
			exit(EXIT_FAILURE);
		}
		new->n = con_int;
		if (*stack == NULL)
		{
			new->next = *stack;
			new->prev = NULL;
			*stack = new;
			return (*stack);
		}
		(*stack)->prev = new;
		new->next = (*stack);
		new->prev = NULL;
		*stack = new;
		return (*stack);
	}

/**
 * add_node_at_end - adds an end node.
 * @stack: pointer to a node.
 * @con_int: line count.
 * Return: a pointer to a node.
 */
	stack_t *add_node_at_end(stack_t **stack, const int con_int)
	{
		stack_t *new, *temp;

		if (stack == NULL)
			return (NULL);
		new = malloc(sizeof(stack_t));
		if (new == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_s();
			exit(EXIT_FAILURE);
		}
		new->n = con_int;
		if (*stack == NULL)
		{
			new->next = *stack;
			new->prev = NULL;
			*stack = new;
			return (*stack);
		}
		temp = *stack;
		while (temp->next)
			temp = temp->next;
		new->next = temp->next;
		new->prev = temp;
		temp->next = new;
		return (temp->next);
}

/**
 * add_queue - adds a queue
 * @stack: pointer to a node.
 * @con_int: line count.
 * Return: nothing.
 */
	void add_queue(stack_t **stack, int con_int)
	{
		stack_t *new, *temp;

		temp = *stack;
		new = malloc(sizeof(stack_t));
		if (!new)
		{
			printf("Error\n");
			exit(0);
		}
		new->n = con_int;
		new->next = NULL;

		if (temp)
		{
			*stack = new;
			new->prev = NULL;
		}
		temp->next = new;
		new->prev = temp;
	}
