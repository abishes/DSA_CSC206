//Bubble sort
#include<stdio.h>
void bubbleSort(int arr[], int size){
    for(int i=0; i< size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
}
void displayArr(int arr[], int size){
    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[10]={56, 2, 46, 20, 48, 1, 62, 98, 782, 10};
    printf("Before sorting\n");
    displayArr(arr, 10);
    printf("After sorting\n");
    bubbleSort(arr, 10);
    displayArr(arr, 10);
    return 0;
}