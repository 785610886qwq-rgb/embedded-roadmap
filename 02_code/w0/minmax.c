#include<stdio.h>
int main(void){
    int arr1[10];
for(int i=0;i<10;i++)
{
scanf("%d",&arr1[i]);
}
int max=arr1[0],min=arr1[0];
float sum=arr1[0];
for(int i=1;i<10;i++){
    if(min>arr1[i]) min=arr1[i];
    if(max<arr1[i]) max=arr1[i];
    sum+=arr1[i];
}
printf("max=%d min=%d avg=%.2f\n",max,min,sum/10);
}