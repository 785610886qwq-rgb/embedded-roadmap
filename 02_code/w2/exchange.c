#include <stdio.h>

int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("before: a=%d b=%d\n", a, b);

    int t = a; a = b; b = t;
    printf("temp:   a=%d b=%d\n", a, b);

    a = a + b; b = a - b; a = a - b;
    printf("arith:  a=%d b=%d\n", a, b);

    a ^= b; b ^= a; a ^= b;
    printf("xor:    a=%d b=%d\n", a, b);
    return 0;
}