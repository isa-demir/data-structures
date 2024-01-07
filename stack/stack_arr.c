#include <stdio.h>
#include <stdlib.h>
#define MAX 5

typedef int bool;
enum boolean
{
    false,
    true
};

int top = -1;
int stack[MAX];

void push(int data);
int pop();
int top_value();
bool isEmpty();
void printStack();

int main(int argc, char const *argv[])
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);
    push(70);
    printStack();

    printf("popped data is : %d\n", pop());
    printf("popped data is : %d\n", pop());
    push(100);
    printStack();

    return 0;
}

void push(int data)
{
    if (MAX - 1 == top)
    {
        printf("Stack overflow!\n");
        return;
    }

    stack[++top] = data;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack underflow!\n");
        return;
    }
    return stack[top--];
}

bool isEmpty()
{
    return top == -1 ? true : false;
}

int top_value()
{
    if (top != -1)
        return stack[top];

    printf("Stack is empty!");
    return -1;
}

void printStack()
{
    if (!isEmpty())
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack is empty!\n");
    }
}