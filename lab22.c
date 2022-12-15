//implementation of merge sort
#include<stdio.h>
#include<stdlib.h>
void displayArr(int arr[], int size){
    for(int i=0; i< size; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void merge(int arr[], int l, int m, int r){
    int *Tarr= (int*)malloc((r+1)*sizeof(int));
    int i =l, j=m +1, k= l;
    while(i<=m && j<=r){
        if(arr[i]<arr[j]){
            *(Tarr+k) = arr[i];
            i++;
        }
        else{
            *(Tarr+k)=arr[j];
            j++;
        }
        k++;
    }
    while (i<=m){
        *(Tarr+k)= arr[i];
        i++;
        k++;
    }
    while(j<=r){
        *(Tarr+k)= arr[j];
        j++;
        k++;
    }
    for(i = l; i<=r; i++){
        arr[i]= *(Tarr+i);
    }
    free(Tarr);    
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
int main(){
    int arr[10]={56, 2, 46, 20, 48, 1, 62, 98, 782, 10};
    printf("Before sorting\n");
    displayArr(arr, 10);
    printf("After sorting\n");
    mergeSort(arr, 0, 9);
    displayArr(arr, 10);
    return 0;
}