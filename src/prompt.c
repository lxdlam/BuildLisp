#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <string.h>
#define BUFFER_SIZE 2048

static char buffer[BUFFER_SIZE];

/* Fake readline function */
char *readline(char *prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, BUFFER_SIZE, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char *unused) {}

#else
#include <editline/readline.h>
#include <histedit.h>
#endif

int main(int argc, char **argv)
{
    puts("Ramen's Lisp Version 0.0.0.0.1");
    puts("Press Ctrl+C to Exit\n");

    while (1)
    {
        char *input = readline("RLisp> ");
        add_history(input);

        printf("No you're a %s\n", input);
        free(input);
    }

    puts("See you!");

    return 0;
}