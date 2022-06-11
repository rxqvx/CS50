#include <stdio.h>
#include <cs50.h>

int main()
{
    \\Hello world com nomes
        printf("Hello world!\n");
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}