#include "monty.h"
/**
 * stack_push - prints the top value.
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_push(stack_t **stack, unsigned int count)
	{
		int idx = 0, num;

		if (collect.str == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", count);
			free_s();
			exit(EXIT_FAILURE);
		}
		for (; collect.str[idx] != '\0'; idx++)
		{
			if (!isdigit(collect.str[idx]) && collect.str[idx] != '-')
			{
				fprintf(stderr, "L%d: usage: push integer\n", count);
				free_s();
				exit(EXIT_FAILURE);
			}
		}
		num = atoi(collect.str);
		if (collect.structure == 1)
			add_node(stack, num);
		else
			add_node_at_end(stack, num);
	}

/**
 * stack_queue - sets a queue
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_queue(stack_t **stack, unsigned int count)
	{
		(void) stack;
		(void) count;

		collect.line = 0;
	}

/**
 * stack_pall - prints all values in a stack
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_pall(stack_t **stack, unsigned int count)
	{
		stack_t *temp;
		(void) count;

		temp = *stack;
		if (!temp)
			return;

		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
/**
 * stack_pint - prints the top value of the stack
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_pint(stack_t **stack, unsigned int count)
	{
		(void) count;

		if (*stack == NULL)
		{
			fprintf(stderr, "L%d: can't pint, stack empty\n", count);
			free_s();
			exit(EXIT_FAILURE);
		}
		printf("%d\n", (*stack)->n);
	}

/**
 * stack_nop - does nothing
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_nop(stack_t **stack, unsigned int count)
	{
		(void) stack;
		(void) count;
	}
