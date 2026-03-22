#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    int n = strlen(str);

    for(int i = 0; i < n; i++)
        push(str[i]);

    printf("Reversed string: ");
    for(int i = 0; i < n; i++)
        printf("%c", pop());

    return 0;
}