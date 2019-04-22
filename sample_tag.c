#include<stdio.h>


int sum(int, int);
/*int sum(int, int, int);
int sum(int, int,int ,int);
int sum(int);*/
int mul(int, int);
int div(int, int);


int main()
{
	int x,y,a=2,b=1;
	int result; 
	printf("Enter two number:");
	scanf("%d \n %d",&x,&y);

	result = sum(x,y);

	printf("Result= %d",result);

	return 0;
}

int sum(int a, int b)
{
	return (a+b);
}

/*
int sum(int a, int b,int c)

	return (a+b+c);
}


int sum(int a, int b,int c,int d)
{
	return (a+b+c+d);
}


int sum(int a)
{
	return (a);
}

*/

int mul(int a, int b)
{
	return (a*b);
}

int div(int a,int b)
{
	return (a/b);
}
