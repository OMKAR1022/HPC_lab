#include <stdio.h>
int main(){
    int arr[] ={1,2,3,4,5,6,7};

    int length = sizeof(arr)/sizeof(arr[0]);

    int * pointer = arr;
    int rev[length];
    for(int i=length-1,j=0;i>=0;i--,j++){
         rev[j] = *(pointer+i);
    }
    
    for(int i =0;i<length;i++){
        printf("%d",rev[i]);
    }
    printf("\n");
}