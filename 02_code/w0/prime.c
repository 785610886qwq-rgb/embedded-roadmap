#include<stdio.h>
int main(void){
    int a;
    int flag=0;
    scanf("%d",&a);
    if (a < 2) {
    printf("%d不是素数\n", a);
    return 0;
 }
for (int i = 2; i < a; i++) {
    if (a % i == 0) { flag = 1; break; }
}
      if(flag ==0) printf("%d是素数\n",a);
    else printf("%d不是素数\n",a);
     for (int i = 2; i <= 100; i++) {
    int k = 0;
    for (int j = 2; j * j <= i; j++)
        if (i % j == 0) { k = 1; break; }
    if (k == 0) printf("%d ", i);
}
}