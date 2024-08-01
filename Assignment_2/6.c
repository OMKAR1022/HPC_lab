#include <stdio.h>
void big_el(int arr[],int length){

     int big_element = arr[0];

     for(int i =0; i<length;i++){
        if(arr[i>big_element]){
            big_element = arr[i];
        }
    }
    printf("%d\n",big_element);

}void small_el(int arr[],int length){

     int small_element = arr[0];

     for(int i =0; i<length;i++){
        if(arr[i]<small_element){
            small_element = arr[i];
        }
    }
    printf("%d",small_element);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7};
     int length = sizeof(arr)/sizeof(arr[0]);
     big_el(arr,length);
     small_el(arr,length);
     
}