#include<stdio.h>
int main(void){
    int number_for=0,number_while=0;
    for(int i=1;i<=100;i++){
       number_for +=i;
    }
    int j=1;
    while(j<=100){
     number_while+=j;
     j++;
    }
    printf ("for=%d while=%d",number_for,number_while);
}