//Lab 1:WAP to store and display information of employees using structure with structure.
#include<stdio.h>
#define N 5
struct emp{
	int empID;
	int salary;
	struct name{
		char fname[20];
		char lname[20];
	}nam;
};

int main(){
	struct emp e[N];
	printf("Enter the details of employees\n");
	printf("empID\tsalary\tFname\tLname\n");
	for(int i=0; i<N; i++){
		scanf("%d%d%s%s",&e[i].empID,&e[i].salary, e[i].nam.fname, e[i].nam.lname);
	}
	printf("Displaying info:\n");
	printf("empID\tsalary\tFname\tLname\n");
	for(int i=0; i<N; i++){
		printf("%d\t%d\t%s\t%s\n",e[i].empID,e[i].salary, e[i].nam.fname, e[i].nam.lname);
	}
	return 0;
}
