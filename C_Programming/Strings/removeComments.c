#include <stdio.h>

void remove_comments(char *str) {
    int in_block = 0, in_line = 0, in_str = 0, in_char = 0;
    int i = 0, j = 0;

    while (str[i] != '\0') {
        if (in_block) {
            if (str[i] == '*' && str[i + 1] == '/') {
                in_block = 0;
                i++;
            }
        } else if (in_line) {
            if (str[i] == '\n') {
                in_line = 0;
                str[j++] = str[i];
            }
        } else if (in_str) {
            str[j++] = str[i];
            if (str[i] == '\\' && str[i + 1] != '\0') {
                i++;
                str[j++] = str[i];
            } else if (str[i] == '"') {
                in_str = 0;
            }
        } else if (in_char) {
            str[j++] = str[i];
            if (str[i] == '\\' && str[i + 1] != '\0') {
                i++;
                str[j++] = str[i];
            } else if (str[i] == '\'') {
                in_char = 0;
            }
        } else {
            if (str[i] == '/' && str[i + 1] == '*') {
                in_block = 1;
                i++;
            } else if (str[i] == '/' && str[i + 1] == '/') {
                in_line = 1;
                i++;
            } else {
                if (str[i] == '"') in_str = 1;
                else if (str[i] == '\'') in_char = 1;
                str[j++] = str[i];
            }
        }
        i++;
    }
    str[j] = '\0';
}

int main() {
    char buffer[10000];
    int c, len = 0;

    while ((c = getchar()) != EOF && len < 9999) {
        buffer[len++] = c;
    }
    buffer[len] = '\0';

    remove_comments(buffer);
    printf("%s", buffer);

    return 0;
}