//implementation of binary search
#include<stdio.h>
int binarySearch(int arr[], int l, int r, int key){
    if(l == r){
        if(key == arr[l])
            return l;
        return -1;
    }
    int m = (l+r)/2;
    if(key == arr[m])
        return m;
    else if(key < arr[m])
        return binarySearch(arr, l, m -1, key);
    else
        return binarySearch(arr, m+1, r, key);
}
void print(int pos, int key){
    if(pos == -1){
        printf("%d key does not exist\n",key);
        return;
    }
    printf("%d key found in %d position\n",key, pos+1);
}
int main(){
    int arr[10]={1, 2, 10, 20, 46, 48, 56, 62, 98, 782};
    printf("Arrar: ");
    for( int i =0; i< 10; i++)
        printf("%d ",arr[i]);
    printf("\n");
    int key1 =62, key2= 600;
    print(binarySearch(arr, 0, 9, key1), key1);
    print(binarySearch(arr, 0, 9, key2), key2);
}