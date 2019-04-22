#include<stdio.h>

int main() 
{ 
    int  arr[] = {1, 2, 3, 4, 5, 6}; 
    int size = *(&arr + 1) - arr; 
    //pritnf("*d\n",*(&arr + 1))
    printf("Number of elements in arr[] is %d\n",size);
    return 0; 
} 
