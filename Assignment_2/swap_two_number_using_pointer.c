#include <stdio.h>

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b=temp;

}
int main(){
int a =20;
int b=40;
printf("Original Values : ,%d,%d\n",a,b);
swap(&a,&b);
printf("Swap value : %d,%d\n",a,b);
}

