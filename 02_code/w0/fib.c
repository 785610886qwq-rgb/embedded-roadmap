#include<stdio.h>
int arr[20];
int fib(int i){
    if(i>2){
    int number=fib(i-1)+fib(i-2);
    arr[i-1]=number;
    return number;
    }else 
    arr[i-1]=1;
    return 1;
}
int main(void){
    fib(20);                        // 算完 20 项，结果存进 arr
    for(int i=0;i<20;i++){          // 从 arr[0] 正序打印第 1~20 项
        printf("%d ",arr[i]);
        if((i+1)%5==0) printf("\n"); // 每 5 个换行
    }
    return 0;
}