#include "monty.h"

colt collect;

void initialize(FILE *file)
{
        collect.file = file;
        collect.str = NULL;
        collect.structure = 1;
        collect.point = NULL;
        collect.line = 1;
        collect.store = NULL;
}

/**
*main - interpreter for a monty code.
*@ac: argument count
*@av: commandline argument
*Return: if successful, 0.
*/

int main(int ac, char *av[])
{
    char *strings[2] = {NULL, NULL};
    void (*m)(stack_t **stack, unsigned int line_number);
    FILE *file;
    ssize_t line = 0;
    size_t n = 512;

    if (ac != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(av[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", av[1]);
        exit(EXIT_FAILURE);
    }
    initialize(file);
    line = getline(&collect.store, &n, file);
    
    while (line != -1)
    {
        strings[0] = strtok(collect.store, " \t\n");
        if (strings[0][0] != '#' && strings[0])
        {
            m = call(strings[0]);
            if (m == NULL)
            {
                fprintf(stderr, "L%d: unknwon instruction %s\n", collect.line, strings[0]);
                free_s();
                exit(EXIT_FAILURE);
            }
            collect.str = strtok(NULL, " \t\n");
            m(&collect.point, collect.line);
        }
        line = getline(&collect.store, &n, file);
        collect.line++;
    }
    free_s();
    return (0);
}

