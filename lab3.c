//WAP to  to add two 3x3 matrices using pointers and transpose a matrix
#include<stdio.h>
#include<stdlib.h>
int main(){
    int *m1, *m2, r=3, c=3, i, j;
    m1=(int*)malloc(r*c*sizeof(int));
    m2=(int*)malloc(r*c*sizeof(int));
    printf("Enter 1st 3x3 matrix\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d",m1 + i*c + j);
        }
    }
    printf("Enter 2nd 3x3 matrix\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            scanf("%d",m2 + i*c + j);
        }
    }
    
    printf("sum of 2 matrices is\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ",*(m1 + i*c + j) + *(m2 + i*c + j));
        }
        printf("\n");
    }

    printf("transpose of 1st matrix is\n");
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            printf("%d ", *(m1 + i + j*c));
        }
        printf("\n");
    }
}