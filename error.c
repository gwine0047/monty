#include "monty.h"
void handle_error(FILE *file, char *lineptr, stack_t **stack)
{
    fclose(file);
    free(lineptr);
    free_s(*stack);
    exit(EXIT_FAILURE);
}