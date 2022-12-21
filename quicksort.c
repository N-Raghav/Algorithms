#include<stdio.h>

int partition(int *arr,int lb,int ub){
	int start=lb;
	int end=ub;
	int pivot=arr[lb];
	int temp;
	while(start<end){
		while(arr[start]<=pivot){
			start++;
		}
		while(arr[end]>pivot){
			end--;
		}
		if(start<end){
			temp=arr[start];
			arr[start]=arr[end]; 
			arr[end]=temp;
		}
	}
	temp=arr[lb];
	arr[lb]=arr[end];
	arr[end]=temp;
	return end;
}

void quicksort(int *arr,int lb,int ub){
	int loc;
	if(lb<ub){
		loc=partition(arr,lb,ub);
		quicksort(arr,lb,loc-1);
		quicksort(arr,loc+1,ub);
	}
}

void printarray(int *arr,int n){
	int i;
	printf("\nSorted list is:");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
}

int main(){
	int i,n;
	printf("\nEnter the no. of elements");
	scanf("%d",&n);
	int arr[n];
	printf("\nEnter the no. of elements");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,n);
	printarray(arr,n);
	return 0;
}