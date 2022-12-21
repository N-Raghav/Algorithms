#include<stdio.h>
void main(){
    int n ;
    printf("Enter size of array: ") ;
    scanf("%d",&n) ;
    int arr[n] ;
    //input array from user
    for(int i=0;i<n;i++){
        printf("Enter element: ") ;
        scanf("%d",&arr[i]) ;
    }
    //linear search
    int ele,flag=0 ;
    printf("Enter element to search: ");
    scanf("%d",&ele) ;
    for(int i=0;i<n;i++){
        if(arr[i]==ele){
            flag=1 ;
        }
        else{
            flag=0 ;
        }
    }
    if(flag==1){
        printf("Element found!") ;
    }
    else if (flag==0)
    {
        printf("Element not found! ") ;
    }

}