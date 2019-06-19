
/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#ifdef __APPLE__
#include <editline/readline.h>
#else
#include <editline/readline.h>
#include <editline/history.h>
#endif
#endif

#define bufSize 2048

static char* version = "Lispy version 0.0.0.1";
static char* exits = "Press Ctrl+C to quit";

int echo()
{
    puts(version);
    puts(exits);

    while (1)
    {
        char* input = readline("lispy>");
        add_history(input);

        printf("%s\n", input);

        free(input);
    }

    return 0;
}
