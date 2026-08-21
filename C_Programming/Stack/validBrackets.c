#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatchingPair(char char1, char char2) {
    if (char1 == '(' && char2 == ')') return true;
    if (char1 == '{' && char2 == '}') return true;
    if (char1 == '[' && char2 == ']') return true;
    return false;
}

bool areParenthesesBalanced(char exp[]) {
    int i = 0;
    // we can increase the size or make it dynamic with time (this is just for concept)
    char stack[50]; 
    int top = -1;

    while (exp[i]) {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') {
            stack[++top] = exp[i];
        } 
        else if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (top == -1) {
                return false;
            } 
            else if (!isMatchingPair(stack[top], exp[i])) {
                return false;
            } 
            else {
                top--;
            }
        }
        i++;
    }
    
    return (top == -1);
}

int main() {
    char exp[50];
    
    if (scanf("%s", exp) != EOF) {
        if (areParenthesesBalanced(exp))
            printf("true\n");
        else
            printf("false\n");
    }
    
    return 0;
}