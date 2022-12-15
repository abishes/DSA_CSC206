//implementation of selection sort
#include<stdio.h>
void displayArr(int arr[], int size){
    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void selectionSort(int arr[], int size){
    int i, j, least, index;
    for( i = 0; i< size; i++){
        least = arr[i];
        index = i;
        for(j = i + 1; j < size; j++){
            if( least > arr[j]){
                least = arr[j];
                index = j;
            }
        }
        if( i != index){
            int temp = arr[i];
            arr[i]= arr[index];
            arr[index]= temp;
        }
    }
}
int main(){
    int arr[10]={56, 2, 46, 20, 48, 1, 62, 98, 782, 10};
    printf("Before sorting\n");
    displayArr(arr, 10);
    printf("After sorting\n");
    selectionSort(arr, 10);
    displayArr(arr, 10);
    return 0;
}