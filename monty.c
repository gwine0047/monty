#include "monty.h"
collect collection = {NULL, NULL, NULL, 0};

/**
*main - interpreter for a monty code.
*@ac: argument count
*@av: commandline argument
*Return: if successful, 0.
*/

int main(int ac, char *av[])
{
    stack_t *stack = NULL;
    FILE *file;
    char *lineptr = NULL;
    ssize_t line;
    unsigned int count = 0;
    size_t n = 0;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(av[1], "r");
    collection.file = file;
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    do {
        line = getline(&lineptr, &n, file);
        collection.data = lineptr;
        count++;
        if (line > 0)
        {
            call(file, lineptr, count, &stack);
        }

        free(lineptr);
        lineptr = NULL;
    } while (line > 0);

    fclose(file);
    free_s(stack);
    return (0);
}