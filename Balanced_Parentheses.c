#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if(top == -1) return '#';
    return stack[top--];
}

int main() {
    char exp[100];
    printf("Enter expression: ");
    scanf("%s", exp);

    for(int i = 0; exp[i] != '\0'; i++) {
        if(exp[i] == '(')
            push(exp[i]);
        else if(exp[i] == ')') {
            if(pop() == '#') {
                printf("Not Balanced");
                return 0;
            }
        }
    }

    if(top == -1)
        printf("Balanced Expression");
    else
        printf("Not Balanced");

    return 0;
}