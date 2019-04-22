#include <stdio.h>
#include <string.h>

void swap(char *a,char *b)
{
	char temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *str,int l,int r)
{
	static int cnt=0;
	if(l==r)
	{
		printf("%s-----%d\n",str,++cnt);	
	}
	else{
		int i;
		for(i=l;i<=r;i++)
		{
			swap((str+l),(str+i));
			permute(str,l+1,r);
			swap((str+l),(str+i));	
		}
	}
}
int main()
{
	char str[] = "AAA";
	permute(str,0,strlen(str)-1);
return 0;
}
