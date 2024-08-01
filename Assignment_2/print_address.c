#include <stdio.h>

int main() {
    int number = 42;  
    int *pointer = &number;  

    printf("Value of number: %d\n", number);

    printf("Address of number: %p\n", (void*)pointer);

    return 0;
}
