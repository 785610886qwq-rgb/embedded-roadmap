#include<stdio.h>
int main(void){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a+b=%d,a-b=%d,a*b=%d,",a+b,a-b,a*b);
    if(b==0)printf("a/b: 除数为 0，无法计算\n");
    else printf("a/b=%d,a%%b=%d",a/b,a%b);
    
}