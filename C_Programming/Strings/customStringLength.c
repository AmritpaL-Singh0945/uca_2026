// custom string 

#include <stdio.h>

int my_strlen(const char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main() {
    char str[] = "Hello, World!";
    printf("%d\n", my_strlen(str));
    return 0;
}