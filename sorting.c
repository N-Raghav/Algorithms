#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void swap(int *xp, int *yp)
{
 int temp = *xp;
 *xp = *yp;
 *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
 int i, j, min_idx;
 
 for (i = 0; i < n-1; i++)
 {
 min_idx = i;
 for (j = i+1; j < n; j++)
 if (arr[j] < arr[min_idx])
 min_idx = j;
 
 swap(&arr[min_idx], &arr[i]);
 }
}
void bubbleSort(int arr[], int n)
{
 int i, j;
 for (i = 0; i < n - 1; i++){
 for (j = 0; j < n - i - 1; j++)
 if (arr[j] > arr[j + 1])
 swap(&arr[j], &arr[j + 1]);
}
}
void insertionSort(int arr[],int n)
{
int i, j, temp;
for(i = 0; i < n; i++){
 temp = arr[i];
 j = i - 1;
 while((temp < arr[j]) && (j >= 0)){
 arr[j+1]=arr[j]; 
j = j - 1;
 }
 arr[j+1]=temp;
}
}
int main(){
 int a[10],b[10],c[10];
 //selection sort
 printf("\n Enter elements : \n");
 for (int i=0;i<10;i++){
 scanf("%d",&a[i]);
 }
 printf("\n Selection Sort\n");
 selectionSort(a,10);
 for(int i=0;i<10;i++){
 printf("%d ",a[i]);
}
//bubble sort
printf("\n Enter elements : \n");
 for (int i =0;i<10;i++){
 scanf("%d",&b[i]);
 }
 printf("\n Bubble Sort\n");
 bubbleSort(b,10);
for(int i=0;i<10;i++){
 printf("%d ",b[i]);
}
//insertion sort
printf("\n Enter elements : \n");
 for (int i =0;i<10;i++){
 scanf("%d",&c[i]);
 }
 printf("\n Insertion Sort\n");
 insertionSort(c,10);
 for(int i=0;i<10;i++){
 printf("%d ",c[i]);
}
}
