#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int binsearch(int arr[],int low,int high,int x){
    int mid=(low+high)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if(arr[mid]>x){
        return binsearch(arr,low,mid-1,x);
    }
    else{
return binsearch(arr,mid+1,high,x);
    }
}
int main(){
    int c,a[10],b,mid,low,high;
    printf("\n Enter elements in sorted format : \n");
    for (int i =0;i<10;i++){
        printf("Enter element:");    
        scanf("%d",&a[i]);
 }
     for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n Enter element to search : ");
    scanf(" %d",&b);
    low=0,high=9;
    c=binsearch(a,low,high,b) ;
    printf("\n %d is found in index %d \n",a[c],c);
}