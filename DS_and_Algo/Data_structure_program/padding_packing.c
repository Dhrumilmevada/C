#include<stdio.h>

#pragma pack(1)
typedef struct /*_attribute_((_packed_))*/ Demo
{
	int a;
	int b;
	char x;
	float r;
}demo;


int main(){

	demo a;
	printf("size of Structure:%ld",sizeof(a));
}
