//Write a program to find transpose and add two 3x3 matrices
#include<stdio.h>
int main(){
    int m1[3][3], m2[3][3],i,j;
    printf("Enter 1st 3x3 matrix\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d", &m1[i][j]);
        }
    }
    printf("Enter 2nd 3x3 matrix\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d", &m2[i][j]);
        }
    }
    printf("Transpose of matrix 1 is\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ", m1[j][i]);
        }
        printf("\n");
    }
    printf("Sum of 2 matrices is\n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%d ", m1[i][j]+m2[i][j]);
        }
        printf("\n");
    }
}