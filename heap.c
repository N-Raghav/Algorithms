#include <stdio.h>

void swap(int arr[], int a, int b){
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void property(int arr[], int end, int i){

    if(end != 1){
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left < end && arr[left] < arr[smallest]) smallest = left;
        if(right < end && arr[right] < arr[smallest]) smallest = right;
        if(smallest != i){
            swap(arr,i,smallest);
            property(arr, end, smallest);
        }
    }

    return;
}

int insertion(int ele, int arr[], int end){

    arr[end] = ele;
    end++;
    if(end != 1){
        for (int i = end/2 - 1; i >= 0; i--){
            property(arr, end, i);
        }
        
    }

    return end;
}

int deletion(int arr[], int end){

    swap(arr, end-1, 0);
    end--;
    for(int i = end/2 - 1; i >= 0; i--){
        property(arr, end, i);
    }

    return end;
}

int sort(int arr[], int end){

    while(end != 0){
        printf("%d\t", arr[0]);
        end = deletion(arr, end);
    }
    printf("\n");

    return end;
}

void display(int arr[], int end){

    for(int i = 0; i < end; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n");

    return;
}

int main(){

    int heap[20] = {0};
    int end = 0;

    while(1){

        int choice = 0;
        printf("Enter choice\n\t1.Insertion\n\t2.Deletion\n\t3.Display\n\t4.SortDisplay\n\tAny other key to Exit...\n");
        scanf("%d",&choice);

        if(choice == 1){
            int element;
            printf("Enter element : ");
            scanf("%d",&element);
            end = insertion(element, heap, end);
        }
        else if(choice == 2){
            end = deletion(heap, end);
        }
        else if(choice == 3){
            display(heap, end);
        }
        else if(choice == 4){
            end = sort(heap, end);
        }
        else{
            break;
        }

    }

    return 0;
}