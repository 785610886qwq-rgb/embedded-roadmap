#include <stdio.h>

void print_bin(unsigned int n)
{
    for (int i = 31; i >= 0; i--) {
        putchar(((n >> i) & 1) ? '1' : '0');
        if (i % 8 == 0 && i != 0)
            putchar(' ');          // 每 8 位空一格，方便看字节
    }
    putchar('\n');
}

int main(void)
{
    unsigned int n;
    scanf("%u", &n);
    print_bin(n);
    printf("置位 bit3: ");  print_bin(n | (1u << 3));
printf("清位 bit3: ");  print_bin(n & ~(1u << 3));
printf("取反:      ");  print_bin(~n);
printf("左移 2:    ");  print_bin(n << 2);
    return 0;
}