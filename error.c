#include "monty.h"
void handle_error(FILE *file, char *lineptr, stack_t **stack)
{
    fclose(collection.file);
    free(collection.data);
    free_s(*stack);
    exit(EXIT_FAILURE);
}