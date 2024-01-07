#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int data;
    struct stack *link;

} Stack;

Stack *root = NULL;

typedef int bool;
enum boolean
{
    false,
    true
};

void push(int data);
int pop();
int peek();
bool isEmpty();
void print_stack();

int main(int argc, char const *argv[])
{
    push(10);
    push(20);
    push(30);
    push(40);
    print_stack();

    printf("popped value is : %d\n", pop());
    printf("popped value is : %d\n", pop());

    push(250);
    print_stack();

    printf("data of top : %d\n", peek());

    printf("popped value is : %d\n", pop());
    printf("popped value is : %d\n", pop());
    printf("popped value is : %d\n", pop());
    printf("popped value is : %d\n", pop());

    print_stack();
    return 0;
}

void push(int data)
{
    Stack *temp = malloc(sizeof(Stack));
    temp->data = data;
    temp->link = root;
    root = temp;
}
int pop()
{
    if (!isEmpty())
    {
        Stack *temp = root;
        int popped = root->data;
        root = root->link;
        free(temp);
        temp = NULL;
        return popped;
    }
    else
    {
        printf("Stack underflow!\n");
        return -1;
    }
}
int peek()
{
    return isEmpty() ? -1 : root->data;
}
bool isEmpty()
{
    return root == NULL ? true : false;
}
void print_stack()
{
    if (!isEmpty())
    {
        printf("Printing stack...\n");
        Stack *temp = root;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
    else
        printf("Stack is empty!\n");
}
