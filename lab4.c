//Write a program to sort an array of 10 numbers using pointers
#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(){
    int *arr, i, j;
    arr = (int*)malloc(N*sizeof(int));
    printf("Enter 10 elements randomly\n");
    for(i=0; i<N; i++){
        scanf("%d",arr + i);
    }
    printf("After sorted\n");
    for(i=0; i<N-1; i++){
        for(j=0; j<N-i-1; j++){
            if(*(arr + j) > *(arr + j + 1)){
                int temp = *(arr + j);
                *(arr + j)= *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
    for(i=0; i< N; i++){
        printf("%d ", *(arr + i));
    }
}