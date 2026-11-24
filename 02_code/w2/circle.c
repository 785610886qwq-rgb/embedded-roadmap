#include<stdio.h>
const float  PI = 3.14159;
int main(void){
 float r;
 scanf("%f",&r);
 printf("面积=%.2f,周长=%.2f",r*PI*r,2*PI*r);
}