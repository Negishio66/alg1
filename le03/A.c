#include <stdio.h>

int stack[101];

int top = 0;

void push(int x) {
    stack[top] = x;
    top++;
}

int pop() {
    top--;
    return stack[top];
}

int main() {
    int a, b;
    char s[100];

    while (scanf("%s", s) != EOF) {
        if (s[0] == '+' && s[1] == '\0') {
            b = pop();
            a = pop();
            push(a + b);
        }
        else if (s[0] == '-' && s[1] == '\0') {
            b = pop();
            a = pop();
            push(a - b);
        }
        else if (s[0] == '*' && s[1] == '\0') {
            b = pop();
            a = pop();
            push(a * b);
        }
        else {
            int val = atoi(s);
            push(val);
        }
    }
    printf("%d\n", pop());

    return 0;
}