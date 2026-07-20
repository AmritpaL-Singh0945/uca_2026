// sum of even fibonacci
#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    long long a = 1, b = 1, sum = 0;

    while (b <= n) {
        if (b % 2 == 0)
            sum += b;

        long long c = a + b;
        a = b;
        b = c;
    }

    printf("%lld", sum);

    return 0;
}