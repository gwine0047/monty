#include "monty.h"
/**
 * call - matches a command with a function.
 * @token: character token.
 * Return: nothing.
 */
	void(*call(char *token))(stack_t **stack, unsigned int line_number)
	{
		int idx = 0;
		instruction_t match[] = {
		{"push", stack_push}, {"pop", stack_pop}, {"pall", stack_pall},
		{"queue", stack_queue}, {"pint", stack_pint}, {"rotr", stack_rotr},
		{"rotl", stack_rotl}, {"swap", stack_swap}, {"add", stack_add},
		{"sub", stack_sub}, {"div", stack_div}, {"stack", _stack},
		{"mod", stack_mod}, {"pchar", stack_pchar}, {"pstr", stack_pstr},
		{"nop", stack_nop},
		{NULL, NULL}
	};

	while (match[idx].opcode)
	{
		if (strcmp(match[idx].opcode, token) == 0)
			break;
		idx++;
	}
	return (match[idx].f);
	}
/**
 * stack_pchar - prints a node's char.
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_pchar(stack_t **stack, unsigned int count)
	{
		if (stack == NULL || *stack == NULL)
		{
			fprintf(stderr, "L%d: can't pchar, stack empty\n", count);
			free_s();
			exit(EXIT_FAILURE);
		}
		if ((*stack)->n < 0 || (*stack)->n >= 128)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", count);
			free_s();
			exit(EXIT_FAILURE);
		}
		printf("%c\n", (*stack)->n);
	}

/**
 * stack_pstr - prints a node's int.
 * @stack: pointer to a node.
 * @count: line count.
 * Return: nothing.
 */
	void stack_pstr(stack_t **stack, unsigned int count)
	{
		stack_t *temp;
		(void) count;

		temp = *stack;
		while (temp && temp->n > 0 && temp->n < 128)
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
		printf("\n");
	}
