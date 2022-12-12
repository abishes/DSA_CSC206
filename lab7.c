// WAP to implement Tower Of Hanoi problem
#include<stdio.h>
int totalSteps = 0;
void TOH(int n, char S, char D , char A){
    if (n==1){
        printf("Move disk 1 from %c to %c\n", S, D);
        totalSteps++;
    }
    if(n > 1){
        totalSteps++;
        TOH(n-1, S, A, D);
        printf("Move disk %d from %c to %c\n", n, S, D);
        TOH(n-1, A, D, S);
    }
}

int main(){
    int n;
    char S='S', D='D', A='A';
    printf("How many disks ");
    scanf("%d", &n);
    TOH(n, S, D, A);
    printf("Total steps %d", totalSteps);
}