#include <stdio.h>
#include <stdlib.h>   // rand()、srand() 在这里
#include <time.h>  
int main(void){
    srand((unsigned)time(NULL));
 int a= rand() % 100 + 1;;
 int turn=0;
 int guess=0;
 while(guess!=a){
 scanf("%d",&guess);
 if(guess>a) printf("大了\n");
 if (guess<a) printf("小了\n");
 turn++;
 }
 printf("猜了%d次\n",turn);
}