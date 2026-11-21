#include<stdio.h>
int main(void){
    float a;
    float b;
    scanf("%f",&a);
    a=a*9/5+32;
    printf("%.2f ",a);
    scanf("%f",&b);
    b=(b-32)*5/9;
    printf("%.2f",b);

}