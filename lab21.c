//implementation of quick sort
#include<stdio.h>
void displayArr(int arr[], int size){
    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void Swap(int *x,int *y){
    int temp = *x;
    *x = *y;
    *y =temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i=low;
    for(int j= low; j<high; j++){
        if(arr[j] < pivot){
            Swap(&arr[i], &arr[j]);
            i++;
        }
    }
    Swap(&arr[i], &arr[high]);
    return i;
}
void quickSort(int arr[],int low, int high){
    if(low<high){
    int p = partition(arr, low, high);
    quickSort(arr, low, p -1);
    quickSort(arr, p+1, high);
    }
}
int main(){
    int arr[10]={56, 2, 46, 20, 48, 1, 62, 98, 782, 10};
    printf("Before sorting\n");
    displayArr(arr, 10);
    printf("After sorting\n");
    quickSort(arr, 0, 9);
    displayArr(arr, 10);
    return 0;
}