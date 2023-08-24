#include "monty.h"
/**
 * free_s - frees a couple
 * Return: nothing.
 */

	void free_s(void)
	{
		free_list(collect.point);
		free(collect.store);
		fclose(collect.file);
	}

/**
 * free_list - frees a list.
 * @stack: pointer to a node pointer.
 * Return: nothing.
 */

	void free_list(stack_t *stack)
	{
		stack_t *temp;

		while ((temp = stack) != NULL)
		{
			stack = stack->next;
			free(temp);
		}
	}
