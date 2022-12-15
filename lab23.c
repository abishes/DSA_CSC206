//implementation of linear search
#include<stdio.h>
int linearSearch(int arr[], int size, int key){
    for(int i =0; i< size; i++){
        if(arr[i] == key)
            return i;
    }
    return -1;
}
void print(int pos, int key){
    if(pos == -1){
        printf("%d key does not exist\n",key);
        return;
    }
    printf("%d key found in %d position\n",key, pos+1);
}
int main(){
    int arr[10]={56, 2, 46, 20, 48, 1, 62, 98, 782, 10};
    printf("Arrar: ");
    for( int i =0; i< 10; i++)
        printf("%d ",arr[i]);
    printf("\n");
    int key1 =1, key2= 600;
    print(linearSearch(arr, 10, key1), key1);
    print(linearSearch(arr, 10, key2), key2);
}