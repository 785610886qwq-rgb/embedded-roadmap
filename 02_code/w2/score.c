#include<stdio.h>
int main(void){
    float a,b,c;
    scanf("%f",&a);
  scanf("%f",&b);
  scanf("%f",&c);
    float avg=(a+b+c)/3;
    printf("平均分（保留两位小数):%.2f,平均分阶段整数:%d",avg,(int)avg);
}