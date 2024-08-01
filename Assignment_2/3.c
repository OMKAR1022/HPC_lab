#include <stdio.h>
int main(){
int arr[]= {1,2,3,4,5,5,6,7};

int length = sizeof(arr)/sizeof(arr[0]);

int *pointer = arr;

for(int i =0; i<length;i++){
  printf("element at index: %d ,%d\n",i,*(pointer+i));
}
return 0;
}