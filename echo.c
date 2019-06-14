#include "stdio.h"

#define bufSize 2048

static char* version = "Lispy version 0.0.0.1";
static char* exit = "Press Ctrl+C to quit";
static char input[bufSize];

int main(int argc, char const *argv[])
{
    puts(version);
    puts(exit);

    while (1)
    {
        fputs("lispy>", stdout);
        fgets(input, bufSize, stdin);
        printf("%s", input);
    }

    return 0;
}
