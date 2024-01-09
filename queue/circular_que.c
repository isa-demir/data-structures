#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int rear = -1, front = -1;
int queue[MAX];

void enqueue(int x)
{
    if (front == -1 && rear == -1)
    {
        front++;
        queue[++rear] = x;
    }
    else if ((rear + 1) % MAX == front)
        printf("Que is full!\n");
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1)
        printf("Que is empty!\n");
    else if (front == rear)
    {
        printf("Que is empty now!\n");
        front = -1;
        rear = -1;
    }
    else
    {
        printf("Dequed element is : %d\n", queue[front]);
        front = (front + 1) % MAX;
    }
}

void printLog()
{
    printf("\nFront is : %d\nRear is : %d\n", front, rear);
}

void printQueue(int isLog)
{
    if (isLog)
        printLog();
    for (int i = front; i != rear; i = (i + 1) % MAX)
        printf("%d ", queue[i]);
    printf("%d", queue[rear]);
    puts("");
}

int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    printQueue(1);

    dequeue();
    printQueue(1);
    enqueue(60);
    printQueue(1);
    dequeue();
    dequeue();
    enqueue(70);
    enqueue(80);
    enqueue(90);
    enqueue(100);

    printQueue(1);

    return 0;
}
