#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int top = 1;
int stack[MAX];

void push(int x)
{
    if (MAX - 1 == top)
    {
        printf("Stack overflow!\n");
        return;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
