#include <stdio.h>


int main(){
int arr[30],n,sum=0;
float avg;
printf("enter the size of the array.");
scanf("%d",&n);
printf("enter the numbers: ");
for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
for(int i=0;i<n;i++){
    sum=sum+arr[i];
}
avg=sum/n;
printf("the avgerage is: %f",avg);

}
