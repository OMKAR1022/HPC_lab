# include <stdio.h>

int main(){
    int arr[] ={ 1,2,3,4,5,6,4,3,2,4,5};
    
    int length = sizeof(arr)/sizeof(arr[0]);
    int *pointer = arr;
    int sum =0;

    for(int i =0;i<length;i++){
       sum+= *(pointer+i);
       
    }
    printf("%d\n",sum);
}