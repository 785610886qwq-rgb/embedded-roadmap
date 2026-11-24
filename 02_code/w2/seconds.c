#include<stdio.h>
int main(void){
int second;
scanf("%d",&second);
int hour=second/3600;
int min=(second-hour*3600)/60;
second=second-hour*3600-min*60;
printf("时：%d,分%d,秒%d",hour,min,second);
}