#include <stdio.h>

void reverse_string(char *str) {
    int len = 0;
    while (str[len] != '\0')
        len++;

    int i = 0, j = len - 1;
    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {
    char str[] = "Data Structures";
    reverse_string(str);
    printf("%s\n", str);
    return 0;
}