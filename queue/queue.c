#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear = -1, front = -1;
int queue[MAX];

void enqueue(int x)
{
    if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        queue[rear] = x;
    }
    else if (MAX - 1 == rear)
        printf("Que is full!\n");
    else
        queue[++rear] = x;
}

void dequeue()
{
    if (front == -1 && rear == -1)
        printf("Que is already empty!\n");
    else if (front == rear)
    {
        front = -1;
        rear = -1;
        printf("Que is empty now!\n");
    }
    else
        front++;
}

void printLog()
{
    printf("\nFront is : %d\nRear is : %d\n", front, rear);
}

void printQueue(int isLog)
{
    if (isLog)
        printLog();
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    puts("");
}

int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(60);
    printQueue(1);

    dequeue();
    printQueue(1);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printQueue(1);

    return 0;
}
