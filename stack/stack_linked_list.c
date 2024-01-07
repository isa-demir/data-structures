#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *link;

} Stack;

typedef int bool;

void push(int data);
int pop();
int peek();
void isEmpty();

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
