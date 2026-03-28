#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if(rear == MAX - 1)
        printf("Queue Full\n");
    else {
        if(front == -1) front = 0;
        queue[++rear] = x;
    }
}

void dequeue() {
    if(front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        printf("Printed Document: %d\n", queue[front++]);
}

void display() {
    if(front == -1 || front > rear)
        printf("No pending documents\n");
    else {
        for(int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}

int main() {
    enqueue(101);
    enqueue(102);
    display();
    dequeue();
    display();
    return 0;
}