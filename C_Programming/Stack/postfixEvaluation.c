#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[50];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[100];
    
    if (fgets(exp, sizeof(exp), stdin) != NULL) {
        char *token = strtok(exp, " \n");
        
        while (token != NULL) {
            if (token[0] == '+' && token[1] == '\0') {
                int val1 = pop();
                int val2 = pop();
                push(val2 + val1);
            } 
            else if (token[0] == '-' && token[1] == '\0') {
                int val1 = pop();
                int val2 = pop();
                push(val2 - val1);
            } 
            else if (token[0] == '*' && token[1] == '\0') {
                int val1 = pop();
                int val2 = pop();
                push(val2 * val1);
            } 
            else if (token[0] == '/' && token[1] == '\0') {
                int val1 = pop();
                int val2 = pop();
                push(val2 / val1);
            } 
            else {
                push(atoi(token));
            }
            token = strtok(NULL, " \n");
        }
        
        printf("%d\n", stack[top]);
    }
    
    return 0;
}