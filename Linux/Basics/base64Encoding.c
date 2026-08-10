#include <stdio.h>
#include <string.h>

char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int getBase64Index(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return 0;
}

void encodeBase64(char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i += 3) {
        int a = str[i];
        int b = (i + 1 < len) ? str[i + 1] : 0;
        int c = (i + 2 < len) ? str[i + 2] : 0;

        int x = (a >> 2) & 63;
        int y = ((a & 3) << 4) | (b >> 4);
        int z = ((b & 15) << 2) | (c >> 6);
        int w = c & 63;

        printf("%c%c", table[x], table[y]);

        if (i + 1 < len)
            printf("%c", table[z]);
        else
            printf("=");

        if (i + 2 < len)
            printf("%c", table[w]);
        else
            printf("=");
    }
    printf("\n");
}

void decodeBase64(char str[]) {
    int len = strlen(str);

    for (int i = 0; i < len; i += 4) {
        int val1 = getBase64Index(str[i]);
        int val2 = getBase64Index(str[i + 1]);
        int val3 = getBase64Index(str[i + 2]);
        int val4 = getBase64Index(str[i + 3]);

        int a = (val1 << 2) | (val2 >> 4);
        int b = ((val2 & 15) << 4) | (val3 >> 2);
        int c = ((val3 & 3) << 6) | val4;

        printf("%c", a);

        if (str[i + 2] != '=') {
            printf("%c", b);
        }

        if (str[i + 3] != '=') {
            printf("%c", c);
        }
    }
    printf("\n");
}

int main() {
    printf("--- ENCODING ---\n");
    encodeBase64("Cat");
    encodeBase64("Hello World");
    encodeBase64("A");
    encodeBase64("");
    
    printf("\n--- DECODING ---\n");
    decodeBase64("Q2F0");
    decodeBase64("SGVsbG8gV29ybGQ=");
    decodeBase64("QQ==");
    decodeBase64("");

    return 0;
}