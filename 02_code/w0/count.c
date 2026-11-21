#include <stdio.h>    // printf、fgets、stdin
#include <ctype.h>    // isalpha、isdigit、isspace
#include <string.h>   // strcspn

int main(void)
{
    /* 1. 准备缓冲区：在栈上要 200 字节，用来装读到的一行 */
    char buf[200];

    /* 2. 读一行：最多读 sizeof buf - 1 个字符，末尾自动补 '\0'
          读失败（比如按了 Ctrl+D）返回 NULL */
    if (fgets(buf, sizeof buf, stdin) == NULL)
        return 1;

    /* 3. 去掉行尾换行符：strcspn 返回 '\n' 第一次出现的下标
          把它改成 '\0'，字符串在这里结束；否则 '\n' 会被算进"空格" */
    buf[strcspn(buf, "\n")] = '\0';

    /* 4. 四个计数器，初值都是 0 */
    int letters = 0, digits = 0, spaces = 0, others = 0;

    /* 5. 逐字符扫描，直到遇到字符串结束符 '\0' */
    for (int i = 0; buf[i] != '\0'; i++) {
        unsigned char c = buf[i];   // 转 unsigned char：isalpha 等传负值行为未定义

        if (isalpha(c))      letters++;   // 字母
        else if (isdigit(c)) digits++;    // 数字
        else if (isspace(c)) spaces++;    // 空白字符（空格、\t 等）
        else                 others++;    // 其他（标点符号等）
    }

    /* 6. 输出统计结果 */
    printf("字母=%d 数字=%d 空格=%d 其他=%d\n", letters, digits, spaces, others);
    return 0;
}
