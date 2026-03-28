#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = 5;

    push(arr[0]);

    for(int i = 1; i < n; i++) {
        while(top != -1 && arr[i] > stack[top]) {
            printf("%d -> %d\n", pop(), arr[i]);
        }
        push(arr[i]);
    }

    while(top != -1) {
        printf("%d -> -1\n", pop());
    }

    return 0;
}
