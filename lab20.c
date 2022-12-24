//implementation of insertion sort
#include<stdio.h>
void displayArr(int arr[], int size){
    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertionSort(int arr[], int size){
    int temp, i, j;
    for(i =0; i < size; i++){
        temp =arr[i];
        for(j=i+1; j>= 0 && temp < arr[j]; j--){
            arr[j +1]= arr[j];
        }
        arr[j + 1]= temp;
    }
}
int main(){
    int arr[10]={56, 2, 46, 20, 48, 1, 62, 98, 782, 10};
    printf("Before sorting\n");
    displayArr(arr, 10);
    printf("After sorting\n");
    insertionSort(arr, 10);
    displayArr(arr, 10);
    return 0;
}
